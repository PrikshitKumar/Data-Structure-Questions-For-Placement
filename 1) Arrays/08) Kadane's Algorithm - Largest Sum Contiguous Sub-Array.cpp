#include<bits/stdc++.h>
using namespace std;

int largestSum(int arr[], int length) {
    int result = 0;
    int temp = 0;
    for(int i=0; i<length; i++) {
        if((temp + arr[i]) < 0) {
            temp = 0;
        }
        else if((temp + arr[i]) > result) {
            result = temp + arr[i];
            temp += arr[i];
        }
        else {
            temp += arr[i];
        }
    }
    // If all the elements are negative
    if(result==0) {
        result = arr[0];
        for(int i=1; i<length; i++) {
            if(result < arr[i]) result = arr[i];
        }
    }
    return result;
}

int main() {
    // int arr[] = {2, -3, 4, -1, -2, 1, 5, -3};
    // int arr[] = {1, 2, 3, -2, 5};
    int arr[] = {-1, -2, -3, -4};
    int length = sizeof(arr)/sizeof(arr[0]);
    cout<<"Elements of Array: ";
    for(int i=0; i<length; i++) {
        cout<<arr[i]<<" ";
    }
    int result = largestSum(arr, length);
    cout<<"\nLargest Sum of Contiguous Sub-Array is: "<<result<<endl;
    return 0;
}
