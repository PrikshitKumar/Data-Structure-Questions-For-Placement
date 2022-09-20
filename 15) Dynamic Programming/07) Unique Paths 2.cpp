#include<bits/stdc++.h>
using namespace std;

int mod = (int) (1e9+7);
// Method 1:- Recursion
/* int solve(int i, int j, vector<vector<int>> &mat) {
    if(i<0 || j<0 || mat[i][j] == -1) return 0;
    if(i==0 && j==0) return 1;
    int left = solve(i-1, j, mat);
    int up = solve(i, j-1, mat);
    return up+left;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    return solve(n-1, m-1, mat);
} */

// Method 2:- Recursion with Memoization
/* int solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp) {
    if(i<0 || j<0 || mat[i][j] == -1) return 0;
    if(i==0 && j==0) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    int left = solve(i-1, j, mat, dp);
    int up = solve(i, j-1, mat, dp);
    return dp[i][j] = up+left;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n-1, m-1, mat, dp);
} */

// Method 3:- Tabulation Method
/* int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = 1;
    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            int left = 0, up = 0;
            if(mat[i][j] != -1) {
                if(i>0) left = dp[i-1][j];
                if(j>0) up = dp[i][j-1];
            }
            dp[i][j] = (up+left) % mod;
        }
    }
    return dp[n-1][m-1];
} */

// Space Optimization
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<int> prev(m, 0);
    for(int i=0; i<n; i++) {
        vector<int> temp(m, 0);
        for(int j=0; j<m; j++) {
            if(mat[i][j] == -1) {
                temp[j] = 0;
                continue;
            }
            if(i==0 && j==0) {
                temp[j] = 1;
                continue;
            }
            int up = 0, left = 0;
            if(j>0) left = temp[j-1];
            if(i>0) up = prev[j];
            temp[j] = (up+left) % mod;
        }
        prev = temp;
    }
    return prev[m-1];
}

int main() {
    vector<vector<int> > maze{{0,0,0}, {0,-1,0}, {0,0,0}};   
    int n = maze.size();
    int m = maze[0].size();
    cout<<"Number of Unique Paths are: "<<mazeObstacles(n, m, maze);
    return 0;
}