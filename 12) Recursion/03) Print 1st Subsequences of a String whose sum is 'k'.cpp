#include<bits/stdc++.h>
using namespace std;

bool printSubsequences(int arr[], int len, int sum, vector<int> &vec, int curr, int currSum) {
    if(curr >= len) {
        if(currSum == sum) {
            for(int i=0; i<vec.size(); i++) cout<<vec[i]<<" ";
            return true;
        }
        return false;
    }
    
    currSum += arr[curr];
    vec.push_back(arr[curr]);
    // Pick the Element
    if(printSubsequences(arr, len, sum, vec, curr+1, currSum) == true) return true;
    
    currSum -= arr[curr];
    vec.pop_back();
    // Without Picking the Element
    if(printSubsequences(arr, len, sum, vec, curr+1, currSum) == true) return true;
    
    return false;     
}

int main() {
    int arr[] = {1, 2, 1};
    int len = sizeof(arr)/sizeof(arr[0]);
    int sum = 2;
    int currSum = 0;
    vector<int> vec;
    printSubsequences(arr, len, sum, vec, 0, currSum);
    return 0;
}