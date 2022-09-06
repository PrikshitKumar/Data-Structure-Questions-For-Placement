#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, int freq[]) {
    if(ds.size() == nums.size()) {
        ans.push_back(ds);
        return;
    }
    for(int i=0; i<nums.size(); i++) {
        if(!freq[i]) {
            ds.push_back(nums[i]);
            freq[i] = 1;
            solve(nums, ds, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[nums.size()];
    for(int i=0; i<nums.size(); i++) freq[i] = 0;
    solve(nums, ds, ans, freq);
    return ans;
}

int main() {
    vector<int> vec = {1, 2, 3};
    cout<<"Elements of the Array are: ";
    for(int i=0; i<vec.size(); i++) cout<<vec[i]<<" ";
    cout<<"\nPermutation of given Array are:\n";
    vector<vector<int>> ans = permute(vec);
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    } 
    return 0;
}