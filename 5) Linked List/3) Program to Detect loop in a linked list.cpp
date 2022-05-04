#include<bits/stdc++.h>
using namespace std;

/* 
    https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/

    Method 1: Hashing Approach: 
    Traverse the list one by one and keep putting the node addresses in a Hash Table. At any point, if 
    NULL is reached then return false, and if the next of the current nodes points to any of the 
    previously stored nodes in  Hash then return true.


    Method 2: This problem can be solved without hashmap by modifying the linked list data structure. 
    Approach: This solution requires modifications to the basic linked list data structure. 

    -> Have a visited flag with each node.
    -> Traverse the linked list and keep marking visited nodes.
    -> If you see a visited node again then there is a loop. This solution works in O(n) but requires 
        additional information with each node.
    -> A variation of this solution that doesn’t require modification to basic data structure can be 
        implemented using a hash, just store the addresses of visited nodes in a hash and if you see an 
        address that already exists in hash then there is a loop.


    Method 3: For cycle detection, we could use Floyd’s Cycle-Finding Algorithm 
    Approach: This is the fastest method and has been described below:  

    -> Traverse linked list using two pointers.
    -> Move one pointer(slow_p) by one and another pointer(fast_p) by two.
    -> If these pointers meet at the same node then there is a loop. If pointers do not meet then 
       linked list doesn’t have a loop.
*/

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

// Normal Method
/* 
bool detectLoop(Node *head) {
    unordered_set<Node*> s;
    while (head != NULL) {
        if (s.find(head) != s.end())
            return true;
            
        s.insert(head);
        head = head->next;
    }
    return false;
}
*/

// Floyd’s Cycle-Finding Algorithm
bool detectLoop(Node *head) {
    Node *slow_p = head, *fast_p = head;
 
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            return true;
        }
    }
    return false;
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
    cout<<"\nPress 3 -> Detect the cycle in the List";
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
                if(detectLoop(start)) {
                    cout<<"\nCycle Detected!";
                }
                else {
                    cout<<"\nCycle not Detected!";
                }
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