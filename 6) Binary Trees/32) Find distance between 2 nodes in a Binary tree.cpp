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

Node *findLCA(Node *root, int node1, int node2) {
    if(!root) return NULL;
    if(root->data == node1 || root->data == node2) return root;

    Node *left = findLCA(root->left, node1, node2);
    Node *right = findLCA(root->right, node1, node2);
    if(left && right) return root;
    if(left) return left;
    else return right;
}

int findDistance(Node *root, int target, int ans) {
    if(!root) return -1;
    if(root->data == target) return ans;
    int left = findDistance(root->left, target, ans+1);
    if(left != -1) return left;
    return findDistance(root->right, target, ans+1);
}

int findDist(Node* root, int a, int b) {
    Node *lca = findLCA(root, a, b);
    int distA = findDistance(lca, a, 0);
    int distB = findDistance(lca, b, 0);
    return distA+distB;
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

    cout<<"\nFind Distance between Two Nodes in a Binary Tree: "<<findDist(root, 8, 25);
    return 0;
}