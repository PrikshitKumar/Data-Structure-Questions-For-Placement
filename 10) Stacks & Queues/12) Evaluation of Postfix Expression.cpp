#include<bits/stdc++.h>
using namespace std;

int calculate(int a, int b, char op) {
    if(op == '+') return a+b;
    else if(op == '-') return a-b;
    else if(op == '*') return a*b;
    else return a/b;
}

int evaluatePostfix(string S) {
    stack<int> st;
    for(int i=0; i<S.size(); i++) {
        if(S[i] >= '0' && S[i] <= '9') {
            st.push(S[i]-'0');
        }
        else {
            int val2 = st.top();
            st.pop();
            int val1 = st.top();
            st.pop();
            int result = calculate(val1, val2, S[i]);
            st.push(result);
        }
    }
    return st.top();
}

int main() {
    string exp = "231*+9-";
    cout<<"Expression Evaluation: "<<evaluatePostfix(exp);
    return 0;
}