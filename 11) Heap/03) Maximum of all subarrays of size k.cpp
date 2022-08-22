#include<bits/stdc++.h>
using namespace std;

vector<int> findMax(int *arr, int size, int k) {
    vector<int> result;
    queue<int> q;
    for(int i=0; i<size; i++) {
        q.push(i);
        while(!q.empty() && arr[q.front()] < arr[i]) q.pop();
        if(q.empty()) result.push_back(-1);
        else if(i >= k-1) result.push_back(arr[q.front()]);
        while(!q.empty() && q.front() < (i-k)) q.pop();
    }
    return result;
}

int main() {
    int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    
    cout<<"Elements of the Array are: ";
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";

    vector<int> result = findMax(arr, size, k);
    
    cout<<"\nLargest Element in each window of Size "<<k<<" are: ";
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";
    
    return 0;
}