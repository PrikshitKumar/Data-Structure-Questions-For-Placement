#include<bits/stdc++.h>
using namespace std;

class Node {
    public: 
        int data;
        Node *next, *prev;

        Node(int val) {
            data = val;
            next = NULL;
            prev = NULL;
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

/* Approach: URL => https://youtu.be/VNf6VynfpdM
    Eg: If we have the list, looks like, 
    1 -> 2 -> 3 -> 4 -> NULL
    Random Ptr. of 1 points to 4
    Random Ptr. of 2 points to 1
    Random Ptr. of 3 points to NULL
    Random Ptr. of 4 points to 2

    Step 1:
    Create a Copy of nodes and assign the addresses in Next pointer only and locate them in b/w the nodes.
    Eg: 
    1 -> 1' -> 2 -> 2' -> 3 -> 3' -> 4 -> 4' -> NULL.
    Random Ptr. of 1, 2, 3, 4 are the same as the original List.
    And, Random Ptr. of 1', 2', 3', 4' are not pointing to any nodes as if now.

    Step 2: 
    Assign the addresses in Random Ptrs of New List.
    curr->next->rand = curr->rand->next
    means suppose curr node is 1;
    next of 1 pointing to 1' and rand ptr. of 1' is equal to the next of random of 1 (1 -> 4 -> 4');
    So, random ptr. of 1' now pointing to 4';
    Same goes for other nodes, until we can't reach the null in original node.

    Step 3: 
    Now, we will have to made the changes in the next ptr of new list for getting the exact copy of the 
    original list, and revert all the changes of Original List that we made for getting the copy List
    1', 2', 3', 4', NULL.

*/

// arb pointer is not defined in this program, make sure to run this in gfg Practise compiler.
Node *copyList(Node *head) {
    Node *curr = head, *front = head;
    /* First Step: make copy of each node, and link them together 
        side-by-side in a single list. */
    while(curr != NULL) {
        front = curr->next;
        Node *temp = new Node(curr->data);
        curr->next = temp;
        temp->next = front;
        curr = front;
    }
    
    // 2nd Step: assign random pointers for the copy nodes.
    curr = head;
    while (curr != NULL) {
        if (curr->arb != NULL) {
            curr->next->arb = curr->arb->next;
        }
        curr = curr->next->next;
    }

    // 3rd Step: restore the original list, and extract the copy list.
    curr = head;
    Node *pseudoHead = new Node(0);
    Node *copy = pseudoHead;
    
    while (curr != NULL) {
        front = curr->next->next;
        // extract the copy
        copy->next = curr->next;
        // restore the original list
        curr->next = front;
            
        copy = copy->next; 
        curr = front;
    }
    
    return pseudoHead->next;
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
    cout<<"\nPress 3 -> Clone the List";
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
                start = copyList(start);
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