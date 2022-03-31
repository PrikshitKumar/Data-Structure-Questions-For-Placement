#include<bits/stdc++.h>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
    vector<long long int> result(n, 0);
    long long temp = 1, withoutZero = 1, zeroesCount = 0;
    for(int i=0; i<n; i++) {
        temp *= nums[i];
        if(nums[i] != 0) {
            withoutZero *= nums[i];
        }
        if(nums[i] == 0) zeroesCount++;
    }
    for(int i=0; i<n; i++) {
        if(nums[i] == 0) {
            if(zeroesCount > 1) result[i] == 0;
            else result[i] = withoutZero;
        }
        else {
            result[i] = temp/nums[i];
        }
    }
    return result;
}

int main() {
    vector<long long int> arr {10, 3, 5, 6, 2};
    cout<<"Elements of the Array are: ";
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    cout<<"\nResultant Array: ";
    arr = productExceptSelf(arr, arr.size());
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    return 0;
}