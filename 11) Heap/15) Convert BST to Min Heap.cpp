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

void printData(Node *head) {
    queue<Node *> q;
    q.push(head);
    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

void preOrder(Node *root, vector<int> &vec) {
    if(!root) return;
    preOrder(root->left, vec);
    vec.push_back(root->data);
    preOrder(root->right, vec);
}

void BSTToHeap(Node *head, vector<int> &vec, int &it) {
    if(!head) return;
    head->data = vec[it++];
    BSTToHeap(head->left, vec, it);
    BSTToHeap(head->right, vec, it);
}

void convertBSTToHeap(Node *head) {
    vector<int> vec;
    preOrder(head, vec);
    int it = 0;
    BSTToHeap(head, vec, it);
}

int main() {
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    cout<<"Binary Tree is: ";
    printData(root);
    convertBSTToHeap(root);
    
    cout<<"\nMin Heap from given BST is: ";
    printData(root);
    return 0;
}