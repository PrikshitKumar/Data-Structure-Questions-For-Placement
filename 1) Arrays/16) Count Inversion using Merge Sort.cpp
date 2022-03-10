#include<bits/stdc++.h>
using namespace std;

// Inversion Count Condition: arr[i] > arr[j] but i < j;

int merge(int arr[], int start, int mid, int end) {
    int inversionCount = 0;
    int length1 = mid-start+1;
    int length2 = end-mid;
    int tempArr1[length1], tempArr2[length2];
    for(int i=0; i<length1; i++) {
        tempArr1[i] = arr[start+i];
    }
    for(int i=0; i<length2; i++) {
        tempArr2[i] = arr[mid+1+i];
    }
    int i=0, j=0, k=start;
    while(i<length1 && j<length2) {
        if(tempArr1[i] <= tempArr2[j]) {
            arr[k] = tempArr1[i];
            i++;
        }
        else {
            arr[k] = tempArr2[j];
            j++;
            inversionCount += length1 - i;
        }
        k++;
    }

    while(i<length1) {
        arr[k] = tempArr1[i];
        i++; k++;
    }

    while(j<length2) {
        arr[k] = tempArr2[j];
        j++; k++;
    }
    return inversionCount;
}

int mergeSort(int arr[], int start, int end) {
    int inversionCount = 0;
    if(start < end) {
        int mid = (start+end)/2;
        inversionCount += mergeSort(arr, start, mid);
        inversionCount += mergeSort(arr, mid+1, end);
        inversionCount += merge(arr, start, mid, end);
    }
    return inversionCount;
}

int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int length = sizeof(arr)/sizeof(arr[0]);
    cout<<"Elements of the Array are: ";
    for(int i=0; i<length; i++) cout<<arr[i]<<" ";
    cout<<"\nInversion Count for the given Array is: "<<mergeSort(arr, 0, length-1);
    cout<<"\nElements of the Array after sorting are: ";
    for(int i=0; i<length; i++) cout<<arr[i]<<" ";
    return 0;
}