#include<bits/stdc++.h>
using namespace std;

int maxProfit(int arr[], int length) {
    int dp[length] = {0}, minimum = arr[0], maximum = arr[length-1];
    // This loop is for getting the Maximum Profit from right to left.
    for(int i=length-2; i>=0; i--) {
        if(arr[i] > maximum) maximum = arr[i];
        dp[i] = max(dp[i+1], maximum-arr[i]);
    }
    // This loop is for getting the Maximum Profit from left to right for second iteration including previous profit, i.e, dp[].
    for(int i=1; i<length; i++) {
        if(arr[i] < minimum) minimum = arr[i];
        dp[i] = max(dp[i-1], dp[i]+(arr[i]-minimum));
    }
    return dp[length-1];
}

int main() {
    // int arr[] = {10, 22, 5, 75, 65, 80};
    int arr[] = {2, 30, 15, 10, 8, 25, 80};
    int length = sizeof(arr)/sizeof(arr[0]);
    cout<<"The Market Price of the Shares is: ";
    for(int i=0; i<length; i++) cout<<arr[i]<<" ";
    cout<<"\nTotal Profit: "<<maxProfit(arr, length);
    return 0;
}