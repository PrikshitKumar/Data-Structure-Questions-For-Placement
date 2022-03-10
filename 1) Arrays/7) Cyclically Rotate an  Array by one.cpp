#include<bits/stdc++.h>
using namespace std;

void rotate(int arr[], int length) {
    int temp[length];
    for(int i=0; i<length; i++) {
        temp[i] = arr[i];
    }
    for(int i=0; i<length; i++) {
        if(i==0) {
            arr[i] = temp[length-1];
        }
        else {
            arr[i] = temp[i-1];
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int length = sizeof(arr)/sizeof(arr[0]);
    cout<<"Elements of Arrays before Rotation: ";
    for(int i=0; i<length; i++) {
        cout<<arr[i]<<" ";
    }
    rotate(arr, length);
    cout<<"\nElements of Arrays after Rotation: ";
    for(int i=0; i<length; i++) {
        cout<<arr[i]<<" ";
    }
}