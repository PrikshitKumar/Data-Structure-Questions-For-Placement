#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, int curr) {
    ans.push_back(ds);        
    for(int i=curr; i<nums.size(); i++) {
        if(i != curr && nums[i] == nums[i-1]) continue;
        ds.push_back(nums[i]);
        solve(nums, ds, ans, i+1);
        ds.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> ds;
    solve(nums, ds, ans, 0);
    return ans;
}

int main() {
    vector<int> vec {1, 2, 2};
    cout<<"Elements of the Array are: ";
    for(int i=0; i<vec.size(); i++) cout<<vec[i]<<" ";
    cout<<"\nAll the Unique Subsets are:\n";
    vector<vector<int>> ans = uniqueSubsets(vec);
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}