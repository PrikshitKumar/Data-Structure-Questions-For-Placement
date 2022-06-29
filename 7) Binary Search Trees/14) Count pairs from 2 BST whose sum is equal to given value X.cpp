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

void inOrderTraversal(Node *root, unordered_map<int, int> &mp) {
    if(!root) return;
    inOrderTraversal(root->left, mp);
    mp[root->data]++;
    inOrderTraversal(root->right, mp);
}

void count(Node *root, unordered_map<int, int> &mp, int &ans, int &x) {
    if(!root) return;
    int data = x - root->data;
    if(mp[data]) ans++;
    count(root->left, mp, ans, x);
    count(root->right, mp, ans, x);
}

int countPairs(Node* root1, Node* root2, int x) {
    unordered_map<int, int> mp;
    int ans = 0;
    inOrderTraversal(root1, mp);
    count(root2, mp, ans, x);
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
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
 

    Node* root2 = new Node(50);
    root2->left = new Node(10);
    root2->right = new Node(60);
    root2->left->left = new Node(5);

    vector<int> result = levelOrder(root);
    cout<<"Values after Level-Order Traversal 1st BST are: "<<endl;
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";

    result = levelOrder(root);
    cout<<"\nValues after Level-Order Traversal of 2nd BST are: "<<endl;
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";

    cout<<"\nThe Number of Pairs whose sum = 20 are: "<<countPairs(root, root2, 20);
    return 0;
}