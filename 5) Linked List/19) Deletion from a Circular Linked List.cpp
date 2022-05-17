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
    }
}

Node* deleteNode(Node* head, int data) {
    // Made Circular List
    // Node *t = head;
    // while(t->next != NULL) t = t->next;
    // t->next = head;

    // Deletion Operation
    if(head == NULL) return head;
    if(head->data == data) {
        Node* curr = head->next;
        // while(curr != head) curr = curr->next;
        // curr = head->next;
        delete head;
        head = curr;
    }
    else {
        Node *curr = head, *prev = head;
        // If Data is Present in Middle and at Last
        while(curr != NULL && curr->data != data) {
            prev = curr;
            curr = curr->next;
        }
        if(curr == NULL) cout<<"\nData not Found!"<<endl;
        else {
            prev->next = curr->next;
            delete curr;
        }
    }

    // Convert Circular to Singly List
    // t = head;
    // while(t->next != head) t = t->next;
    // t->next = NULL;

    return head;
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
    cout<<"\nPress 3 -> Delete the Node from List";
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
                start = deleteNode(start, 5);
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