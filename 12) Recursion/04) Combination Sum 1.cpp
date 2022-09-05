#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &candidates, int target, vector<int> &vec, vector<vector<int>> &result, int curr) {
    if(curr == candidates.size()) {
        if(target == 0) {
            result.push_back(vec);
        }
        return;
    }
    
    if(candidates[curr] <= target) {
        vec.push_back(candidates[curr]);
        solve(candidates, target-candidates[curr], vec, result, curr);
        vec.pop_back();
    }
    
    solve(candidates, target, vec, result, curr+1);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> vec;
    vector<vector<int>> result;
    solve(candidates, target, vec, result, 0);
    return result;
}

int main() {
    vector<int> candidates {2, 3, 6, 7};
    int target = 7;
    cout<<"Elements of the Array are: ";
    for(int i=0; i<candidates.size(); i++) cout<<candidates[i]<<" ";
    cout<<"\nTarget is: "<<target;
    cout<<"\n\nAll Combinations with Sum equals to '"<<target<<"' are: "<<endl;

    vector<vector<int>> result = combinationSum(candidates, target);
    for(int i=0; i<result.size(); i++) {
        for(int j=0; j<result[i].size(); j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}