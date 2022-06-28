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

Node *constructBalancedBST(vector<int> &data, int start, int end) {
    if(start > end) return NULL;
    int mid = (start + end) >> 1;
    Node *root = new Node(data[mid]);
    root->left = constructBalancedBST(data, start, mid-1);
    root->right = constructBalancedBST(data, mid+1, end);
    return root;
}

Node *bstToBalancedBST(Node *root) {
    vector<int> data;
    inOrderTraversal(root, data);
    int start = 0, end = data.size()-1;
    root = constructBalancedBST(data, start, end);
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
    Node* root = new Node(4);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    
    vector<int> result = levelOrder(root);
    cout<<"Values after Level-Order Traversal are: "<<endl;
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";

    cout<<"\nConversion of Normal BST to Balanced BST is: ";

    root = bstToBalancedBST(root);
    result = levelOrder(root);
    cout<<"\nValues after Level-Order Traversal are: "<<endl;
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";
    
    return 0;
}