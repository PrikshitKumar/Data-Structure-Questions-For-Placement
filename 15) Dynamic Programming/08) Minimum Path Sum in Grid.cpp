#include<bits/stdc++.h>
using namespace std;

// Method 1:- Recursion
/* int solve(int i, int j, vector<vector<int>> &grid) {
    if(i==0 && j == 0) return grid[0][0];
    if(i<0 || j<0) return 1e9;

    int up = grid[i][j] + solve(i-1, j, grid);
    int left = grid[i][j] + solve(i, j-1, grid);

    return min(up,left);
}

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    return solve(n-1, m-1, grid);
} */

// Method 2:- Recursion with Memoization
/* int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
    if(i==0 && j == 0) return grid[0][0];
    if(i<0 || j<0) return 1e9;
    if(dp[i][j] != -1) return dp[i][j];
    
    int up = grid[i][j] + solve(i-1, j, grid, dp);
    int left = grid[i][j] + solve(i, j-1, grid, dp);

    return dp[i][j] = min(up,left);
}

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n-1, m-1, grid, dp);
} */

// Method 3:- Tabulation
/* int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i==0 && j==0) {
                dp[i][j] = grid[i][j];
                continue;
            } 
            int up = grid[i][j];
            if(i>0) up += dp[i-1][j];
            else up += 1e9;
            
            int left = grid[i][j];
            if(j>0) left += dp[i][j-1];
            else left += 1e9;
            
            dp[i][j] = min(up, left);
        }
    }
    return dp[n-1][m-1];
} */

// Method 4:- Space Optimization
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m, 0);    
    for(int i=0; i<n; i++) {
        vector<int> temp(m, 0);
        for(int j=0; j<m; j++) {
            if(i==0 && j==0) {
                temp[j] = grid[i][j];
                continue;
            } 
            int up = grid[i][j];
            if(i>0) up += prev[j];
            else up += 1e9;
            
            int left = grid[i][j];
            if(j>0) left += temp[j-1];
            else left += 1e9;
            
            temp[j] = min(up, left);
        }
        prev = temp;
    }
    return prev[m-1];
}

int main() {
    vector<vector<int> > matrix{{5,9,6}, {11,5,2}};
    cout<<"Minumum Path Sum in Grid is: "<<minSumPath(matrix);
    return 0;
}