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

void levelTraversal(Node *root, int level, vector<int> &ans) {
    if(root == NULL) return;
    if(level == ans.size()) ans.push_back(root->data);
    levelTraversal(root->left, level+1, ans);
    levelTraversal(root->right, level+1, ans);
}

//Function to return list containing elements of right view of binary tree.
vector<int> leftView(Node *root) {
    // Your Code here
    vector<int> ans;
    if(root == NULL) return ans;
    levelTraversal(root, 0, ans);
    return ans;
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

    result = leftView(root);
    cout<<"\nLeft View of the Tree is: "<<endl;
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";

    return 0;
}
