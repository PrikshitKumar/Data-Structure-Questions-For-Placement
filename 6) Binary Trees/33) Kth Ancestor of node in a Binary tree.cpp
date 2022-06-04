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

Node *solve(Node *root, int &k, int target) {
    if(!root) return NULL;
    if(root->data == target) return root;

    Node *left = solve(root->left, k, target);
    Node *right = solve(root->right, k, target);

    if(!left && !right) return NULL;
    else if(left) {
        k--;
        if(k <= 0) {
            k = INT_MAX;
            return root;
        }
        return left;
    }
    else {
        k--;
        if(k <= 0) {
            k = INT_MAX;
            return root;
        }
        return right;
    }
}

int findAncestor(Node* root, int k, int node) {
    Node *ans = solve(root, k, node);
    if(!ans || ans->data == node) return -1;
    else return ans->data;
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

    cout<<"\nFind 'Kth' Ancestor of given Node in a Binary Tree: "<<findAncestor(root, 2, 12);
    return 0;
}