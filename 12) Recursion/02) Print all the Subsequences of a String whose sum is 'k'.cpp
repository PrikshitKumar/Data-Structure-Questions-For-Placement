#include<bits/stdc++.h>
using namespace std;

void printSubsequences(int arr[], int len, int sum, vector<int> &vec, int curr, int currSum) {
    if(curr >= len) {
        if(currSum == sum) {
            for(int i=0; i<vec.size(); i++) cout<<vec[i]<<" ";
            cout<<endl;
        }
        return;
    }
    currSum += arr[curr];
    vec.push_back(arr[curr]);
    printSubsequences(arr, len, sum, vec, curr+1, currSum);     // Pick the Element
    currSum -= arr[curr];
    vec.pop_back();
    printSubsequences(arr, len, sum, vec, curr+1, currSum);     // Without Picking the Element
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