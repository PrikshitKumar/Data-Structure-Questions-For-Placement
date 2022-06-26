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

/* There is one more Ptr. called "next", that we didn't create. 
    So, better to run this solution in GFG Practise itself. */
void inOrderSuccessor(Node *root, Node* &prev) {
    if(!root) return;
    inOrderSuccessor(root->left, prev);
    
    if(prev != NULL) prev->next = root;
    prev = root;
    
    inOrderSuccessor(root->right, prev);
}

void populateNext(Node *root) {
    Node *prev = NULL;
    inOrderSuccessor(root, prev);
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

    cout<<"\nInOrder Successors of all the Nodes are: ";
    populateNext(root);
    return 0;
}