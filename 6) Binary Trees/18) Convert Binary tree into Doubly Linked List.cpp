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

void treeToListConversion(Node *root, Node* &head, Node* &prev) {
    if(!root) return;
    treeToListConversion(root->left, head, prev);
    if(head == NULL) {
        head = prev = root;
    }
    else {
        prev->right = root;
        root->left = prev;
        prev = prev->right;
    }
    treeToListConversion(root->right, head, prev);
}

Node *bToDLL(Node *root) {
    Node *head = NULL, *prev = NULL;
    treeToListConversion(root, head, prev);
    return head;
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

    Node *ll = bToDLL(root);
    cout<<"\nDoubly Linked List of Binary Tree is:\n";
    while(ll != NULL) {
        cout<<ll->data<<" ";
        ll = ll->right;
    }
    return 0;
}