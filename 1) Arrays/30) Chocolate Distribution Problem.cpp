#include<bits/stdc++.h>
using namespace std;

int findMinDiff(int a[], int n, int m) {
    sort(a, a+n);
    int result = INT_MAX;
    for(int i=0; i+m-1<n; i++) {
        if(a[i+m-1]-a[i] < result) {
            result = a[i+m-1]-a[i];
        }
    }
    return result;
}  

int main() {
    int arr[] = {3, 4, 1, 9, 56, 7, 9, 12};
    int length = sizeof(arr)/sizeof(arr[0]);
    int M = 5;
    cout<<"Total Number of Students in a Class are: "<<M;
    for(int i=0; i<length; i++) {
        cout<<"\nNumber of Chocolates in Packet number "<< i+1 <<": "<<arr[i];
    }
    cout<<"\nThe difference between maximum number of chocolates and minimum number of chocolates given to a student is: ";
    cout<<findMinDiff(arr, length, M);
    return 0;
}