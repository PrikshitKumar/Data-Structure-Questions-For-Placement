#include<bits/stdc++.h>
using namespace std;

class MyStack {
    public: 
        int maxSize;
        int top;
        vector<int> stackArray;
        
        MyStack(int maxSize) {
            this->maxSize = maxSize;
            top = -1;
            stackArray.resize(maxSize, -1);
        }

        void push(int data) {
            stackArray[++top] = data;
        }
        int pop() {
            return stackArray[top--];
        }
        int peek() {
            return stackArray[top];
        }
        bool isEmpty() {
            return (top == -1);
        }
        bool isFull() {
            return (top == maxSize-1);
        }
};

int main() {
    int size = 5;
    MyStack stack(size);
    cout<<"Inserting Elements to the Stack: ";
    for(int i=0; i<size; i++) {
        stack.push(10*(i+1));
        cout<<stack.peek()<<" ";
    }
    cout<<"\nElements of the Stack are: ";
    while(!stack.isEmpty()) {
        int value = stack.pop();
        cout<<value<<" ";
    }
    return 0;
}