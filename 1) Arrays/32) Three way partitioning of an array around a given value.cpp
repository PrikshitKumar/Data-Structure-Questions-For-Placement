#include<bits/stdc++.h>
using namespace std;

void threeWayPartition(vector<int>& arr,int a, int b) {
    // code here 
    int start = 0;
    for(int i=start; i<arr.size(); i++) {
        if(arr[i] < a) {
            swap(arr[start++], arr[i]);
        }
    }
    for(int i=start; i<arr.size(); i++) {
        if(arr[i] >= a && arr[i] <= b) {
            swap(arr[start++], arr[i]);
        }
    }
    for(int i=start; i<arr.size(); i++) {
        if(arr[i] > a) {
            swap(arr[start++], arr[i]);
        }
    }
}

int main() {
    vector<int> arr {1, 4, 45, 6, 10, 19};
    int a = 4, b = 6;
    cout<<"Elements of an Array are: ";
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    vector<int> result {1, 4, 6, 45, 10, 19};
    cout<<"\nIs there any Three Way Partitioning of an Array arrount a given Range is aquired? ";
    threeWayPartition(arr, a, b);
    if(arr == result) cout<<"Yes";
    else cout<<"No";
    return 0;
}