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

Node *buildBST(Node *root, int data) {
    if(root == NULL) {
        root = new Node(data);
    }
    if(data < root->data) {
        root->left = buildBST(root->left, data);
    }
    else if(data > root->data) {
        root->right = buildBST(root->right, data);
    }
    return root;
}

Node* post_order(int pre[], int size) {
    Node *root = NULL;
    for(int i=0; i<size; i++)
        root = buildBST(root, pre[i]);
    return root;
}

void postOrderTraversal(Node* root, vector<int> &result) {
    if(!root) return;
    postOrderTraversal(root->left, result);
    postOrderTraversal(root->right, result);
    result.push_back(root->data);    
}

int main() {
    int arr[] = {40, 30, 35, 80, 100};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    cout<<"\nElements of the Array are:\n";
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
 
    Node *root = post_order(arr, size);
    vector<int> result;
    postOrderTraversal(root, result);
    cout<<"\nValues after PostOrder Traversal are: "<<endl;
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";

    return 0;
}