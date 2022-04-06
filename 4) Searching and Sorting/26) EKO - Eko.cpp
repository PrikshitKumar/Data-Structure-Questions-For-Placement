#include<bits/stdc++.h>
using namespace std;

int totalWood(int arr[], int length, int k) {
    sort(arr, arr+length);
    int start = 0, end = arr[length-1];
    int result = 0;
    while(start <= end) {
        int mid = (start+end) >> 1;
        int sum = 0;
        for(int i=0; i<length; i++) {
            if(arr[i] > mid) sum += arr[i]-mid;
        }
        if(sum >= k) {
            result = mid;
            start = mid+1;
        }
        else end = mid-1;
    }
    return result;
}

int main() {
    int arr[] = {4, 42, 40, 26, 46};
    int length = sizeof(arr)/sizeof(arr[0]);
    int k = 20;
    cout<<"Length of Trees are: ";
    for(int i=0; i<length; i++) cout<<arr[i]<<" ";
    cout<<"\nHe could cut the Trees from length: "<<totalWood(arr, length, k)<<" for getting "<<k<<" metres of Wood."<<endl;
    return 0;
}