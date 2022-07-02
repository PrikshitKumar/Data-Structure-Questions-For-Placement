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

bool chkDeadEnd(Node *root, int min, int max) {
    if(!root) return false;
    if(min == max) return true;
    return chkDeadEnd(root->left, min, root->data-1) || chkDeadEnd(root->right, root->data+1, max);
}

bool deadEnd(Node *root) {
    return chkDeadEnd(root, 1, INT_MAX);
}

vector<int> inOrder(Node* root) {
    vector<int> ans;
    if(!root) return ans;
    
    stack<Node *> st;
    Node *curr = root;
    while(true) {
        if(curr != NULL) {
            st.push(curr);
            curr = curr->left;
        } 
        else {
            if(st.empty()) break;
            curr = st.top();
            st.pop();
            ans.push_back(curr->data);
            curr = curr->right;
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
 
    vector<int> result = inOrder(root);
    cout<<"Values after InOrder Traversal are: "<<endl;
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";

    cout<<"\nIs there any Dead End present in BST: "<<deadEnd(root);
    return 0;
}