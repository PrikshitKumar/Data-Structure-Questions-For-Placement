#include<bits/stdc++.h>
using namespace std;

int firstOccurence(int arr[], int size, int k, int x) {
    if(arr[0] == x) return 0;
    for(int i=1; i<size; i++) {
        if(abs(arr[i]-arr[i-1]) <= k) {
            if(arr[i] == x) return i;
        }
        else return -1;
    }
    return -1;
}

int main() {
    int arr[] = {4, 5, 6, 7, 6};
    int k = 1, x = 6;
    int length = sizeof(arr)/sizeof(arr[0]);
    cout<<"Elements of the Array are: ";
    for(int i=0; i<length; i++) cout<<arr[i]<<" ";
    cout<<"\nFirst Occurrence of "<<x<<" is present at: "<<firstOccurence(arr, length, k, x);
    return 0;
}