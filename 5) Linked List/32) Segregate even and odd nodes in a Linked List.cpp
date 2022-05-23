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

Node* divide(int N, Node *head) {
    Node *evenTemp = NULL, *oddTemp = NULL;
    Node *even = NULL, *odd = NULL;
    
    while(head != NULL) {
        if(head->data % 2 == 0) {
            if(even == NULL) {
                even = head;
                evenTemp = head;
            }
            else {
                evenTemp->next = head;
                evenTemp = evenTemp->next;
            }
        }
        else {
            if(odd == NULL) {
                odd = head;
                oddTemp = head;
            }
            else {
                oddTemp->next = head;
                oddTemp = oddTemp->next;
            }
        }
        head = head->next;
    }
    if(evenTemp != NULL) evenTemp->next = odd;
    if(oddTemp != NULL) oddTemp->next = NULL;
    if(even != NULL) return even;
    return odd;
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
    cout<<"\nPress 3 -> Segregate the evem and odd Nodes of the List";
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
                start = divide(start);
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