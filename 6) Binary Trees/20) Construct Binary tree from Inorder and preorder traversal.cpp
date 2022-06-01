#include <bits/stdc++.h>
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

Node *constructTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, 
        int inStart, int inEnd, map<int,int> &mp) {

    if(preStart > preEnd || inStart > inEnd) return NULL;

    Node *root = new Node(preorder[preStart]);
    int inRootIndex = mp[root->data];     // index of value in Inorder Array
    int numsLeft = inRootIndex-inStart;   // remaining elements in Left Side of Inorder Array

    root->left = constructTree(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRootIndex-1, mp);
    root->right = constructTree(preorder, preStart+numsLeft+1, preEnd, inorder, inRootIndex+1, inEnd, mp);

    return root;
}

Node *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int preStart = 0, preEnd = preorder.size()-1;
    int inStart = 0, inEnd = inorder.size()-1;

    map<int,int> mp;
    for(int i=inStart; i<=inEnd; i++) {
        mp[inorder[i]] = i;
    }

    return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
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

void postOrderTraversal(Node *root) {
    if(!root) return;
    if(root->left) postOrderTraversal(root->left);
    if(root->right) postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

int main() {
    vector<int> preorder{10,20,40,50,30,60};
    vector<int> inorder{40,20,50,10,60,30};
    Node *root = buildTree(preorder, inorder);

    vector<int> result = levelOrder(root);
    cout<<"Values after Level-Order Traversal are: "<<endl;
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";

    cout<<"\nValues after Post-Order Traversal are: "<<endl;
    postOrderTraversal(root);

    return 0;
}