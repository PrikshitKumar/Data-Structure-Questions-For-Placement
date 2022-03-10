#include<bits/stdc++.h>
using namespace std;

int getPairsCount(int arr[], int n, int sum) {
    unordered_map<int, int> map;
    int result = 0;
    for(int i=0; i<n; i++) {
        int temp = sum - arr[i];
        if(map[temp]) {
            result += map[temp];
        }
        map[arr[i]]++;
    }
    return result;
}

int main() {
    int arr[] = {1, 1, 1, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    cout<<"Elements of the Array are: ";
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
    cout<<"\nNumber of Pairs who Sum is equal to "<<k<<" : "<<getPairsCount(arr, size, k);
    return 0;
}