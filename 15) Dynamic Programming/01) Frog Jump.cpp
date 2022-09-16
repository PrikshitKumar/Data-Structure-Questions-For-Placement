#include<bits/stdc++.h>
using namespace std;

// Method 1:- Recursion (Top - Down Approach)
/* int solve(vector<int> &heights, int curr) {
    if(curr == 0) return 0;
    int left = 0, right = INT_MAX;
    left = solve(heights, curr-1) + abs(heights[curr]-heights[curr-1]);
    if(curr > 1) right = solve(heights, curr-2) + abs(heights[curr]-heights[curr-2]);
    return min(left, right);
}

int frogJump(int n, vector<int> &heights) {
    int ans = solve(heights, n-1);
    return ans;
} */

// Method 2:- Recursion with Memoization (Top - Down Approach)
/* int solve(vector<int> &heights, int curr, vector<int> &dp) {
    if(curr == 0) return 0;
    if(dp[curr] != -1) return dp[curr];
    int left = 0, right = INT_MAX;
    left = solve(heights, curr-1, dp) + abs(heights[curr]-heights[curr-1]);
    if(curr > 1) right = solve(heights, curr-2, dp) + abs(heights[curr]-heights[curr-2]);
    return dp[curr] = min(left, right);
}

int frogJump(int n, vector<int> &heights) {
    vector<int> dp (n, -1);
    int ans = solve(heights, n-1, dp);
    return ans;
} */

// Method 3:- Tabulation (Bottom - Up Approach) 
/* int frogJump(int n, vector<int> &heights) {
    vector<int> dp(n, 0);
    for(int i=1; i<n; i++) {
        int left = dp[i-1] + abs(heights[i]-heights[i-1]);
        int right = INT_MAX;
        if(i>1) right = dp[i-2] + abs(heights[i]-heights[i-2]);
        dp[i] = min(left, right);
    }
    return dp[n-1];
} */

// Method 4:- Space Optimization Method
int frogJump(int n, vector<int> &heights) {
    int prev1 = 0, prev2 = 0;
    for(int i=1; i<n; i++) {
        int first = 0, second = INT_MAX;
        first = prev1 + abs(heights[i]-heights[i-1]);
        if(i>1) second = prev2 + abs(heights[i]-heights[i-2]);
        
        int curr = min(first, second);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    int len = 4;
    vector<int> vec {10, 20, 30, 10};
    cout<<"Elements of the Array are: ";
    for(int i=0; i<len; i++) cout<<vec[i]<<" ";
    cout<<"\nMinimum Total Enegy used by the Frog to reach end is: "<<frogJump(len, vec);
    return 0;
}