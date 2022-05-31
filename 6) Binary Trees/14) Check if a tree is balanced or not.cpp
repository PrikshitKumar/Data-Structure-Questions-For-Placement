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

int findHeight(Node *root) {
    if(root == NULL) return 0;
    int lh = findHeight(root->left);
    int rh = findHeight(root->right);
    if(lh == -1 || rh == -1) return -1;
    if(abs(lh-rh) > 1) return -1;
    return max(lh, rh) + 1;
}

bool isBalanced(Node *root) {
    int result = findHeight(root);
    if(result == -1) return false;
    return true;
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

    cout<<"\nTree is Balanced or not? "<<isBalanced(root);
    return 0;
}