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
void preorderTraversal(Node *root) {
    if(!root) return;
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Iterative method of Traversing through Binary Tree
void preorderTraversal(Node *root) {
    if(root == NULL) return;
    stack<Node *> st;
    st.push(root);
    while(!st.empty()) {
        root = st.top();
        st.pop();
        cout<<root->data<<" ";
        /* We stored the Right Sided Tree because when we pop the data from stack, we got the top node
            from the Left Sided Tree.  */
        if(root->right != NULL) st.push(root->right);
        if(root->left != NULL) st.push(root->left);
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
    preorderTraversal(root);
    return 0;
}
