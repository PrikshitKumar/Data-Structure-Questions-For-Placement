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

void inOrder(Node *curr, Node* &prev) {
    if(!curr) return;
    inOrder(curr->left, prev);

    prev->left = NULL;
    prev->right = curr;
    prev = curr;

    inOrder(curr->right, prev);
}

// Function to flatten binary tree using level order traversal
Node *flatten(Node *root) {
    Node *dummy = new Node(-1);
    Node *prev = dummy;
    
    inOrder(root, prev);
    prev->left = NULL;
    prev->right = NULL;

    Node *result = dummy->right;
    delete dummy;
    return result;
}

void print(Node* root) {
    Node* curr = root;
    while(curr != NULL) {
        cout<<curr->data<<" "; 
        curr = curr->right;
    }
}

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
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
 
    vector<int> result = inOrder(root);
    cout<<"Values after InOrder Traversal are: "<<endl;
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";

    cout<<"\nBST to Sorted List:\n";
    Node *ans = flatten(root);
    print(ans);
    return 0;
}