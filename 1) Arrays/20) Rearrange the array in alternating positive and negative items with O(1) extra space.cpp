#include<bits/stdc++.h>
using namespace std;

void rightShift(int arr[], int start, int end) {
    int temp = arr[end];
    for(int i=end; i>start; i--) {
        arr[i] = arr[i-1];
    }
    arr[start] = temp;
}

void rearrangeTheArray(int arr[], int length) {
    int wrongIndex = -1;
    for(int i=0; i<length; i++) {
        if(wrongIndex != -1) {
            if((arr[wrongIndex]<0 && arr[i]>=0) || (arr[wrongIndex]>=0 && arr[i]<0)) {
                rightShift(arr, wrongIndex, i);
                // if(i-wrongIndex >= 2) wrongIndex += 2;
                i = wrongIndex;
                wrongIndex = -1;
            }
        }
        else {
            if((i%2==0 && arr[i]>=0) || (i%2==1 && arr[i]<0))
                wrongIndex = i;
        }
    }
}

int main() {
    int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    // Output: {-5, 5, -2, 2, -8, 4, 7, 1, 8, 0}
    // int arr[] = {1, 2, 3, -4, -1, 4};
    // output: {-4, 1, -1, 2, 3, 4}
    int length = sizeof(arr)/sizeof(arr[0]);
    cout<<"Elements of the Array are: ";
    for(int i=0; i<length; i++) cout<<arr[i]<<" ";
    cout<<"\nResultant Array is: ";
    rearrangeTheArray(arr, length);
    for(int i=0; i<length; i++) cout<<arr[i]<<" ";
    return 0;
}