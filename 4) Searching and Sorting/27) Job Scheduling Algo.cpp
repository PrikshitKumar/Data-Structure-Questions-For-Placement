#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int> &v1, vector<int> &v2) {
    return v1[1] < v2[1];
}

int maxProfit(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
    int size = startTime.size();
    vector<vector<int>> vec(size);
    for(int i=0; i<size; i++) {
        int x = startTime[i];
        int y = endTime[i];
        int z = profit[i];
        vec[i] = {x, y, z};
    }
    sort(vec.begin(), vec.end(), compare);
    int dp[size] = {0};
    dp[0] = vec[0][2];
    for(int i=1; i<size; i++) {
        int including = vec[i][2];
        int withoutIncluding = -1;
        int low = 0, high = size-1;
        while(low <= high) {
            int mid = (low+high) >> 1;
            if(vec[mid][1] <= vec[i][0]) {
                withoutIncluding = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        if(withoutIncluding != -1) including += dp[withoutIncluding];
        int excluding = dp[i-1];
        dp[i] = max(including, excluding);
    }
    return dp[size-1];
}

int main() {
    vector<int> startingTime {1, 3, 6, 2};
    vector<int> endingTime {2, 5, 19, 100};
    vector<int> profit {50, 20, 100, 200};
    cout<<"Data of Jobs: "<<endl;
    cout<<"Starting Time \tEnding Time \tProfit"<<endl;
    for(int i=0; i<profit.size(); i++) {
        cout<<"      "<<startingTime[i]<<"\t\t     "<<endingTime[i]<<"\t\t  "<<profit[i]<<endl;
    }
    cout<<"\nMaximum Profit is: "<<maxProfit(startingTime, endingTime, profit)<<endl;
    return 0;
}