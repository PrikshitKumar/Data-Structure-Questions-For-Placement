#include<bits/stdc++.h>
using namespace std;

bool ispar(string &str) {
    stack<char> st;
    for(int i=0; i<str.size(); i++) {
        if(str[i] == '{' || str[i] == '(' || str[i] == '[') {
            st.push(str[i]);
        }
        else if(st.empty()) return false;
        else if(str[i] == ')' && st.top() == '(') {
            st.pop();
        } 
        else if(str[i] == '}' && st.top() == '{') {
            st.pop();
        } 
        else if(str[i] == ']' && st.top() == '[') {
            st.pop();
        } 
        else return false;
    }
    return st.empty() ? true : false;
}

int main() {
    string exp = "{([])}";
    cout<<"Is the '"<<exp<<"' having balanced Paranthesis? "<<ispar(exp);
    return 0;
}