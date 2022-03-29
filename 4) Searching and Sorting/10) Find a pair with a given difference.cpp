#include<bits/stdc++.h>
using namespace std;

bool findPair(int arr[], int size, int n){
    if(n==0) return false;
    map<int, int> values;
    for(int i=0; i<size; i++) values[arr[i]]++;
    for(int i=0; i<size; i++) {
        if(values[arr[i]+n]) return true;
    }
    return false;
}

int main() {
    int arr[] = {5, 20, 3, 2, 5, 80};
    int length = sizeof(arr)/sizeof(arr[0]);
    int diff = 78;
    cout<<"Elements of the Array are: ";
    for(int i=0; i<length; i++) cout<<arr[i]<<" ";
    cout<<"\nWhether any pair is present in the Array whose differen is equal to '"<<diff<<"': ";
    cout<<findPair(arr, length, diff);
    return 0;
}