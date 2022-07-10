#include<bits/stdc++.h>
using namespace std;

void reverse(string &str, int len) {
    stack<char> st;
    for(int i=0; i<len; i++) {
        st.push(str[i]);
    }
    int i=0;
    while(!st.empty()) {
        str[i++] = st.top();
        st.pop();
    }
}

int main() {
    string str = "Prikshit";
    cout<<"Reverse of '"<<str<<"' is: ";
    reverse(str, str.size());
    cout<<str;
    return 0;
}