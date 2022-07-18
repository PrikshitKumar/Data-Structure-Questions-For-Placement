#include<bits/stdc++.h>
using namespace std;

queue<int> rev(queue<int> q) {
    vector<int> vec;
    while(!q.empty()) {
        int data = q.front();
        vec.push_back(data);
        q.pop();
    }
    for(int i=vec.size()-1; i>=0; i--) q.push(vec[i]);
    return q;
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<"Reverse Elements of the Queue are:";
    queue<int> temp = q;
    while(!temp.empty()) {
        cout<<temp.front()<<" ";
        temp.pop();
    }
    temp = rev(q);
    cout<<"\nReverse Elements of the Queue are: ";
    while(!temp.empty()) {
        cout<<temp.front()<<" ";
        temp.pop();
    }
    return 0;
}