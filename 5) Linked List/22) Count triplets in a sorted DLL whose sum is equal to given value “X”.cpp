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

Node* getLastNode(Ndde* head) {
    Node* prev = head;
    while(prev->next != NULL) prev = prev->nextl
    return prev;
}

// We have used the Singly Linked List, So, we would have to convert this into Doubly linked list first
void findTriplets(Node* head, int sum) {
    Node *st = head;
    Node *lt = getLastNode(head);
    bool found = false;
    while(st != NULL) {
        Node *start = st->next;
        Node *last = lt;
        while(start != last && last->next != start) {
            int data = st->data + start->data + last->data;
            if(data == sum) {
                found = true;
                cout<<st->data<<" "<<start->data<<" "<<last->data<<endl;
                start = start->next;
                last = last->prev;
            }
            else if(data < sum) start = start->next;
            else last = last->prev;
        }
    }
    if(!found) cout<<"\nDidn't found any pair with Sum = "<<sum;
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
    cout<<"\nPress 3 -> Count Triplets in the List whose Sum equals to the inputed Number";
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
                findTriplets(start, 7);
                // printElements(start);
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