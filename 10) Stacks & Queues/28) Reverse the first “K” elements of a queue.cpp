#include<bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> s;
    for(int i=0; i<k; i++){
       s.push(q.front());
       q.pop();
    }
    while(!s.empty()){
       q.push(s.top());
       s.pop();
    }
    for(int i=0; i<q.size()-k; i++) {
        int data = q.front();
        q.pop();
        q.push(data);
    }
    return q;
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<"Elements of the Queue are: ";
    queue<int> temp = q;
    while(!temp.empty()) {
        cout<<temp.front()<<" ";
        temp.pop();
    }
    cout<<"\nElements of the Queue after modification are: ";
    temp = modifyQueue(q, 3);
    while(!temp.empty()) {
        cout<<temp.front()<<" ";
        temp.pop();
    }
    return 0;
}