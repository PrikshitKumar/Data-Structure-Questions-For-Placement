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

void findPreSuc(Node* root, int key) {
    if(root == NULL) return;
    Node *temp = root;
    Node *pre, *suc;
    pre = suc = NULL;
    
    while(temp != NULL) {
        if(temp->data <= key) temp = temp->right;
        else {
            suc = temp;
            temp = temp->left;
        }
    }
    
    temp = root;
    while(temp != NULL) {
        if(temp->data >= key) temp = temp->left;
        else {
            pre = temp;
            temp = temp->right;
        }
    }
    cout<<"\nSuccessor of the "<<key<<" in BST is: "<< ((suc!=NULL) ? suc->data : -1);
    cout<<"\nPredecessor of the "<<key<<" in BST is: "<< ((pre!=NULL) ? pre->data : -1);
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
 
    vector<int> result = levelOrder(root);
    cout<<"Values after Level-Order Traversal are: "<<endl;
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";

    findPreSuc(root, 1);
    return 0;
}