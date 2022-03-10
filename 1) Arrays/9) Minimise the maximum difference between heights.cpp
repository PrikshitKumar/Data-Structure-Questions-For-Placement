#include<bits/stdc++.h>
using namespace std;
/*
    k = 5
    n = 10
    arr[] = 2 6 3 4 7 2 10 3 2 1
    Answer: 7
*/

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

int heigthDifference(int arr[], int n, int k) {
    int minElement, maxElement;
    int result = arr[n-1] - arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i] >= k) {  // height not negative
            maxElement = max(arr[i-1] + k, arr[n-1] - k);
            minElement = min(arr[0] + k, arr[i]-k);
            result = min(result, maxElement - minElement);
        }
    }
    return result;
}

int main() {
    int k, n;
    cout<<"Enter the values of 'k': ";
    cin>>k;
    cout<<"Enter the length of Array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the Elements of Array: ";
    for(int i=0; i<n; i++) { 
        cin>>arr[i];
    }
    quickSort(arr, 0, n-1);
    cout<<"Elements after Sorting: ";
    for(int i=0; i<n; i++) { 
        cout<<arr[i]<<" ";
    }
    cout<<"\nDifference between Heights after Processing: "<<heigthDifference(arr, n, k);
    return 0;
}