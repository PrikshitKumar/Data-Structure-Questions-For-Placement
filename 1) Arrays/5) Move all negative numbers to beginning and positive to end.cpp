#include<bits/stdc++.h>
using namespace std;

void changePositions(int arr[], int length) {
    int result[length];
    for(int i=0; i<length; i++) {
        result[i] = arr[i];
    }
    int k=0;
    for(int i=0; i<length; i++) {
        if(result[i] < 0) {
            arr[k] = result[i];
            k++;
        }
    }
    for(int i=0; i<length; i++) {
        if(result[i] > 0) {
            arr[k] = result[i];
            k++;
        }
    }
}

int main() {
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int length = sizeof(arr)/sizeof(arr[0]);
    cout<<"Elements of Arrays before changing the positions: ";
    for(int i=0; i<length; i++) {
        cout<<arr[i]<<" ";
    }
    changePositions(arr, length);
    cout<<"\nElements of Arrays after changing the positions: ";
    for(int i=0; i<length; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}