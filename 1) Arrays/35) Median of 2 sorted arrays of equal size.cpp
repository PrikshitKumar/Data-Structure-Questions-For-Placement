#include<bits/stdc++.h>
using namespace std;

/* Method 1: The Time Complexity of this method is O(n), as it traverse through the array and made 
     the Comparisons. */
/* int findMedian(int arr1[], int arr2[], int length) {
    int median1 = -1, median2 = -1, i = 0, j = 0;
    for(int counter = 0; counter <= length; counter++) {
        if(i == length) {
            median1 = median2;
            median2 = arr2[0];
            break;
        }
        else if(j == length) {
            median1 = median2;
            median2 = arr1[0];
            break;
        }

        if(arr1[i] <= arr2[j]) {
            median1 = median2;
            median2 = arr1[i];
            i++;
        }
        else {
            median1 = median2;
            median2 = arr2[j];
            j++;
        }
    }
    return (median1+median2)/2;
} */

/* Method 2: The Time Complexity of this method is O(logn). */
int getMedian(int arr[], int length) {
    if(length%2 == 0) {
        return (arr[length-1/2] + arr[length+1/2]) / 2;
    }
    return arr[length/2];
}

int findMedian(int arr1[], int arr2[], int length) {
    if(length == 0) return -1;
    else if(length == 1) return (arr1[0]+arr2[0])/2;
    else if(length == 2) {
        return (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1])) / 2;
    }
    else {
        int median1 = getMedian(arr1, length);
        int median2 = getMedian(arr2, length);

        if(median1 == median2) return median1;
        else if(median1 < median2) {
            if(length%2 == 0) {
                return findMedian(arr1+(length-1)/2, arr2, length-((length+1)/2) );
            }
            return findMedian(arr1+(length/2), arr2, length-(length/2));
        }
        else {
            if(length%2 == 0) {
                return findMedian(arr2+(length-1)/2, arr1, length-((length+1)/2) );
            }
            return findMedian(arr2+(length/2), arr1, length-(length/2));
        }
    }
}

int main() {
    // int arr1[] = {1, 12, 15, 26, 38};
    int arr1[] = {1, 9, 10, 15, 20};
    int arr2[] = {2, 3, 5, 8, 13};
    // int arr2[] = {2, 13, 17, 30, 45};
    int length = sizeof(arr1)/sizeof(arr1[0]);
    cout<<"Elements of Array 1 are: ";
    for(int i=0; i<length; i++) cout<<arr1[i]<<" ";
    cout<<"\nElements of Array 2 are: ";
    for(int i=0; i<length; i++) cout<<arr2[i]<<" ";
    cout<<"\nMedian of 2 Sorted Array are: "<<findMedian(arr1, arr2, length);
    return 0;
}