#include<bits/stdc++.h>
using namespace std;

bool chkExpression(string &exp) {
    stack<char> st;
    for(int i=0; i<exp.size(); i++) {
        char ch = exp[i];
        if(ch == '(' || ch == '+' || ch =='-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        else {
            if(ch == ')') {
                bool isRedundant = true;
                while(st.top() != '(') {
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/') {
                        isRedundant = false;
                    }
                    st.pop();   // For removing the operators (+, -, *, /)
                }
                if(isRedundant) return true;
                st.pop();   // For removing the Opening Bracket '('
            }
        }
    }
    return false;
}

int main() {
    string exp = "(a+(b*c))";
    cout<<"Given Expression is: "<<exp<<endl;
    cout<<"'"<<exp<<"' contains Redundant Brackets or not? "<<chkExpression(exp);
    return 0;
}