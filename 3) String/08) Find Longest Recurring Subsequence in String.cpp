#include<bits/stdc++.h>
using namespace std;

int LongestRepeatingSubsequence(string str) {
    int length = str.length();
    int dp[length+1][length+1];
    for(int i=0; i<=length; i++) {
        for(int j=0; j<=length; j++) {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(str[i-1] == str[j-1] && i != j) 
                dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[length][length];
}


int main() {
    string str = "axxzxy";
    cout<<"Longest Subsequence of '"<<str<<"' is: "<<LongestRepeatingSubsequence(str);
    return 0;
}
