#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[]= {0, 2, 1, 2, 0};
    int length = sizeof(arr)/sizeof(arr[0]);
    cout<<"The values of Array before sorting: ";
    for(int i=0; i<length; i++) {
        cout<<arr[i]<<" ";
    }
    int k=0;
    int result[length];
    for(int i=0; i<=2; i++) {
        for(int j=0; j<length; j++) {
            if(arr[j] == i) {
                result[k] = i;
                k++;
            }
        }
    }
    cout<<"\nThe values of Array after sorting: ";
    for(int i=0; i<length; i++) {
        cout<<result[i]<<" ";
    }
    return 0;
}
