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

Node* findMid(Node *head) {
    Node *slow = head, *fast = head->next;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* reverse(Node *head) {
    if(head == NULL || head->next == NULL) return head;
    Node* rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

bool compareLists(Node* list1, Node* list2) {
    while(list1 != NULL && list2 != NULL) {
        if(list1->data == list2->data) {
            list1 = list1->next;
            list2 = list2->next;
        }
        else return false;
    }
    return true;
}

bool isPalindrome(Node *head) {
    //Your code here
    Node* list1 = head;
    Node* mid = findMid(list1);
    Node* list2 = mid->next;
    mid->next = NULL;
    list2 = reverse(list2);
    return compareLists(list1, list2);
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
    cout<<"\nPress 3 -> Check whether the list is Palindrome or not?";
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
                bool result = isPalindrome(start);
                cout<<"\nList is Palindrome or not? "<<result;
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