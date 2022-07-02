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

Node *buildBST(Node *root, int data, Node* &succ) {
    if(root == NULL) {
        return root = new Node(data);
    }
    if(data < root->data) {
        succ = root;
        root->left = buildBST(root->left, data, succ);
    }
    else if(data > root->data) {
        root->right = buildBST(root->right, data, succ);
    }
    return root;
}

void replace(int arr[], int size) {
    Node *root = NULL;
    for(int i=size-1; i>=0; i--) {
        Node *succ = NULL;
        root = buildBST(root, arr[i], succ);
        if(succ != NULL) arr[i] = succ->data;
        else arr[i] = -1;
    }
}

int main() {
    int arr[] = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    cout<<"\nElements of the Array are: ";
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
    replace(arr, size);
    cout<<"\nResultant Array is: ";
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
    return 0;
}