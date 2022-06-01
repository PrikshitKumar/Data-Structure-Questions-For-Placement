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

int postOrder(Node *root, int &flag) {
    if(!root) return 0;
    // Leaf Nodes 
    if(!root->left && !root->right) return root->data;
    if(flag == 0) return 0;

    int left = postOrder(root->left, flag);
    int right = postOrder(root->right, flag);
    if(left+right != root->data) flag = 0;
    return left+right+root->data;
}

bool isSumTree(Node* root) {
    int flag = 1;
    postOrder(root, flag);
    return flag;
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

    cout<<"\nIs Binary Tree is a Sum Tree or not? "<<isSumTree(root)<<endl;
    return 0;
}