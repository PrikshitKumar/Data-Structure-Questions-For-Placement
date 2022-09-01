#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int size, int curr) {
    int largest = curr;
    int left = curr*2 + 1;
    int right = curr*2 + 2;

    if(left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    if(right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    if(largest != curr) {
        swap(arr[curr], arr[largest]);
        heapify(arr, size, largest);
    }
}

void convertToMaxHeap(int arr[], int size) {
    for(int i=size/2; i>=0; i--) {
        heapify(arr, size, i);
    }
}

int main() {
    int arr[] = { 3, 5, 9, 6, 8, 20, 10, 12, 18, 9 };
    int size = sizeof(arr)/sizeof(arr[0]);
 
    cout<<"The elements of Min Heap are: ";
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";

    convertToMaxHeap(arr, size);
 
    cout<<"\nThe Elements of Max Heap are: ";
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
 
    return 0;
}