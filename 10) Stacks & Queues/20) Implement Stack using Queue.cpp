#include<bits/stdc++.h>
using namespace std;

class QueueStack {
    private:
        queue<int> q1;
        queue<int> q2;
    public: 
        void push(int);
        int pop();
};

void QueueStack :: push(int x) {
    q1.push(x);
}

int QueueStack :: pop() {
    if(q1.empty()) return -1;
    int res = q1.back();
    while(q1.size() != 1){
       q2.push(q1.front());
       q1.pop();
    }
    q1.pop();
    while(!q2.empty()) {
       q1.push(q2.front());
       q2.pop();
    }
    return res;
}

int main() {
    QueueStack *qs = new QueueStack();
    qs->push(1);
    qs->push(8);
    qs->push(5);
    qs->push(2);
    qs->push(9);
    cout<<"Implemented Stack using Two Queues and The element of the Stack are:\n";
    cout<<qs->pop()<<" ";
    cout<<qs->pop()<<" ";
    cout<<qs->pop()<<" ";
    cout<<qs->pop()<<" ";
    cout<<qs->pop()<<" ";
    cout<<qs->pop()<<" ";
    return 0;
}