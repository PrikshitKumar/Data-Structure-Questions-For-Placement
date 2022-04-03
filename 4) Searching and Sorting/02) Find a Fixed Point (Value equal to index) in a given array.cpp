#include<bits/stdc++.h>
using namespace std;

vector<int> valueEqualToIndex(int arr[], int n) {
    // code here
    vector<int> result;
    for(int i=0; i<n; i++) {
        if(arr[i] == i+1) result.push_back(arr[i]); 
    }
    return result;
}

int main() {
    int arr[] = {15, 2, 45, 12, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Elements of the Array are: ";
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
    cout<<"\nValues equal to the Indexes are: ";
    vector<int> result = valueEqualToIndex(arr, size);
    if(result.size() == 0) cout<<"-1";
    else for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";
    return 0;
}
