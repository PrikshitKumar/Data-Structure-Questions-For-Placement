#include<bits/stdc++.h>
using namespace std;

long long trappingWater(int arr[], int n) {
    long long result = 0;
    int left[n], right[n];
    left[0] = arr[0];
    right[n-1] = arr[n-1];
    for(int i=1; i<n; i++) {
        if(arr[i] > left[i-1]) {
            left[i] = arr[i];
        }
        else {
            left[i] = left[i-1];
        }
    }
    for(int i=n-2; i>=0; i--) {
        if(arr[i] > right[i+1]) {
            right[i] = arr[i];
        }
        else {
            right[i] = right[i+1];
        }
    }
    for(int i=0; i<n; i++) {
        result += min(left[i], right[i])-arr[i];
    }
    return result;
}

int main() {
    int arr[] = {3, 0, 0, 2, 0, 4};
    int length = sizeof(arr)/sizeof(arr[0]);
    cout<<"Heights of the Buildings are: ";
    for(int i=0; i<length; i++) cout<<arr[i]<<" ";
    cout<<"\nMaximum Trapping Water is: "<<trappingWater(arr, length);
    return 0;
}