#include<bits/stdc++.h>
using namespace std;

// Method 1:- Recursion
/* int solve(int i, int j) {
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    int up = solve(i-1, j);
    int left = solve(i, j-1);
    return up+left;
}

int uniquePaths(int m, int n) {
    return solve(m-1, n-1);
} */

// Method 2:- Recursion with Memoization
/* int solve(int i, int j, vector<vector<int>> &dp) {
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int up = solve(i-1, j, dp);
    int left = solve(i, j-1, dp);
    return dp[i][j] = up+left;
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(m-1, n-1, dp);
} */

// Method 3:- Tabulation Method
/* int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int> (n, 0));
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(i==0 && j==0) {
                dp[i][j] = 1;
                continue;
            }
            int down = 0, right = 0;
            if(i>0) {
                down = dp[i-1][j];
            }
            if(j>0) {
                right = dp[i][j-1];
            }
            dp[i][j] = down + right;
        }
    }
    return dp[m-1][n-1];
} */

// Method 4:- Space Optimization
int uniquePaths(int m, int n) {
    vector<int> prev(n, 0);
    for(int i=0; i<m; i++) {
        vector<int> temp(n, 0);
        for(int j=0; j<n; j++) {
            if(i==0 && j==0) {
                temp[j] = 1;
                continue;
            }
            int up = 0, left = 0;
            if(i>0) {
                up = prev[j];
            }
            if(j>0) {
                left = temp[j-1];
            }
            temp[j] = up + left;
        }
        prev = temp;
    }
    return prev[n-1];
}

int main() {
    
    return 0;
}