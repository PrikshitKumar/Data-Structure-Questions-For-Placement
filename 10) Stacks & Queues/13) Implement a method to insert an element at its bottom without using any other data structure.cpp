#include<bits/stdc++.h>
using namespace std;

/* Approach: 
    i) Define a recursion function that accepts the stack S and an integer as parameters and returns 
        a stack.
    ii) Base case to be considered is if the stack is empty. For this scenario, push N into the stack 
        and return it.
    iii) Otherwise, remove the top element of S and store it in a variable, say X.
    iv) Recurse again using the new stack
    v) Push X into S. */

stack<int> recur(stack<int> st, int num) {
	if(st.empty()) st.push(num);
	else {
		int x = st.top();
		st.pop();
		// Recurse with remaining elements
		st = recur(st, num);
		// Push the previous top element again
		st.push(x);
	}
	return st;
}

void insertToBottom(stack<int> st, int num) {
	st = recur(st, num);
	// Print the stack S
	while (!st.empty()) {
		cout<<st.top()<<" ";
		st.pop();
	}
}

int main() {
	stack<int> st;
	st.push(5);
	st.push(4);
	st.push(3);
	st.push(2);
	st.push(1);
    int num = 7;
    cout<<"Elements of the Stack are: "<<endl;
	insertToBottom(st, num);
	return 0;
}