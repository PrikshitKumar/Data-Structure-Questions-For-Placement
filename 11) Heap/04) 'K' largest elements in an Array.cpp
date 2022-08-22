#include<bits/stdc++.h>
using namespace std;

vector<int> kLargest(int arr[], int n, int k) {
    vector<int> ans;
    priority_queue<int> pq(arr, arr+n);
    while(k--) {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main() {
    int arr[] = {12, 5, 787, 1, 23};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    cout<<"Elements of the Array are: ";
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
    vector<int> result = kLargest(arr, size, k);
    cout<<"\n'"<<k<<"' Largest Elements are: ";
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";
    return 0;
}