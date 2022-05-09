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
/* There are 3 to 4 approaches to solve this problem:
    i) By running two loops and check whether the intersection point exists in lists or not.
        TC = O(n+m)^2, SC = O(1)
    ii) By using the Hashmap. Store the addresses of nodes of list1 in hashmap and run a loop for
        2nd list and check whether any address of list2 node present in Hashmap or not.
        TC = O(n+m), SC = O(n)
    iii) Iterate through List1 till the End and find the length. Similarlly, find the length for 
        list2. Then, calculate the difference of lengths and iterate difference number of time in 
        largest list and made that node as the Head Node. Now, start both the list and compare the 
        address of Nodes, whether the Intersection Node is present in the List or not.
        TC = O(m)+O(n)+O(m) = O(2m), SC = O(1)
    iv) Iterate through the 1st and 2nd List until we didn't find the intersection Point. But we will
        have to take care of some points: 
        a) When both lists pointers equals to NULL, that means Intersection Point is not found.
        b) If Pointer of any list reached last position and point to NULL, assign the head address of 
            another List and start the traversing again simultaneously.
        By this approach, we don't need to calculate the lengths of the Lists, that thing is taken care
        by the insertion of address of another lists.
        TC: O(m)+O(n)+O(m) = O(2m), SC = O(1)
        
        Method 4 is precise than other methods.
*/
// Method 3: 
/* int intersectPoint(Node* head1, Node* head2) {
    Node *temp1 = head1, *temp2 = head2;
    int length1 = 0, length2 = 0;
    while(temp1 != NULL) {
        temp1 = temp1->next;
        length1++;
    }
    while(temp2 != NULL) {
        temp2 = temp2->next;
        length2++;
    }
    int diff = abs(length1 - length2);
    if(length1 < length2) {
        Node *temp = head1;
        head1 = head2;
        head2 = temp;
    }
    temp1 = head1, temp2 = head2;
    while(diff--) {
        temp1 = temp1->next;
    }
    while(temp1 && temp2) {
        if(temp1 == temp2) return temp1->data;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return -1;
} */

// Method 4: 
int intersectPoint(Node* head1, Node* head2) {
    Node *temp1 = head1, *temp2 = head2;
    while(temp1 != temp2) {
        temp1 = temp1->next;
        temp2 = temp2->next;
        if(temp1==NULL && temp2==NULL) return -1;
        if(temp1 == NULL) temp1 = head2;
        if(temp2 == NULL) temp2 = head1;
    }
    return temp1->data;
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