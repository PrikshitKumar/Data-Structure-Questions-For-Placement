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

vector<int> reverseLevelOrder(Node *root) {
    // code here
    vector<int> ans;
    if(root == NULL) return ans;
    
    queue<Node *> q;
    q.push(root);
    
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++) {
            Node *curr = q.front();
            q.pop();
            ans.push_back(curr->data);
            if(curr->right!=NULL) {
                q.push(curr->right);
            }
            if(curr->left!=NULL) {
                q.push(curr->left);
            }
        }
    }
    reverse(ans.begin(),ans.end());
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
 
    vector<int> result = reverseLevelOrder(root);
    cout<<"Values after Level-Order Traversal are: "<<endl;
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";

    return 0;
}
