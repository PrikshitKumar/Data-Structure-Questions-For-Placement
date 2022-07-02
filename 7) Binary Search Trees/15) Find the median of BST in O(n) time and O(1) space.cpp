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

// Morris Traversal
int getLength(Node *root) {
    int size = 0;
    Node *curr = root;
    while(curr != NULL) {
        if(curr->left == NULL) {
            size++;
            curr = curr->right;
        }
        else {
            Node *prev = curr->left;
            while(prev->right != NULL && prev->right != curr) {
                prev = prev->right;
            }
            if(prev->right == NULL) {
                prev->right = curr;
                curr = curr->left;
            }
            else {
                prev->right = NULL;
                size++;
                curr = curr->right;
            }
        }
    }
    return size;
}

int median(Node *root, int size) {
    Node *curr = root, *prev = NULL;
    int count = 0;
    while(curr != NULL) {
        if(curr->left == NULL) {
            count++;
            // check if current node is the median Odd case
            if(size%2 != 0 && count == (size+1)/2)
                return curr->data;
 
            // Even case
            else if(count%2 == 0 && count == (size/2)+1)
                return (prev->data + curr->data)/2;
 
            // Update prev for even no. of nodes
            prev = curr;
            curr = curr->right;
        }
        else {
            Node *pre = curr->left;
            while(pre->right != NULL && pre->right != curr) {
                pre = pre->right;
            }
            if(pre->right == NULL) {
                pre->right = curr;
                curr = curr->left;
            }
            else {
                pre->right = NULL;
                prev = pre;
                // Count current node
                count++;
 
                // Check if the current node is the median
                if(size%2 != 0 && count == (size+1)/2)
                    return curr->data;
 
                else if(size%2 == 0 && count == (size/2)+1)
                    return (prev->data + curr->data)/2;
 
                // update prev node for the case of even no. of nodes
                prev = curr;
                curr = curr->right;
            }
        }
    }
    return curr->data;
}

// Used Morris Inorder Traversal (Time Complexity: Approx O(n) and Space Complexity: O(1)).
int findMedian(Node *root) {
    if(!root) return 0;
    int size = getLength(root);
    return median(root, size);
}

vector<int> inorderTraversal(Node *root) {
    stack<Node *> st;
    vector<int> ans;
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
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
 
    vector<int> result = inorderTraversal(root);
    cout<<"Values after Pre-Order Traversal are: "<<endl;
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";

    cout<<"\nMedian of the Given BST is: "<<findMedian(root);
    return 0;
}