#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int size) {
    int gap = (int) ceil(size/2.0);
    while(gap > 0) {
        int start = 0, end = gap;
        while(end < size) {
            if(arr[start] > arr[end]) {
                swap(arr[start], arr[end]);
            }
            start++; end++;
        }
        if(gap == 1) break;
        gap = (int) ceil(gap/2.0);
    }
}

int main() {
    int arr[] = {3, 16, 5, 14, 8,  10, 7, 15, 1, 13, 4, 9,  12, 11, 6, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before Sorting:-";
    cout<<"\nElements of the Array are: ";
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
    cout<<"\n\nAfter Merging:-";
    merge(arr, size);
    cout<<"\nElements of the Array are: ";
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
    return 0;
}