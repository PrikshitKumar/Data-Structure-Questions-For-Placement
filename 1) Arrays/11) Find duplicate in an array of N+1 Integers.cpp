#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
    vector<int> arr(nums.size(), 0);
    int result = 0;
    for(int i=0; i<nums.size(); i++) {
        arr[nums[i]]++;
        if(arr[nums[i]] > 1) {
            return nums[i];
        }
    }
    return result;
}

int main() {
    vector<int> vec{8, 1, 1, 1, 2, 7, 4, 3, 1, 1};
    cout<<"Duplicate Element is: "<<findDuplicate(vec);
    return 0;
}