#include<bits/stdc++.h>
using namespace std;

int minSwap(int arr[], int length, int k) {
    int result = INT_MAX, windowSize = 0;
    for(int i=0; i<length; i++) {
        if(arr[i] <= k) windowSize++;
    }
    int start = 0, size = 0, swaps = 0;
    for(int i=0; i<length; ) {
        if(size == windowSize) {
            if(swaps < result) result = swaps;
            swaps = size = 0;
            i = ++start;
            cout<<endl<<i<<" : "<<result;
        }
        else {
            if(arr[i++] > k) {
                swaps++;
            }
            size++;
        }
    }
    if(swaps < result) result = swaps;
    return result;
}

int main() {
    // n = 5; arr[] = {2, 1, 5, 6, 3}; k = 3; Ans: 1
    // n = 7; arr[] = {2, 7, 9, 5, 8, 7, 4}; k=6; Ans: 2
    int arr[] = {2, 1, 5, 6, 3};
    // int arr[] = {2, 7, 9, 5, 8, 7, 4};
    int length = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout<<"Elements of an Array are: ";
    for(int i=0; i<length; i++) cout<<arr[i]<<" ";
    cout<<"\nMinimum Swaps: "<<minSwap(arr, length, k);
    return 0;
}