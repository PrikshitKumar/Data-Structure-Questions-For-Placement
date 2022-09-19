#include<bits/stdc++.h>
using namespace std;

// Method 1:- Recursion
/* int solve(int currDay, int lastJob, vector<vector<int>> &points) {
    if(currDay == 0) {
        int maxi = INT_MIN;
        for(int i=0; i<=2; i++) {
            if(lastJob != i && maxi < points[0][i]) {
                maxi = points[0][i];
            }
        }
        return maxi;
    }
    int maxi = INT_MIN;
    for(int i=0; i<=2; i++) {
        if(i != lastJob) {
            int activity = points[currDay][i] + solve(currDay-1, i, points);
            maxi = max(maxi, activity);
        }
    }
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    int ans = solve(n-1, 3, points);
    return ans;
} */

// Method 2:- Recursion with Memoization
/* int solve(int currDay, int lastJob, vector<vector<int>> &points, vector<vector<int>> &dp) {
    if(currDay == 0) {
        int maxi = INT_MIN;
        for(int i=0; i<=2; i++) {
            if(lastJob != i && maxi < points[0][i]) {
                maxi = points[0][i];
            }
        }
        return maxi;
    }
    if(dp[currDay][lastJob] != -1) return dp[currDay][lastJob];
    int maxi = INT_MIN;
    for(int i=0; i<=2; i++) {
        if(i != lastJob) {
            int activity = points[currDay][i] + solve(currDay-1, i, points, dp);
            maxi = max(maxi, activity);
        }
    }
    return dp[currDay][lastJob] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp(n, vector<int>(4, -1));
    int ans = solve(n-1, 3, points, dp);
    return ans;
} */

// Method 3:- Tabulation
/* int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    
    for(int currDay=1; currDay<n; currDay++) {
        for(int lastTask=0; lastTask<4; lastTask++) {
            dp[currDay][lastTask] = 0;
            for(int task=0; task<=2; task++) {
                if(task != lastTask) {
                    int activity = points[currDay][task]+dp[currDay-1][task];
                    dp[currDay][lastTask] = max(activity, dp[currDay][lastTask]);
                }
            }
        }
    }
    
    return dp[n-1][3];
} */

//Method 4:- Space Optimization
int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<int> dp(4, 0);
    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][0], points[0][1]);
    dp[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int currDay=1; currDay<n; currDay++) {
        vector<int> temp(4, 0);
        for(int lastTask=0; lastTask<4; lastTask++) {
            temp[lastTask] = 0;
            for(int task=0; task<=2; task++) {
                if(task != lastTask) {
                    int activity = points[currDay][task] + dp[task];
                    temp[lastTask] = max(activity, temp[lastTask]);
                }
            }
        }
        dp = temp;
    }
    return dp[3];
}

int main() {
    vector<vector<int>> points = {{10,40,70}, {20,50,80}, {30,60,90}};
    int n = points.size();
    cout<<"Maximum Points collected from Trainings by Ninja are: "<<ninjaTraining(n, points);
    return 0;
}