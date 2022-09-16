#include<bits/stdc++.h>
using namespace std;

// Method 1:- Recursion
/* int solve(vector<int> &nums, int curr) {
    if(curr == 0) return nums[curr];
    if(curr < 0) return 0;
    int pick = nums[curr] + solve(nums, curr-2);
    int notPick = solve(nums, curr-1);
    
    return max(pick, notPick);
}

int maximumNonAdjacentSum(vector<int> &nums) {
    int ans = solve(nums, nums.size()-1);
    return ans;
} */

// Method 2:- Recursion with Memoization
/* int solve(vector<int> &nums, int curr, vector<int> &dp) {
    if(curr == 0) return nums[curr];
    if(curr < 0) return 0;
    
    if(dp[curr] != -1) return dp[curr];
    int pick = nums[curr] + solve(nums, curr-2, dp);
    int notPick = solve(nums, curr-1, dp);
    
    return dp[curr] = max(pick, notPick);
}

int maximumNonAdjacentSum(vector<int> &nums) {
    vector<int> dp(nums.size(), -1);
    int ans = solve(nums, nums.size()-1, dp);
    return ans;
} */

// Method 3:- Tabulation Approach
/* int maximumNonAdjacentSum(vector<int> &nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    for(int i=1; i<nums.size(); i++) {
        int pick = nums[i];
        if(i > 1) pick += dp[i-2];
        int notPick = dp[i-1];
        dp[i] = max(pick, notPick);
    }
    return dp[nums.size()-1];
} */

// Method 4:- Space Optimization
int maximumNonAdjacentSum(vector<int> &nums) {
    int prev1 = nums[0];
    int prev2 = 0;
    for(int i=1; i<nums.size(); i++) {
        int pick = nums[i];
        if(i > 1) pick += prev2;
        int notPick = prev1;

        int curr = max(pick, notPick);
        prev2 = prev1; 
        prev1 = curr;
    }
    return prev1;
}

int main() {
    vector<int> vec {2, 1, 4, 9};
    cout<<"Elements of the Array are: ";
    for(int i=0; i<vec.size(); i++) cout<<vec[i]<<" ";
    cout<<"\nMaximum Sum of Non-Adjacent Elements is: "<<maximumNonAdjacentSum(vec);
    return 0;
}