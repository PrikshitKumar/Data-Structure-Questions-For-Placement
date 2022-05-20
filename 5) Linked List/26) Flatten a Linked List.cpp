#include<bits/stdc++.h>
using namespace std;

class Node {
    public: 
        int data;
        Node *next;

        Node(int val) {
            data = val;
            next = NULL;
        }
};

Node *start = NULL;

Node * createNode() {
    int val;
    cout<<"Enter the Value: ";
    cin>>val;
    Node *n = new Node(val);
    return n;
}

void insertNode() {
    Node *n = createNode();
    if(start == NULL) {
        start = n;
    }
    else {
        Node *temp = start;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
    }
}

Node* merge(Node* a, Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;
 
    Node* result;
    if (a->data < b->data) {
        result = a;
        result->bottom = merge(a->bottom, b);
    }
    else {
        result = b;
        result->bottom = merge(a, b->bottom);
    }
    
    result->next = NULL;
    return result;
}

// Pointers are not defined here, but working completely fine in GFG Compiler
Node *flatten(Node *root) {
    if (root == NULL || root->next == NULL) return root;
    root->next = flatten(root->next);
    root = merge(root, root->next);
    return root;
}

void printElements(Node* head) {
    if(head == NULL) {
        cout<<"List is Empty!";
    }
    else {
        Node *temp = head;
        cout<<"Data of the List is: ";
        while(temp != NULL) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
}

void menu() {
    cout<<"\n\nPress 1 -> Inserting the data";
    cout<<"\nPress 3 -> Flatten the List";
    cout<<"\nPress 9 -> Print the data";
    cout<<"\nPress 0 -> Exit!\n";
}

int main() {
    while(1) {
        menu();
        int ch;
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch (ch) {
            case 1: {
                insertNode();
                break;
            }
            case 3: {
                start = flatten(start);
                printElements(start);
                break;
            }
            case 9: {
                printElements(start);
                break;
            }
            case 0: {
                cout<<"Program Terminatted Successfully!!"<<endl;
                return 0;
            }
            default: {
                cout<<"Invalid Choice!";
                break;
            }
        }
    }
    return 0;
}