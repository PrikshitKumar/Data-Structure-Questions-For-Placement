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

Node* detectLoop(Node* head) {
    Node *slowPtr = head, *fastPtr = head;
    while(slowPtr && fastPtr && fastPtr->next) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        
        if(slowPtr == fastPtr) {
            return slowPtr;
        }
    }
    return NULL;
}

Node* findStartingOfLoop(Node* head, Node* loopDetectedPtr) {
    if (head == loopDetectedPtr)
        while (loopDetectedPtr->next != head)
            loopDetectedPtr = loopDetectedPtr->next;
    else {
        while (head->next != loopDetectedPtr->next) {
            head = head->next;
            loopDetectedPtr = loopDetectedPtr->next;
        }
    }
    return loopDetectedPtr;
}

void findLoopStartngPooint(Node* head)
{
    // code here
    // just remove the loop without losing any nodes
    Node* loop = detectLoop(head);
    if(loop != NULL) {
        Node* lastNode = findStartingOfLoop(head, loop);
        return lastNode;
    }
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
    cout<<"\nPress 3 -> Find the starting point of Cycle from List";
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
                Node* lsp = findLoopStartngPooint(start);
                cout<<"\nLoop Starting Point is: "<<lsp->data;
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