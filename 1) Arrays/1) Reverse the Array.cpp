#include <bits/stdc++.h>
using namespace std;

void reverseTheArray(int arr[], int length) {
    int start = 0;
    int last = length-1;
    while(last > start) {
        int temp = arr[start];
        arr[start] = arr[last];
        arr[last] = temp;
        last--;
        start++;
    }
}

int main() {
    int arr[] = {5, 9, 6, 7, 2, 10, 45};
    int length = sizeof(arr)/sizeof(arr[0]);
    cout<<"Values before Reversing: ";
    for(int i=0; i<length; i++) {
        cout<<arr[i]<<" ";
    }
    reverseTheArray(arr, length);
    cout<<"\nValues after Reversing: ";
    for(int i=0; i<length; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}