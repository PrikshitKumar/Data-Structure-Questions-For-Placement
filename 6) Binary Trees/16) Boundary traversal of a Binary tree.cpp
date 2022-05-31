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

bool isLeaf(Node *root) {
    return !root->left && !root->right;
}

void addLeftBoundary(Node *root, vector<int> &res) {
    Node *cur = root->left;
    while(cur) {
        if(!isLeaf(cur)) res.push_back(cur->data);
        if(cur->left) cur = cur->left;
        else cur = cur->right;
    }
}

void addRightBoundary(Node *root, vector<int> &res) {
    Node *cur = root->right;
    vector<int> tmp;
    while(cur) {
        if(!isLeaf(cur)) tmp.push_back(cur->data);
        if(cur->right) cur = cur->right;
        else cur = cur->left;
    }
    for(int i=tmp.size()-1; i>=0; --i) {
        res.push_back(tmp[i]);
    }
}

void addLeaves(Node *root, vector<int> &res) {
    if(isLeaf(root)) {
        res.push_back(root->data);
        return;
    }
    if(root->left) addLeaves(root->left, res);
    if(root->right) addLeaves(root->right, res);
}

vector<int> boundary(Node *root) {
    vector<int> res;
    if(!root) return res;

    if(!isLeaf(root)) res.push_back(root->data);

    addLeftBoundary(root, res);

    // add leaf nodes
    addLeaves(root, res);

    addRightBoundary(root, res);
    return res;
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

    result = boundaryTraversal(root);
    cout<<"\nDiagonal Traversal of Binary Tree is:\n";
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";
    return 0;
}