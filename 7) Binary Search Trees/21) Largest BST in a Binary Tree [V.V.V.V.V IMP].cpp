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

class NodeValue {
    public: 
        int minNode, maxNode, maxSize;
        NodeValue(int minNode, int maxNode, int maxSize) {
            this->minNode = minNode;
            this->maxNode = maxNode;
            this->maxSize = maxSize;
        }
};

NodeValue *largestBSTSubtree(Node *root) {
    // An empty tree is a BST of size 0.
    if(!root) return new NodeValue(INT_MAX, INT_MIN, 0);

    // Get values from left and right subtree of current tree.
    NodeValue *left = largestBSTSubtree(root->left);
    NodeValue *right = largestBSTSubtree(root->right);

    // Current node is greater than max in left AND smaller than min in right, it is a BST.
    if(left->maxNode < root->data && root->data < right->minNode) {
        // It is a BST.
        return new NodeValue(min(root->data, left->minNode), max(root->data, right->maxNode), 
                                left->maxSize + right->maxSize + 1);
    }
    else {
        // Otherwise, return [-inf, inf] so that parent can't be valid BST
        return new NodeValue(INT_MIN, INT_MAX, max(left->maxSize, right->maxSize));
    }
}

int largestBST(Node *root) {
    return largestBSTSubtree(root)->maxSize;
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

    cout<<"\nThe Size of Largest BST in the Binary Tree is: "<<largestBST(root);
    return 0;
}