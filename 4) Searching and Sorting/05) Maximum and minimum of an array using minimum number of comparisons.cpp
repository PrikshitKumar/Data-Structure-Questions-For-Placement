#include<bits/stdc++.h>
using namespace std;

int middle(int A, int B, int C){
    //code here//Position this line where user code will be pasted.
    set<int> temp;
    temp.insert(A);
    temp.insert(B);
    temp.insert(C);
    set<int>::iterator it = temp.begin();
    return *(++it);
}

int main() {
    int a = 978, b = 518, c = 300;
    cout<<"Middle Element is: "<<middle(a, b, c);
    return 0;
}
