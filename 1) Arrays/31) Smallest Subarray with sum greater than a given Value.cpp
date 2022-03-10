#include<bits/stdc++.h>
using namespace std;

int smallestSubArray(int arr[], int length, int k) {
    int start = 0, end = 0, sum = 0, result = INT_MAX;
    while(end < length) {
        if((sum+arr[end]) <= k) {
            sum += arr[end++];
        }
        else {
            result = (result < (end-start+1)) ? result : (end-start+1);
            end = ++start;
            sum = 0;
        }
    }
    return result;
}

int main() {
    int arr[] = {1, 4, 45, 6, 10, 19};
    int length = sizeof(arr)/sizeof(arr[0]);
    int k = 51;
    cout<<"Elements of an Array are: ";
    for(int i=0; i<length; i++) cout<<arr[i]<<" ";
    cout<<"\nLength of Smallest Sub-Array with sum greater than "<<k<<" is: "<<smallestSubArray(arr, length, k);
    return 0;
}