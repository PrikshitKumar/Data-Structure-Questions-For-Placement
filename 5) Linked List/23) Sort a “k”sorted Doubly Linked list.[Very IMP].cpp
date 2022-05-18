#include<bits/stdc++.h>
using namespace std;

class Node {
    public: 
        int data;
        Node *next, *prev;

        Node(int val) {
            data = val;
            next = prev = NULL;
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

// Comparator for comparing the data according to our choice
class compare {
    public:
    bool operator() (Node *n1, Node *n2) {
        return n1->data > n2->data;
    }
};

/* For sorting the List, we could directly use Merge Sort, Quick Sort, Insertion Sort, etc by 
    implementing the logic. And, TC for these algos are: O(n*logn), O(n^2), O(n^2) respectively.
    But, here the number selection distance 'k' is given. So, we would have to think about to optimize 
    the time complexity. 
    As k is given, we would only have to take care to took the curr element at it's right position in 
    that distance only, that actually reduces the time from O(n*logn) to O(n*logk); 
*/

Node* sortList(Node* head, int k) {
    if(head == NULL) return head;
    priority_queue<Node*, vector<Node*>, compare> queue;
    Node *temp = head;
    Node* newNode = NULL, *curr = NULL;
    int i=0;
    while(temp != NULL && i++ < k) {
        queue.push(temp);
        temp = temp->next;
    }
    while(!queue.empty()) {
        if(newNode == NULL) {
            newNode = queue.top();
            queue.top()->prev = curr;
            curr = queue.top();
        }
        else {
            curr->next = queue.top();
            queue.top()->prev = curr;
            curr = queue.top();
        }
        queue.pop();
        if(temp != NULL) {
            queue.push(temp);
            temp = temp->next;
        }
    }
    curr->next = NULL;
    return newNode;
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
    cout<<"\nPress 3 -> Sort the Doubly Linked List";
    cout<<"\nPress 9 -> Print the data";
    cout<<"\nPress 0 -> Exit!\n";
}
/* Input : 3 6 2 12 56 8 and k = 2
   Output: 2 3 6 8 12 56
*/
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
                start = sortList(start, 2);
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