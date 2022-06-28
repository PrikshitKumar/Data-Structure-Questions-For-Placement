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

Node *buildBST(vector<int> &preOrder, int &i, int bound) {
    if(i == preOrder.size() || preOrder[i] > bound) return NULL;
    Node *root = new Node(preOrder[i++]);
    root->left = buildBST(preOrder, i, root->data);
    root->right = buildBST(preOrder, i, bound);
    return root;
}

Node *bstFromPreOrder(vector<int> &preOrder) {
    int i = 0;
    return buildBST(preOrder, i, INT_MAX);
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
    vector<int> preOrder {10, 5, 1, 7, 40, 50};
    cout<<"PreOrder Traversal of the BST is: ";
    for(int i=0; i<preOrder.size(); i++) cout<<preOrder[i]<<" ";
    
    cout<<"\nConstructed BST from the given Traversal is: ";
    Node *root = bstFromPreOrder(preOrder);

    vector<int> result = levelOrder(root);
    cout<<"\nValues after Level-Order Traversal are: ";
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";

    return 0;
}