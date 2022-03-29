#include<bits/stdc++.h>
using namespace std;

int findMaxSum(int arr[], int n) {
    if(n == 0) return 0;
    else if(n == 1) return arr[0];
    else if(n == 2) return max(arr[0], arr[1]);
    
    int value1 = arr[0];
    int value2 = max(arr[0], arr[1]);
    int max_val;
    
    for (int i=2; i<n; i++) {
        max_val = max(arr[i]+value1, value2);
        value1 = value2;
        value2 = max_val;
    }
    return max_val;
}

int main() {
    int arr[] = {5,5,10,100,10,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Elements of the Array are: ";
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
    cout<<"\nMaximum Stolen Amount: "<<findMaxSum(arr, size);
    return 0;
}