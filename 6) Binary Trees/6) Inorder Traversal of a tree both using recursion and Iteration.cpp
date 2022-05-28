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

// Recursive method of Traversing through Binary Tree
void inorderTraversal(Node *root) {
    if(!root) return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

// Iterative method of Traversing through Binary Tree
void inorderTraversal(Node *root) {
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
            cout<<curr->data<<" ";
            curr = curr->right;
        }
    }
}

int main() {
    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);
 
    cout<<"Inorder Traversal of Tree is: ";
    inorderTraversal(root);
    return 0;
}
