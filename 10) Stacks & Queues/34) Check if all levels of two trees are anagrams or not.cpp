#include<bits/stdc++.h>
using namespace std;

class Node {
    public: 
        int data;
        Node *left, *right;
        Node(int data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

bool areAnagrams(Node *root1, Node *root2) {
    if(!root1 && !root2) return true;
    if(!root1 || !root2) return false;
    
    queue<Node *> q1, q2;
    q1.push(root1);
    q2.push(root2);
    
    unordered_map<int, int> m;
    while(!q1.empty() && !q2.empty()) {
        int n1 = q1.size(), n2 = q2.size();
        if(n1 != n2) return false;
        while (n1--) {
            Node* node1 = q1.front();
            q1.pop();
            m[node1->data]++;
    
            if(node1->left != NULL)
                q1.push(node1->left);
            if(node1->right != NULL)
                q1.push(node1->right);
        }

        while(n2--) {
            Node* node2 = q2.front();
            q2.pop();
            if(m.find(node2->data) == m.end()) return false;
            m[node2->data]--;
    
            if(m[node2->data] == 0) m.erase(node2->data);
    
            if (node2->left != NULL)
                q2.push(node2->left);
            if (node2->right != NULL)
                q2.push(node2->right);
        }
        if (m.size() > 0) return false;
    }
    if(q1.empty() && q2.empty()) return true;
    return false;
}

int main() {
    Node *root1, *root2;
    root1 = new Node(1);
    root1->left = new Node(3);
    root1->right = new Node(2);
    root1->right->left = new Node(5);
    root1->right->right = new Node(4);

    root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);

    cout<<"Tree 2 is a Anagram or not of Tree 1 ?  "<<areAnagrams(root1, root2);
    return 0;
}