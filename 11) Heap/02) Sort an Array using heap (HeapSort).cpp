#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int size, int curr) {
    int largest = curr;
    int left = (curr*2)+1;
    int right = (curr*2)+2;

    if(left < size && arr[largest] < arr[left]) {
        largest = left;
    }
    if(right < size && arr[largest] < arr[right]) {
        largest = right;
    }

    if(largest != curr) {
        swap(arr[largest], arr[curr]);
        heapify(arr, size, largest);
    }    
}

void heapSort(int arr[], int n) {
    for(int i=(n/2)-1; i>=0; i--) {
        heapify(arr, n, i);
    }
    for(int i=n-1; i>=0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void print(int arr[], int size) {
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<"Elements of Array before Sorting: ";
    print(arr, len);
    heapSort(arr, len);
    cout<<"After apply Heap Sort: ";
    print(arr, len);
}