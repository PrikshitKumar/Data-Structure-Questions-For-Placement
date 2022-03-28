#include<bits/stdc++.h>
using namespace std;

int majorityElement(int a[], int size) {
    int result = -1;
    sort(a, a+size);
    int index = 0;
    for(int i=0; i<size; ) {
        int j = i+1, count = 1;
        while(a[j] == a[i]) {
            j++; count++;
        }
        if(count > size/2) result = a[i];
        i = j;
    }
    return result;
}

int main() {
    int arr[] = {3,1,3,3,2};
    int length = sizeof(arr)/sizeof(arr[0]);
    cout<<"Elements of the Array are: ";
    for(int i=0; i<length; i++) cout<<arr[i]<<" ";
    cout<<"\nMajorty Element in the Array is: "<<majorityElement(arr, length);
    return 0; 
}