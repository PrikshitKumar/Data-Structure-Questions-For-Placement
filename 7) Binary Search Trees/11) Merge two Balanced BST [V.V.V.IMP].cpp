#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *left, *right;
        Node(int data) {
            this->data = data;
            left = right = NULL;
        }
};

/* There are two Approaches to solve this problem: 
    Approach 1: 
        Step 1: Store the Inorder Traversal of the BSTs in vectors 
        Step 2: Merge both of them in Sorted Order. 
        Step 3: Build the BST from this merged Array by using the Approach of "Construct a Balanced 
            BST" Question.
        The Time Complexity of this Approach is: O(n+m). 
        And, The Space Complexity is: O(n+m).
    
    Approach 2: 
        Step 1: Convert BST to Sorted Doubly Linked List by changing the pointers (without taking any 
            extra space).
        Step 2: Merge these 2 Sorted Linked Lists.
        Step 3: Convert Linked List to Balanced BST.
        The Time Complexity of this Approach is: O(n+m).
        And, the Space Complexity is: O(1). 
*/

// Approach 1:-
void inOrderTraversal(Node *root, vector<int> &data) {
    if(!root) return;
    if(root->left) inOrderTraversal(root->left, data);
    data.push_back(root->data);
    if(root->right) inOrderTraversal(root->right, data);
}

Node *constructBalancedBST(vector<int> &data, int start, int end) {
    if(start > end) return NULL;
    int mid = (start + end) >> 1;
    Node *root = new Node(data[mid]);
    root->left = constructBalancedBST(data, start, mid-1);
    root->right = constructBalancedBST(data, mid+1, end);
    return root;
}

Node *merge(Node *node1, Node *node2) {
    vector<int> dataBST1, dataBST2;
    inOrderTraversal(node1, dataBST1);
    inOrderTraversal(node2, dataBST2);
    
    // Merging both BSTs data
    for(int i=0; i<dataBST2.size(); i++) {
        dataBST1.push_back(dataBST2[i]);
    }
    sort(dataBST1.begin(), dataBST1.end());

    //Construct Balanced BST
    int start = 0, end = dataBST1.size()-1;
    Node *root = constructBalancedBST(dataBST1, start, end);
    return root;
}

// Approach 2:- Gives Segmentation Fault Error (Will Review the problem Later)
/* void convertIntoSortedDLL(Node *root, Node* &head) {
    if(!root) return;
    convertIntoSortedDLL(root->right, head);

    root->right = head;
    if(!head) head->left = root;
    head = root;

    convertIntoSortedDLL(root->left, head);
}

Node *merge(Node *node1, Node *node2) {
    Node *head = NULL, *curr = NULL;
    
    while(node1 != NULL && node2 != NULL) {
        if(node1->data < node2->data) {
            if(head == NULL) {
                head = curr = node1;
                node1 = node1->right;
            }
            else {
                curr->right = node1;
                node1->left = curr;
                curr = node1;
                node1 = node1->right;
            }
        }
        else {
            if(head == NULL) {
                head = curr = node2;
                node2 = node2->right;
            }
            else {
                curr->right = node2;
                node2->left = curr;
                curr = node2;
                node2 = node2->right;
            }
        }
    }

    while(node1 != NULL) {
        curr->right = node1;
        node1->left = curr;
        curr = node1;
        node1 = node1->right;
    }

    while(node2 != NULL) {
        curr->right = node2;
        node2->left = curr;
        curr = node2;
        node1 = node2->right;
    }

    return head;
}

int countNodes(Node *root) {
    int count = 0;
    Node *curr = root;
    while(curr != NULL) {
        count++;
        curr = curr->right;
    }
    return count;
}

Node *sortedDLLToBalancedBST(Node* &head, int length) {
    if(length <= 0 || head == NULL) return NULL;
    Node *left = sortedDLLToBalancedBST(head, length/2);

    Node *root = head;
    root->left = left;
    head = head->right;

    root->right = sortedDLLToBalancedBST(head, length-(length/2)-1);
    return root;
} */

vector<int> inOrder(Node* root) {
    vector<int> ans;
    if(!root) return ans;
    
    stack<Node *> st;
    Node *curr = root;
    while(true) {
        if(curr != NULL) {
            st.push(curr);
            curr = curr->left;
        } 
        else {
            if(st.empty()) break;
            curr = st.top();
            st.pop();
            ans.push_back(curr->data);
            curr = curr->right;
       }
    }

    return ans;
}

int main() {
    Node* root1 = new Node(8);
    root1->left = new Node(3);
    root1->right = new Node(10);
    root1->left->left = new Node(1);
    root1->left->right = new Node(6);
    root1->left->right->left = new Node(4);
    root1->left->right->right = new Node(7);
    root1->right->right = new Node(14);
    root1->right->right->left = new Node(13);
 
    vector<int> result = inOrder(root1);
    cout<<"InOrder Traversal of BST 1 is: "<<endl;
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";

    Node* root2 = new Node(50);
    root2->left = new Node(10);
    root2->right = new Node(60);
    root2->left->left = new Node(5);
 
    result = inOrder(root2);
    cout<<"\nInOrder Traversal of BST 2 is: "<<endl;
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";

    cout<<"\nMerging of Both the BSTs: ";
    Node *root = merge(root1, root2);
    // Node *list1 = NULL, *list2 = NULL;
    // convertIntoSortedDLL(root1, list1);
    // list1->left = NULL;
    // convertIntoSortedDLL(root2, list2);
    // list2->left = NULL;

    // Node *head = merge(list1, list2);
    // int length = countNodes(head);
    // Node *root = sortedDLLToBalancedBST(head, length);

    result = inOrder(root);
    cout<<"\nValues after InOrder Traversal are: "<<endl;
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";
    return 0;
}