#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int start, int end) {
    while(start <= end) {
        if(str[start++] != str[end--]) {
            return false;
        }
    }
    return true;
}


void solve(string str, vector<string> &ds, vector<vector<string>> &res, int curr) {
        if(curr == str.size()) {
            res.push_back(ds);
            return;
        }
    
        for(int i=curr; i<str.size(); ++i) {
            if(isPalindrome(str, curr, i)) {
                ds.push_back(str.substr(curr, i-curr+1));
                solve(str, ds, res, i+1);
                ds.pop_back();
            }
        }
    }   

vector<vector<string>> partition(string str) {
    vector<vector<string>> res;
    vector<string> ds;
    solve(str, ds, res, 0);
    return res;
}

int main() {

    string str = "aabb";
    vector<vector<string>> ans = partition(str);
    int n = ans.size();
    cout<<"The Palindromic partitions are :-" << endl;
    cout<<"[ ";
    for(auto i: ans) {
        cout << "[ ";
        for(auto j: i) {
            cout << j << " ";
        }
        cout << "] ";
    }
    cout << "]";

    return 0;
}