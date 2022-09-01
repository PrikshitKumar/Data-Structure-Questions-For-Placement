#include<bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n) {
    priority_queue<long long, vector<long long>, greater<int>> pq(arr, arr+n);
    long long ans = 0;
    
    while(pq.size() != 1) {
        long long val = pq.top();
        pq.pop();
        
        val += pq.top();
        pq.pop();
        
        ans += val;
        pq.push(val);
    }
    return ans;
}

int main() {
    long long arr[] = {4, 3, 2, 6};
    long long size = 4;
    cout<<"Elements of the Array are: ";
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
    cout<<"\nMinimum Cost to Connect all Ropes: "<<minCost(arr, size);
    return 0;
}