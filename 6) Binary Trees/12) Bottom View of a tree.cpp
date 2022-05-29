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

vector <int> bottomView(Node *root) {
    vector<int> ans;
    if(root == NULL) return ans;
    
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    
    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int line = it.second;
        if(mp.find(line) == mp.end()) mp[line] = node->data;
        else mp[line] = node->data;
        
        if(node->left != NULL) q.push({node->left, line-1});
        if(node->right != NULL) q.push({node->right, line+1});
    }
    
    map<int, int>::iterator itr;
    for(itr = mp.begin(); itr != mp.end(); itr++) {
        ans.push_back(itr->second);
    }
    
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

    result = bottomView(root);
    cout<<"\nBottom View of the Tree is: "<<endl;
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";

    return 0;
}