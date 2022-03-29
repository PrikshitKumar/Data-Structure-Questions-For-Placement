#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll countTriplets(ll arr[], int n, ll target) {
    ll result = 0;
    sort(arr, arr+n);
    for(ll i=0; i<n; i++) {
        ll start = i+1, end = n-1;
        while(start < end) {
            if(arr[i]+arr[start]+arr[end] < target) {
                result += end-start;
                start++;
            }
            else end--;
        }
    }
    return result;
}

int main() {
    ll arr[] = {5, 1, 3, 4, 7};
    ll size = sizeof(arr)/sizeof(arr[0]);
    ll target = 12;
    cout<<"Elements of the Array are: ";
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
    cout<<"\nCount of Triplets whose sum is smaller than "<<target<<" are: "<<countTriplets(arr, size, target);
    return 0;
}