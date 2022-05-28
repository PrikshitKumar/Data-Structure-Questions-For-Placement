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

// Level Order Traversal
void levelOrder(Node* node) {
    if(node==NULL) return;
    
    queue<Node *> q;
    q.push(node);
    
    while(!q.empty()) {
        Node *front = q.front();
        cout<<front->data<<" ";
        q.pop();
        
        if(front->left != NULL) {
            q.push(front->left);
        }
        if(front->right != NULL) {
            q.push(front->right);
        }
    }
}

// Recursive method of Traversing through Binary Tree
void postorderTraversal(Node *root) {
    if(!root) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}

// Iterative method of Traversing through Binary Tree
// By using 2 Stacks 
void postorderTraversal(Node *root) {
    if(root == NULL) return;
    stack<Node *> st1, st2;
    st1.push(root);
    while(!st1.empty()) {
        Node *curr = st1.top();
        st1.pop();
        st2.push(curr);
        if(curr->left != NULL) st1.push(curr->left);
        if(curr->right != NULL) st1.push(curr->right);
    }
    while(!st2.empty()) {
        cout<<st2.top()->data<<" ";
        st2.pop();
    }
}

// By using only 1 Stack
void postorderTraversal(Node *root) {
    if(root == NULL) return;
    stack<Node *> st;
    Node *curr = root;
    while(curr != NULL || !st.empty()) {
        if(curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        else {
            Node *temp = st.top()->right;
            if(temp == NULL) {
                temp = st.top();
                st.pop();
                cout<<temp->data<<" ";
                while(!st.empty() && temp == st.top()->right) {
                    temp = st.top();
                    st.pop();
                    cout<<temp->data<<" ";
                }
            }
            else {
                curr = temp;
            }
        }
    }
}

int main() {
    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);
 
    cout<<"LevelOrder Traversal of Tree is: ";
    levelOrder(root);
    cout<<"\nPostOrder Traversal of Tree is: ";
    postorderTraversal(root);
    return 0;
}
