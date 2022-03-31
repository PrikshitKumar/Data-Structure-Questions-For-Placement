#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll findSubarray(vector<ll> arr, int n ) {
    //code here
    ll count = 0, prevSum = 0;
    unordered_map<ll, ll> occurrences;
    occurrences[0]++;
    for(ll i=0; i<n; i++) {
        prevSum += arr[i];
        if(occurrences[prevSum]) {
            count += occurrences[prevSum]++;
        }
        else {
            occurrences[prevSum]++;
        }
    }
    return count;
}

int main() {
    vector<ll> arr {0,0,5,5,0,0};
    cout<<"Element of the Array are: ";
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    cout<<"\nSubarrays those sum is 0 are: "<<findSubarray(arr, arr.size());
    return 0;
}