#include<bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int length) {
    int sum = 0, temp = 0;
    for(int i=0; i<length; i++) {
        temp += arr[i];
        if(temp < 0) temp = 0;
        if(temp > sum) sum = temp;
    }
    // If all the elements are negative
    if(sum==0) {
        sum = arr[0];
        for(int i=1; i<length; i++) {
            if(sum < arr[i]) sum = arr[i];
        }
    }
    return sum;
}

int main() {
    int arr[] = {1, 2, 3, -2, 5};
    int length = sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum Sum: "<<maxSum(arr, length);
    return 0;
}