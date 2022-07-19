#include<bits/stdc++.h>
using namespace std;

/*  Method 1 => By using the Queue.
    Step 1:- Insert first n/2 elements to newQueue. Now, we have last n/2 elements in Original Queue. 
    Step 2:- Pop the front Element from newQueue and push that in Orginal Queue. And, pop the front 
        element from Orginal Queue and again push this in Original Queue.
        Perform Step 2, till we didn't get the Resultant Queue.
    Eg: 
        originalQueue = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        Step 1:- newQueue = {11, 12, 13, 14, 15}; and originalQueue = {16, 17, 18, 19, 20};
        Step 2:- original Queue = {11, 16, 12, 17, 13, 18, 14, 19, 15, 20};
    Time Complexity:- O(n);
    Space Complext:- O(n);
    
    Mehtod 2 => By using the Stack.
    Step 1:- Insert 1st n/2 Elements to Stack.
    Step 2:- Push all the elements of Stack in Original Queue.
    Step 3:- Pop() n/2 elements from Queue and Push those elements again in Original Queue simultaneously.
    Step 4:- Push n/2 elements of Original Queue to Stack.
    Step 5:- Pop() single element from Stack and push that in Original Queue. Now, pop the element from 
        Queue and Push that again in same Queue, i.e., Original Queue.
        Repeat Step 5, untill stack won't get empty.
    Eg: 
        Original Queue = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        Step 1:- Stack -> {11, 12, 13, 14, 15}; Queue -> {16, 17, 18, 19, 20};
        Step 2:- Stack -> { }; Queue -> {16, 17, 18, 19, 20, 15, 14, 13, 12, 11};
        Step 3:- Stack -> { }; Queue -> {15, 14, 13, 12, 11, 16, 17, 18, 19, 20};
        Step 4:- Stack -> {15, 14, 13, 12, 11}; Queue -> {16, 17, 18, 19, 20};
        Step 5:- Stack -> { }; Queue -> {11, 16, 12, 17, 13, 18, 14, 19, 15, 20};
    Time Complexity:- O(n);
    Space Complexity:- O(n);
*/

queue<int> modifyQueue(queue<int> q) {
    stack<int> st;
    int length = q.size() >> 1;
    // Step 1
    for(int i=0; i<length; i++) {
        st.push(q.front());
        q.pop();
    }
    // Step 2
    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }
    // Step 3
    for(int i=0; i<length; i++) {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    // Step 4
    for(int i=0; i<length; i++) {
        st.push(q.front());
        q.pop();
    }
    // Step 5
    while(!st.empty()) {
        q.push(st.top());
        st.pop();
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}

int main() {
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    cout<<"Elements of the Queue are: ";
    queue<int> temp = q;
    while(!temp.empty()) {
        cout<<temp.front()<<" ";
        temp.pop();
    }
    cout<<"\nElements of the Queue after modification are: ";
    temp = modifyQueue(q);
    while(!temp.empty()) {
        cout<<temp.front()<<" ";
        temp.pop();
    }
    return 0;
}