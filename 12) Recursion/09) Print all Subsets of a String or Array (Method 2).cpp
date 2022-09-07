#include<bits/stdc++.h>
using namespace std;

/* Method 2:- By fixing the Place of every value in Array and swap the rest of the values for 
    getting the permutations with all pairs of values. Basically, Swap the element with all the 
    elements next to them.

    For Eg: If arr[] = {1, 2, 3};
    1st level of Recursion Tree:-                             {1, 2, 3}  // currIndex = 0; (current Index for swapping)
    2nd level of Recursion Tree:-      {1, 2, 3};             {2, 1, 3};             {3, 2, 1}   // currIndex = 1
    3rd level of Recursion Tree:- {1, 2, 3}, {1, 3, 2};  {2, 1, 3}, {2, 3, 1};  {3, 2, 1}, {3, 1, 2};   // currIndex = 2
    4th level of Recursion Tree:- {1, 2, 3}, {1, 3, 2};  {2, 1, 3}, {2, 3, 1};  {3, 2, 1}, {3, 1, 2};   // currIndex = 3
    
    When currIndex equals to the size of Array, we got all the possible pairs of permutations.
*/
void solve(vector<int> &nums, vector<vector<int>> &ans, int curr) {
    if(curr == nums.size()) {
        ans.push_back(nums);
        return;
    }
    for(int i=curr; i<nums.size(); i++) {
        swap(nums[curr], nums[i]);
        solve(nums, ans, curr+1);
        swap(nums[curr], nums[i]);  // BackTracking
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    solve(nums, ans, 0);
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