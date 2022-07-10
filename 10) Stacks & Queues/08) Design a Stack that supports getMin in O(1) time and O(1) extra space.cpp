#include<bits/stdc++.h>
using namespace std;

// stack<int> minElements;
int minVal = INT_MAX;
void push(stack<int>& s, int a) {
    if(s.empty()) {
        s.push(a);
        minVal = a;
    }
    else {
        int x = a;
        if(a < minVal) {
            x = 2*a - minVal;
            minVal = a;
        }
        s.push(x);
    }
    // Code for 2nd Method:-
    // if(a < minVal) {
    //     minElements.push(a);
    //     minVal = a;
    // }
}

bool isFull(stack<int>& s,int n){
	return (s.size() == n);
}

bool isEmpty(stack<int>& s){
    return s.empty();
}

int pop(stack<int>& s){
    int val = s.top();
    if(val >= minVal) s.pop();
    else {
        int y = 2*minVal - val;
        s.pop();
        minVal = y;
    }
    // Code for 2nd Method:-
    // s.pop();
    // if(minElements.top() == val) {
    //     minElements.pop();
    //     minVal = minElements.top();
    // }
    return val;
}

// Method 1: 
/* int getMin(stack<int>& s){
    stack<int>s2 = s;   // SC:- O(n) and TC:- O(n)
    int min = s2.top();
    while(!s2.empty()){
        if(s2.top() < min){
            min = s2.top();
        }
        s2.pop();
    }
    return min;
} */

// Method 2: 
/* int getMin(stack<int> &s) {
    return minElements.top();   // SC:- O(n) and TC:- O(1)
} */

/* Method 3: Whenever we find any minimum value than previous, store the encrypted form of that in 
    Stack and while deleting the elements, update the value of Minumum and if we find the encrypted 
    value from stack that means it is the Minmum Value after removing some top elements from Stack.
    Formula for Encryption: 2x - min OR x + (x - min), where min is the previous minimum element and 
    x is the current minimum value.
    Formula for Decrypting: 2x - (2x - min).
    For Example: Original Data -> [5, 8, 4, 6, 1, 7]
    Minimum Elements from left to right:- [5, 4, 1]
    Data in Stack -> [5, 8, *3, 6, *-2, 7]; * denotes the encrypted Values.
    if previous minimum Element is:- 5 and current minimum Element is 4. Then,
    Encrypted Value is: x + (x - min) => 4 + (4 - 5) => 4 - 1 => 3 (this value is to be store in Stack).
    Where, x = curr minimum value and (min) is the previous minimum value.
    Updated Data in Stack -> [5, 8, *3]; curr MIn:- 4 (After Deleting:- 6, 1, 7)
    Now, previous min = 4, and current min = 3 (At the time of Deletion (Right to Left)).
    Decrypted Value is: 2x - min => 2 * 4 - 3 => 8 - 3 => 5
    So, 5 is the minimum Value after deleting the first minimum (4) Value from Stack.
    */
int getMin(stack<int> &s) {
    return minVal;  // SC:- O(1) and TC:- O(1)
}

int main() {
    stack<int> st;
    push(st, 5);
    push(st, 1);
    push(st, 7);
    push(st, 10);
    push(st, 4);
    cout<<"Minimum Element is: "<<getMin(st);
    return 0;
}