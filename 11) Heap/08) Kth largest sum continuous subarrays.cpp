#include<bits/stdc++.h>
using namespace std;

int kthLargestSum(int arr[], int size, int k) {
    vector<int> vec;
    for(int i=0; i<size; i++) {
        int sum = 0;
        for(int j=i; j<size; j++) {
            sum += arr[j];
            vec.push_back(sum);
        }
    }
    sort(vec.begin(), vec.end(), greater<int>());
    return vec[k-1];
}

int main() {
    int arr[] = {20, -5, -1}, k = 3;
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Elements of the Array are: ";
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
    cout<<"\n'"<<k<<"' th Largest Sum from Continuous SubArrays is: "<<kthLargestSum(arr, size, k);
    return 0;
}