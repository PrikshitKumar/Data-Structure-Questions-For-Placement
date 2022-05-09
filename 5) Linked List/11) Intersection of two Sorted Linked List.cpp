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

Node* findIntersection(Node* head1, Node* head2) {
    Node* head = NULL, *curr = NULL, *temp = NULL;
    while(head1 != NULL && head2 != NULL) {
        if(head1->data == head2->data) {
            temp = new Node(head1->data);
            if(head == NULL) head = temp;
            else curr->next = temp;
            curr = temp;
            head1 = head1->next;
            head2 = head2->next;
        } 
        else if(head1->data < head2->data) head1 = head1->next;
        else head2 = head2->next;
    }
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
    cout<<"\nPress 3 -> Find Intersection of 2 Linked Lists";
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
                start = findIntersection(start);
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