#include<bits/stdc++.h>
using namespace std;

int minSwaps(vector<int>&nums) {
    int count = 0;
    unordered_map<int, int> temp;
    for(int i=0; i<nums.size(); i++) {
        temp[nums[i]] = i;
    }
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size(); ) {
        if(i == temp[nums[i]] ) i++;
        else {
            swap(nums[i], nums[temp[nums[i]]]);
            count++;
        }
    }
    return count;
}

int main() {
    vector<int> nums {10, 19, 6, 3, 5};
    cout<<"Elements of the Array are: ";
    for(int i=0; i<nums.size(); i++) cout<<nums[i]<<" ";
    cout<<"\nMinimum Number of Swaps required to sort the Array are: "<<minSwaps(nums);    
    return 0;
}