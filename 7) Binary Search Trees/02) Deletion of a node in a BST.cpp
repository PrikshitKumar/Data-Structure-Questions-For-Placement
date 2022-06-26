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

Node* findLastRight(Node* root) {
    if(root->right == NULL) return root;
    return findLastRight(root->right);
}

Node* helper(Node* root) {
    if(root->left == NULL) return root->right;
    else if (root->right == NULL) return root->left;

    Node* rightChild = root->right;
    Node* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;

    return root->left;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;
    if (root->data == key) return helper(root);

    Node *dummy = root;
    while(root != NULL) {
        if(root->data > key) {
            if(root->left != NULL && root->left->data == key) {
                root->left = helper(root->left);
                break;
            } 
            else root = root->left;
        } 
        else {
            if (root->right != NULL && root->right->data == key) {
                root->right = helper(root->right);
                break;
            } 
            else root = root->right;
        }
    }
    return dummy;
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

    int val;
    cout<<"\nEnter the Value that you want to Delete from BST: ";
    cin>>val;
    root = deleteNode(root, val);
    
    result = levelOrder(root);
    cout<<"Values after Deletion are: "<<endl;
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";

    return 0;
}