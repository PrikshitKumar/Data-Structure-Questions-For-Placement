#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {        
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        int middle = left + (right - left) / 2;
        if (nums[middle] > nums[right]) {
            left = middle + 1;
        }
        else {
            right = middle;
        }
    }
    int pivot = left;
    left = 0;
    right = nums.size() - 1;
    if (target >= nums[pivot] && target <= nums[right]) {
        left = pivot;
    } else {
        right = pivot;
    }

    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (nums[middle] == target) {
            return middle;
        } else if (target < nums[middle]) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    return -1;
}

int main() {
    // vector<int> nums{4,5,6,7,0,1,2};
    // int target = 0;
    vector<int> nums{8,9,0,1,2,3,4,5};
    int target = 8;
    cout<<"Elements of the array are: ";
    for(int i=0; i<nums.size(); i++) cout<<nums[i]<<" ";
    cout<<"\nValue present at index Number: "<<search(nums, target);
    return 0;
}
