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

vector<int> diagonalTraversal(Node *root) {
    vector<int> result;
    if(root == NULL) {
        return result;
    }

    queue<Node *> q;
    q.push(root);
    while(!q.empty()) {
        Node *node = q.front();
        q.pop();
        while(node != NULL) {
            result.push_back(node->data);
            if(node->left != NULL) q.push(node->left);
            node = node->right;
        }
    }
    return result;
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
    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);

    vector<int> result = levelOrder(root);
    cout<<"Values after Level-Order Traversal are: "<<endl;
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";

    result = diagonalTraversal(root);
    cout<<"\nDiagonal Traversal of Binary Tree is:\n";
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";
    return 0;
}