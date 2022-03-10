#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][0] <= result.back()[1]) {
                result.back()[1] = max(intervals[i][1], result.back()[1]);
            } 
            else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }

int main() {
    vector<vector<int>> intervals{{1,3},{2,6},{8,10},{15,18}};
    cout<<"Intervals before Merging: ";
    for(int i=0; i<intervals.size(); i++) {
        cout<<"["<<intervals[i][0]<<"]["<<intervals[i][1]<<"] ";
    }
    vector<vector<int>> result = merge(intervals);
    cout<<"\nIntervals after Merging: ";
    for(int i=0; i<result.size(); i++) {
        cout<<"["<<result[i][0]<<"]["<<result[i][1]<<"] ";
    }
    return 0;
}