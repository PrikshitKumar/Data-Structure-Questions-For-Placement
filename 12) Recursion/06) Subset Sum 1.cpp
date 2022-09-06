#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int len, int curr, int sum, vector<int> &ans) {
    if(curr == len) {
        ans.push_back(sum);
        return;
    }
    
    solve(arr, len, curr+1, sum+arr[curr], ans);
    solve(arr, len, curr+1, sum, ans);
}

vector<int> subsetSums(vector<int> arr, int N) {
    vector<int> ans;
    solve(arr, N, 0, 0, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> vec {2, 3};
    int len = 2;
    cout<<"Elements of the Array are: ";
    for(int i=0; i<len; i++) cout<<vec[i]<<" ";
    vector<int> ans = subsetSums(vec, len);
    cout<<"\nSum of all possible Subsets is: ";
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
    return 0;
}