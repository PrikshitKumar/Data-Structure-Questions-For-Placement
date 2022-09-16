#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
int dp[N][108];

// Method 1:- Recursion
/* int solve(int curr, vector<int> &heights, int k) {
    if(curr == 0) return 0;
    int minSteps = INT_MAX;
    for(int j=1; j<=k; j++) {
        if(curr-j >= 0) {
            int jumpEnergy = solve(curr-j, heights, k) + abs(heights[curr]-heights[curr-j]);
            minSteps = min(minSteps, jumpEnergy);
        }
    }
    return minSteps;
} */
 
// Method 2:- Recursion with memoization
/* int solve(int curr, vector<int> &heights, vector<int> &dp, int k) {
    if(curr == 0) return 0;
    if(dp[curr] != -1) return dp[curr];
    
    int mmSteps = INT_MAX;
    for(int j=1; j<=k; j++) {
        if(curr-j >= 0) {
            int jump = solve(curr-j, heights, dp, k) + abs(heights[curr]- heights[curr-j]);
            mmSteps = min(jump, mmSteps);
        }
    }
    return dp[curr] = mmSteps;
} */

// Method 3:- Tabulation Approach
int solve(int n, vector<int> &height, vector<int> &dp, int k) {
    dp[0] = 0;
    for(int i=1; i<n; i++) {
        int mmSteps = INT_MAX;
        for(int j=1; j<=k; j++) {
            if(i-j >= 0) {
                int jump = dp[i-j] + abs(height[i]- height[i-j]);
                mmSteps = min(jump, mmSteps);
            }
        }
        dp[i]= mmSteps;
    }
    return dp[n-1];
}

int frogJump(int n, vector<int> &heights, int k) {
    vector<int> dp(n,-1);
    return solve(n, heights, dp, k);
}

int main() {
    vector<int> heights{30, 10, 60, 10, 60, 50};
    int len = heights.size(), k = 2;
    cout<<"Elements of the Array are: ";
    for(int i=0; i<len; i++) cout<<heights[i]<<" ";
    cout<<"\nMinimum Total Enegy used by the Frog to reach end is: "<<frogJump(len, heights, k);
    return 0;
}