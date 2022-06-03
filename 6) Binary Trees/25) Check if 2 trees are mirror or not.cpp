#include<bits/stdc++.h>
using namespace std;

int checkMirrorTree(int n, int e, int A[], int B[]) {
    unordered_map<int, stack<int>> mp;
    for(int i=0; i<2*e; i+=2) {
        mp[A[i]].push(A[i+1]);
    }
    for(int i=0; i<2*e; i+=2) {
        if(mp[B[i]].top() != B[i+1]) return 0;
        mp[B[i]].pop();
    }
    return 1;
}

int main() {
    int n = 3, e = 2;
    int A[] = {1, 2, 1, 3};
    int B[] = {1, 2, 1, 3};
    cout<<"Values of Tree 1: "<<endl;
    for(int i=0; i<2*e; i+=2) {
        cout<<"Value of Node with Root "<<A[i]<<": "<<A[i+1]<<endl;
    }
    cout<<"\nValues of Tree 2: "<<endl;
    for(int i=0; i<2*e; i+=2) {
        cout<<"Value of Node with Root "<<B[i]<<": "<<B[i+1]<<endl;
    }
    cout<<"\nCheck whether Both the tree are Mirror Trees or Not? "<<checkMirrorTree(n, e, A, B);
    return 0;
}