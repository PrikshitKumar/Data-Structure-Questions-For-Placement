#include<bits/stdc++.h>
using namespace std;


// Method 1: Recurrsion with Memoization - Iterating through all possible ways
int calculateDistance(int i, int j, string &str1, string &str2, vector<vector<int>> &dp) {
    if(i < 0) return j+1;
    if(j < 0) return i+1;
    if(dp[i][j] != -1) return dp[i][j];
    if(str1[i] == str2[j]) return dp[i][j] = calculateDistance(i-1, j-1, str1, str2, dp);
    return dp[i][j] = 1 + min(calculateDistance(i-1, j, str1, str2, dp), 
                    min(calculateDistance(i, j-1, str1, str2, dp), 
                    calculateDistance(i-1, j-1, str1, str2, dp)));
} 

int editDistance(string str1, string str2) {
    int length1 = str1.length();
    int length2 = str2.length();
    vector<vector<int>> dp (length1, vector<int>(length2, -1));
    return calculateDistance(length1-1, length2-1, str1, str2, dp);
}

int main() {
    string str1 = "geek", str2 = "gesek";
    cout<<"No. of ways to convert '"<<str1<<"' to '"<<str2<<"' are: "<<editDistance(str1, str2);
    return 0;
}