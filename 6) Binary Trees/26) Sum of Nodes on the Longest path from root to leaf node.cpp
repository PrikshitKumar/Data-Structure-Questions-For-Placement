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

pair<int, int> findSum(Node *root) {
    if(!root) return {0, 0};
    auto a = findSum(root->left);
    auto b = findSum(root->right);
    if(a.first > b.first) return {a.first+1, a.second+root->data};
    if(a.first < b.first) return {b.first+1, b.second+root->data};
    else return {a.first+1, max(a.second, b.second)+root->data};
}

int sumOfLongRootToLeafPath(Node *root) {
    auto sum = findSum(root);
    return sum.second;
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

    cout<<"\nSum of Longest Path of Tree is: "<<sumOfLongRootToLeafPath(root);

    return 0;
}