#include<bits/stdc++.h>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m) {
    // code here
    int gap = ceil((float)(m+n)/2);
    while(gap > 0) {
        int i = 0;
        int j = gap;
        while (j < (n + m)) {
            if (j < n && arr1[i] > arr1[j]) {
                swap(arr1[i], arr1[j]);
            } 
            else if (j >= n && i < n && arr1[i] > arr2[j - n]) {
                swap(arr1[i], arr2[j - n]);
            } 
            else if (j >= n && i >= n && arr2[i - n] > arr2[j - n]) {
                swap(arr2[i - n], arr2[j - n]);
            }
            j++; i++;
        }
        if(gap == 1) break;
        gap = ceil((float)(gap)/2);
    }
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {0, 2, 6, 8, 9};
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    cout<<"Before Sorting:-";
    cout<<"\nElements of the Array 1 are: ";
    for(int i=0; i<size1; i++) cout<<arr1[i]<<" ";
    cout<<"\nElements of the Array 2 are: ";
    for(int i=0; i<size2; i++) cout<<arr2[i]<<" ";
    cout<<"\n\nAfter Merging:-";
    merge(arr1, arr2, size1, size2);
    cout<<"\nElements of the Array 1 are: ";
    for(int i=0; i<size1; i++) cout<<arr1[i]<<" ";
    cout<<"\nElements of the Array 2 are: ";
    for(int i=0; i<size2; i++) cout<<arr2[i]<<" ";
    return 0;
}