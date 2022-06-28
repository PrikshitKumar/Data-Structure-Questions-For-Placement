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

void inOrderTraversal(Node *root, vector<int> &data) {
    if(!root) return;
    inOrderTraversal(root->left, data);
    data.push_back(root->data);
    inOrderTraversal(root->right, data);
}

void btToBST(Node *root, int &it, vector<int> &data) {
    if(!root) return;
    btToBST(root->left, it, data);
    root->data = data[it++];
    btToBST(root->right, it, data);
}

Node *binaryTreeToBST (Node *root) {
    vector<int> data;
    inOrderTraversal(root, data);
    sort(data.begin(), data.end());
    int it = 0;
    btToBST(root, it, data);
    return root;
}

vector<int> levelOrder(Node* node) {
    vector<int> ans;
    if(node==NULL) return ans;
    
    queue<Node *> q;
    q.push(node);
    
    while(!q.empty()) {
        Node *front = q.front();
        ans.push_back(front->data);
        q.pop();
        
        if(front->left != NULL) {
            q.push(front->left);
        }
        if(front->right != NULL) {
            q.push(front->right);
        }
    }
    return ans;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    
    vector<int> result = levelOrder(root);
    cout<<"Values after Level-Order Traversal are: "<<endl;
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";

    cout<<"\nConversion of Binary tree to BST: ";

    root = binaryTreeToBST(root);
    result = levelOrder(root);
    cout<<"\nValues after Level-Order Traversal are: "<<endl;
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";
    
    return 0;
}