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

vector<int> path;
void printPath(Node *root, int k) {
    if(!root) return;
    path.push_back(root->data);
    printPath(root->left, k);
    printPath(root->right, k);

    int sum = 0;
    for(int i=path.size()-1; i>=0; i--) {
        sum += path[i];
        if(sum == k) {
            for(int j=i; j<path.size(); j++) {
                cout<<path[j]<<" ";
            }
            cout<<endl;
        }
    }
    path.pop_back();
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

    cout<<"\nPrint all the Paths having Sum = 20 : "<<endl;
    printPath(root, 20);
    return 0;
}