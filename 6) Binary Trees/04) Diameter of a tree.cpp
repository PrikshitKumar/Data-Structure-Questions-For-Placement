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

int diameter(Node* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}
int height(Node *root, int &diameter) {
    if(root == NULL) return 0;
    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);
    diameter = max(diameter, lh+rh+1);
    return 1 + max(lh, rh);
}

int main() {
    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);
 
    cout<<"Diameter of the Tree is: "<<diameter(root);
    return 0;
}
