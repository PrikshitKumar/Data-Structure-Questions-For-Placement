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

//Function to sort the given linked list using Merge Sort.
struct node* getTail(struct node* head) {
    while(head->next != NULL) head = head->next;
    return head;
}

struct node* partition(struct node* head, struct node* tail) {
    struct node* pivot = head;
    struct node* curr = head->next, *prev = head;
    
    while(curr != tail->next) {
        if(pivot->data > curr->data) {
            swap(prev->next->data, curr->data);
            prev = prev->next;
        }
        curr = curr->next;
    }
    
    swap(prev->data, pivot->data);
    return prev;
}

void solveSort(struct node* head, struct node* tail) {
    if(head == NULL || tail == NULL || head == tail) return;
    
    struct node* pivot = partition(head, tail);
    solveSort(head, pivot);
    solveSort(pivot->next, tail);
}

//you have to complete this function
void quickSort(struct node **headRef) {
    struct node* head = *headRef;
    if(head == NULL || head->next == NULL) return;
        
    struct node *tail = getTail(head);
    solveSort(head, tail);
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
    cout<<"\nPress 3 -> Sort the Linked Lists";
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
                start = quickSort(start);
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