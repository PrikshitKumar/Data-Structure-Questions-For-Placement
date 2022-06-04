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

unordered_map<Node *, int> dp;

int maxSum(Node *root) {
    if(!root) return 0;
    if(dp[root]) return dp[root];

    int including = root->data;
    if(root->left) {
        including += maxSum(root->left->left);
        including += maxSum(root->left->right);
    }
    if(root->right) {
        including += maxSum(root->right->left);
        including += maxSum(root->right->right);
    }

    int excluding = maxSum(root->left) + maxSum(root->right);
    dp[root] = max(including, excluding); 

    return dp[root];
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

    cout<<"\nMaximum Sum of Nodes such that not two nodes are adjacent is: "<<maxSum(root);
    return 0;
}