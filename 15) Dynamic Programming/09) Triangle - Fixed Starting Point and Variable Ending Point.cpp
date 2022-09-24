#include<bits/stdc++.h>
using namespace std;

// Method 1:- Recusion
/* int solve(int i, int j, vector<vector<int>> &arr, int n) {
    if(i==n-1) return arr[i][j];
    int up = arr[i][j] + solve(i+1, j, arr, n);
    int diagonal = arr[i][j] + solve(i+1, j+1, arr, n);
    return min(up, diagonal);
}

int minimumPathSum(vector<vector<int>>& triangle, int n) {
    return solve(0, 0, triangle, n);
} */

// Method 2:- Recursion with Memoization
/* int solve(int i, int j, vector<vector<int>> &arr, int n, vector<vector<int>> &dp) {
    if(dp[i][j] != -1) return dp[i][j];
    if(i==n-1) return arr[i][j];
    int up = arr[i][j] + solve(i+1, j, arr, n, dp);
    int diagonal = arr[i][j] + solve(i+1, j+1, arr, n, dp);
    return dp[i][j] = min(up, diagonal);
}

int minimumPathSum(vector<vector<int>>& triangle, int n) {
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(0, 0, triangle, n, dp);
} */

// Method 3:- Tabulation 
/* int minimumPathSum(vector<vector<int>>& triangle, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i=0; i<n; i++) {
        dp[n-1][i] = triangle[n-1][i];
    }
    for(int i=n-2; i>=0; i--) {
        for(int j=i; j>=0; j--) {
            int down = triangle[i][j] + dp[i+1][j];
            int diagonal = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down, diagonal);
        }
    }
    return dp[0][0];
} */

// Mehtod 4:- Space Optimization
int minimumPathSum(vector<vector<int>>& triangle, int n) {
    vector<int> curr(n, 0), front(n, 0);
    for(int i=0; i<n; i++) {
        front[i] = triangle[n-1][i];
    }
    for(int i=n-2; i>=0; i--) {
        for(int j=i; j>=0; j--) {
            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j+1];
            curr[j] = min(down, diagonal);
        }
        front = curr;
    }
    return front[0];
}

int main() {
    vector<vector<int> > triangle{{1},
                                  {2,3},
                                  {3,6,7},
                                  {8,9,6,10}};
    int n = triangle.size();
    cout<<"Minimum Path Sum to reach Last Row is: "<<minimumPathSum(triangle, n);
    return 0;
}