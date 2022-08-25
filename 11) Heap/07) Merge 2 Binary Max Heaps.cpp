#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &vec, int size, int curr) {
    int largest = curr;
    int left = (2*curr) + 1;
    int right = (2*curr) + 2;
    
    if(left < size && vec[largest] < vec[left]) {
        largest = left;
    }
    if(right < size && vec[largest] < vec[right]) {
        largest = right;
    }
    
    if(curr != largest) {
        swap(vec[largest], vec[curr]);
        heapify(vec, size, largest);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    vector<int> result;
    for(int i=0; i<n; i++) result.push_back(a[i]);
    for(int i=0; i<m; i++) result.push_back(b[i]);

    for(int i=(result.size()/2)-1; i>=0; i--) {
        heapify(result, result.size(), i);
    }
    return result;
}

int main() {
    int n = 4, m = 3;
    vector<int> a {10, 5, 6, 2};
    vector<int> b {12, 7, 9};
    cout<<"Elements of Array 1: ";
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<"\nElements of Array 2: ";
    for(int i=0; i<m; i++) cout<<b[i]<<" ";
    
    vector<int> result = mergeHeaps(a, b, n, m);
    cout<<"\nData of Array after merging: ";
    for(int i=0; i<n+m; i++) cout<<result[i]<<" ";
    
    return 0;
}