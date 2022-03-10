#include<bits/stdc++.h>
using namespace std;

int minimumJumps(int arr[], int length) {
    if(length == 1) return 0;
    int jumps = 0;
    for(int i=0; i<length; ) {
        if(arr[i] == 0 && i < length-1) return -1;
        else if(i+arr[i] > length) {
            jumps++;
            return jumps;
        }
        else if(arr[i] + i == length-1) {
            jumps++;
            i = length-1;
            return jumps;
        }
        int max = arr[i+1];
        int maxIndex = i+1;
        for(int j=i+1; j<=i+arr[i]; j++) {
            if(arr[j] > max) { 
                max = arr[j];
                maxIndex = j;
            }
        }
        i = maxIndex;
        jumps++;
    }
    return jumps;
}

int main() {
    // int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int arr[] = {2, 3, 1, 1, 2, 4, 2, 0, 1, 1};
    int length = sizeof(arr)/sizeof(arr[0]);
    cout<<"Elements of the Array are: ";
    for(int i=0; i<length; i++) {
        cout<<arr[i]<<" ";
    }    
    cout<<"\nMinimum Number of Jumps to reach the end of an Array are: "<<minimumJumps(arr, length);
    return 0;
}