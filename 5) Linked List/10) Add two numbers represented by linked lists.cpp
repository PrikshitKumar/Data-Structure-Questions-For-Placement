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

Node* reverse(struct Node* head) {
    if(head == NULL || head->next == NULL) return head;
    
    struct Node* rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return rest;
}

Node* addTwoLists(Node* first, Node* second) {
    first = reverse(first);
    second = reverse(second);
    
    int carry = 0;
    Node* head = NULL;
    Node* curr = NULL, *temp = NULL;
    while(first != NULL || second != NULL) {
        carry = carry + (first ? first->data : 0) + (second ? second->data : 0);
        temp = new Node(carry%10);
        carry /= 10;
        if(head == NULL) head = temp;
        else curr->next = temp;
        curr = temp;
        if(first) first = first->next;
        if(second) second = second->next;
    }
    if(carry > 0) {
        temp = new Node(carry);
        curr->next = temp;
        curr = temp;
    }
    head = reverse(head);
    return head;
}

void printElements() {
    if(start == NULL) {
        cout<<"List is Empty!";
    }
    else {
        Node *temp = start;
        cout<<"Data of the List is: ";
        while(temp != NULL) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
}

void menu() {
    cout<<"\n\nPress 1 -> Inserting the data";
    cout<<"\nPress 3 -> Add 2 Linked Lists";
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
                start = addLinkedLists(start);
                printElements();
                break;
            }
            case 9: {
                printElements();
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