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

vector<int> zigzagLevelOrder(Node *root) {
    vector<int> result;
    if(root == NULL) {
        return result;
    }

    queue<Node *> q;
    q.push(root);
    bool leftToRight = true;

    while(!q.empty()) {
        int size = q.size();
        vector<int> row(size);
        for(int i=0; i<size; i++) {
            Node *node = q.front();
            q.pop();

            // find position to fill node's value
            int index = (leftToRight) ? i : (size-1-i);

            row[index] = node->val;
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
        }
        // after this level
        leftToRight = !leftToRight;
        for(int i=0;  i<row.size(); i++) result.push_back(row[i]);
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

    result = zigZagTraversal(root);
    cout<<"Zig Zag Traversal of Binary Tree is:\n";
    for(i=0; i<result.size(); i++) cout<<ans[i][j]<<" ";
    return 0;
}