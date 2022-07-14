#include<bits/stdc++.h>
using namespace std;

int findMaxLen(string s) {
    stack<int> st;
    int n = s.size();
    int ans = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '(') st.push(i);
        else {
            if(!st.empty() && s[st.top()] == '(') {
                st.pop();
                int x;
                if(!st.empty()) x = st.top();
                else x = -1; 
                    
                ans = max(ans,i-x);
            }
            else st.push(i);
        }
    }
    return ans;
}

int main() {
    string str = "()(())(";
    cout<<"Length of Valid Substring is: "<<findMaxLen(str);
    return 0;
}