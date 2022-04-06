#include<bits/stdc++.h>
using namespace std;

bool allocationIsPossible(int arr[], int length, int barrier, int m) {
    int allocatedStudents = 1, pages = 0;
    for(int i=0; i<length; i++) {
        if(arr[i] > barrier) return false; 
        else if(arr[i]+pages > barrier) {
            allocatedStudents += 1;
            pages = arr[i];
        }
        else pages += arr[i];
    }
    if(allocatedStudents > m) return false;
    return true;
}

int findPages(int arr[], int length, int m) {
    int minSum = INT_MAX, maxSum = 0;
    for(int i=0; i<length; i++) {
        maxSum += arr[i];
        minSum = arr[i]<minSum ? arr[i] : minSum;
    }
    int start = minSum, end = maxSum, result = -1;
    while(start <= end) {
        int mid = (start + end) >> 1;
        if(allocationIsPossible(arr, length, mid, m)) {
            result = mid;
            end = mid-1;
        }
        else start = mid+1;
    }
    return result;
}

int main() {
    int arr[] = {12,34,67,90};
    int size = sizeof(arr)/sizeof(arr[0]);
    int m = 2; // Number of Students
    for(int i=0; i<size; i++) 
        cout<<"Pages of Book "<<i+1<<" are: "<<arr[i]<<endl;
    cout<<"Minimum Number of Pages Allocation among Students are: "<<findPages(arr, size, m);
    return 0;
}