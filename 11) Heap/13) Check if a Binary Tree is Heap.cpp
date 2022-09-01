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

 bool isHeap(struct Node* root) {
    if(!root) return 1;
    queue<Node *> q;
    q.push(root);
    
    bool nullNode = false;
    
    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();
        
        if(temp->left != NULL) {
            if(temp->left->data > temp->data) return false;
            q.push(temp->left);
        }
        else nullNode = true;
        
        if(nullNode && temp->right != NULL) return false;
        if(temp->right != NULL) {
            if(temp->right->data > temp->data) return false;
            q.push(temp->right);
        }
        else nullNode = true;
    }
    
    return true;
}

int main() {
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);

    cout<<"Is the given Binary Tree is a Heap? "<<isHeap(root);
    return 0;
}