#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int start, int mid, int end) {
    int len1 = mid-start+1;
    int len2 = end-mid;
    int tempArr1[len1];
    int tempArr2[len2];

    for(int i=0; i<len1; i++) {
        tempArr1[i] = arr[start+i];
    }
    for(int i=0; i<len2; i++) {
        tempArr2[i] = arr[mid+1+i];
    }
    
    int i=0, j=0, k=start;
    while(i<len1 && j<len2) {
        if(tempArr1[i] < tempArr2[j]) {
            arr[k] = tempArr1[i];
            i++; k++;
        }
        else {
            arr[k] = tempArr2[j];
            j++; k++;
        }
    }

    // Check whether all the elements of Array are saved or not!
    while(i<len1) {
        arr[k] = tempArr1[i];
        i++; k++;
    }
    while(j<len2) {
        arr[k] = tempArr2[j];
        j++; k++;
    }
}

void mergeSort(int arr[], int start, int end) {
    if(start < end) {
        int mid = (start+end)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15}; 
    // int arr[] = {7, 10, 4, 20, 15};
    int length = sizeof(arr)/sizeof(arr[0]);
    int k;
    cout<<"Elements of the Array before Sorting are: ";
    for(int i=0; i<length; i++) {
        cout<<arr[i]<<" ";
    }
    mergeSort(arr, 0, length-1);
    cout<<"\nElements of the Array after Sorting are: ";
    for(int i=0; i<length; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}