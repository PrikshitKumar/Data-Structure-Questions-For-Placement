#include<bits/stdc++.h>
using namespace std;

class StackQueue {
    private:
        stack<int> s1;
        stack<int> s2;
    public:
        void push(int);
        int pop();
};

void StackQueue :: push(int x) {
    s1.push(x);
}

int StackQueue :: pop() {
    int data = -1;
    if(s1.empty()) return data;
    while(s1.size() > 1) {
        s2.push(s1.top());
        s1.pop();
    }
    data = s1.top();
    s1.pop();
    while(!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
    }
    return data;
}

int main() {
    StackQueue *sq = new StackQueue();
    sq->push(5);
    sq->push(7);
    sq->push(1);
    sq->push(3);
    sq->push(8);
    cout<<"Elements of the Queue using Stack are:\n";
    for(int i=0; i<5; i++) {
        cout<<sq->pop()<<" ";
    }
    return 0;
}