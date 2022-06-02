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

void height(Node *root, stack<int> &st, int dep) {
    if(!root) return;
    if(!root->left && !root->right) {
        st.push(dep);
        return;
    }
    height(root->left, st, dep+1);
    height(root->right, st, dep+1);
}

bool check(Node *root) {
    if(!root) return true;
    stack<int> st;
    height(root, st, 0);
    int dep = st.top();
    st.pop();
    while(!st.empty()) {
        if(st.top() != dep) return false;
        st.pop();
    }
    return true;
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

    cout<<"\nCheck whether all the Leaf Nodes are at the Same Level or not? "<<check(root);
    return 0;
}