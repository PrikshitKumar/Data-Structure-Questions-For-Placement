#include<bits/stdc++.h>
using namespace std;

void swap(int arr[], int firstIndex, int secondIndex) {
    int temp = arr[firstIndex];
    arr[firstIndex] = arr[secondIndex];
    arr[secondIndex] = temp;
}

int partition(int arr[], int start, int end) {
    int pivotElement = arr[start];
    int i = start;
    int j = end;
    while(i < j) {
        while(arr[i] <= pivotElement) i++;
        while(arr[j] > pivotElement) j--;
        if(i < j) {
            swap(arr, i, j);
        }
    }
    swap(arr, start, j);
    return j;
}

void quickSort(int arr[], int start, int end) {
    if(start < end) {
        int pivotIndex = partition(arr, start, end);
        quickSort(arr, start, pivotIndex-1);
        quickSort(arr, pivotIndex+1, end);
    }
}

void printArray(int arr[], int length) {
    for(int i=0; i<length; i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {
    int length;
    cout<<"Enter the length of Array: ";
    cin>>length;
    int arr[length];
    cout<<"Enter the Elements of the Array: ";
    for(int i=0; i<length; i++) {
        cin>>arr[i];
    }
    cout<<"Elements of Array before Sorting: ";
    printArray(arr, length);
    cout<<"\nElements of Array after Sorting: ";
    quickSort(arr, 0, length-1);
    printArray(arr, length);
    return 0;
}