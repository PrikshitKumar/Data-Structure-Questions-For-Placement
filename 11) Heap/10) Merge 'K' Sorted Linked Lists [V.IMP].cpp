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
        // n->prev = temp;
    }
}

Node* merge(Node* l1, Node* l2) {
    // Make Sure always the head of L1 has the smallest Value than the head of L2, if not, swap the nodes.
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    if(l1->data > l2->data) {
        Node *temp = l1;
        l1 = l2;
        l2 = temp;
    }
    Node *result = l1;
    while(l1 && l2) {
        Node *temp = NULL;
        while(l1 != NULL && l1->data <= l2->data) {
            temp = l1;
            l1 = l1->next;
        }
        temp->next = l2;
        
        // Swap the lists
        Node *t = l1;
        l1 = l2;
        l2 = t;
    }
    return result;
}

//Function to merge K sorted linked list.
Node * mergeKLists(Node *arr[], int K) {
    // Your code here
    for(int i=K-2; i>=0; i--) {
        arr[i] = merge(arr[i], arr[i+1]);
    }
    return arr[0];
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
    cout<<"\nPress 3 -> Merge the Lists";
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
                Node *arr[] = {start, start->next};
                start = mergeKLists(arr, 2);
                cout<<"\nData after merging Lists: ";
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