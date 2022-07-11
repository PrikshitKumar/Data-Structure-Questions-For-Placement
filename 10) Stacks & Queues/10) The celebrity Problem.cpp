#include<bits/stdc++.h>
using namespace std;

bool knows(int a, int b, vector<vector<int>> &M) {
    if(M[a][b] == 1) return true;
    else return false;
}

int celebrity(vector<vector<int> >& M, int n) {
    stack<int> st;
    for(int i=0; i<n; i++) st.push(i);
    
    while(st.size() > 1) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        
        if(knows(a, b, M)) {
            st.push(b);
        }
        else st.push(a);
    }
    
    int candidate = st.top();
    bool rowCheck = false, colCheck = false;
    int zeroCount = 0, oneCount = 0;
    for(int i=0; i<n; i++) {
        if(M[candidate][i] == 0) zeroCount++;
    }
    if(zeroCount == n) rowCheck = true;
    
    for(int i=0; i<n; i++) {
        if(M[i][candidate] == 1) oneCount++;
    }
    if(oneCount == n-1) colCheck = true;
    
    if(rowCheck == true and colCheck == true) return candidate;
    else return -1;
}

int main() {
    vector<vector<int>> M {{0, 1, 0},
                           {0, 0, 0},
                           {0, 1, 0}};
    cout<<"Celebrity Number in the Party: "<<celebrity(M, 3);
    return 0;
}