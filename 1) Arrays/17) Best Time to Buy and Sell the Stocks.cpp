#include<bits/stdc++.h>
using namespace std;

int maxProfit(int arr[], int length) {
    int profit = 0, stockPrice = INT_MAX;
    for(int i=0; i<length; i++) {
        stockPrice = min(stockPrice, arr[i]);
        profit = max(profit, arr[i]-stockPrice);
    }
    return profit;
}

int main() {
    int arr[] = {7, 1, 5, 3, 6, 4};
    int length = sizeof(arr)/sizeof(arr[0]);
    cout<<"Elements of the Array are: ";
    for(int i=0; i<length; i++) cout<<arr[i]<<" ";
    cout<<"\nMaximum Profit is: "<<maxProfit(arr, length);
    return 0;
}