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

void inOrder(Node *root, vector<int> &v) {
    if(root == NULL) return;
    
    inOrder(root->left, v);
    v.push_back(root->data);
    inOrder(root->right, v);
}
    
bool isIsomorphic(Node *root1, Node *root2) {
    vector<int> v1;
    vector<int> v2;
    inOrder(root1, v1);
    inOrder(root2, v2);
    
    if(v1 == v2) return true;
    
    reverse(v2.begin(), v2.end());
    
    if(v1 == v2) return true;
    return false;
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

    cout<<"\nCheck Whether Both the Trees are Isomorphic or not? "<<isIsomorphic(root, root);
    return 0;
}