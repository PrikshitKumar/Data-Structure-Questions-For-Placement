#include<bits/stdc++.h>
using namespace std;

void insertAtRightPosition(int val, stack<int> &st) {
    if(st.size() == 0 || st.top() < val) {
        st.push(val);
    }
    else {
        int num = st.top();
        st.pop();
        insertAtRightPosition(val, st);
        st.push(num);
    }
}

void reverse(stack<int> &st) {
    if(st.size() > 0) {
        int num = st.top();
        st.pop();
        reverse(st);
        insertAtRightPosition(num, st);
    }
}

void sortTheStack(stack<int> &st) {
    reverse(st);
}

void print(stack<int> st) {
    if(st.empty()) cout<<"Stack is Empty.";
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main() {
    stack<int> st;
    st.push(52);
    st.push(1);
    st.push(7);
    st.push(65);
    st.push(30);
    cout<<"Elements of the Stack are:\n";
    print(st);
    cout<<"\nSorted Elements of the Stack are:\n";
    sortTheStack(st);
    print(st);
    return 0;
}