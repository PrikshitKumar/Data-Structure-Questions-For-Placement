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

void inorderTraversal(Node *root) {
    if(!root) return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

Node *BinaryTreeFormation(String str) {
    Node *root;


    return root;
}

int main() {
    string s = "4(2(3)(1))(6(5))";
    Node *root = BinaryTreeFormation(s);
    cout<<"Inorder Traversal of Tree is: ";
    inorderTraversal(root);
    return 0;
}
