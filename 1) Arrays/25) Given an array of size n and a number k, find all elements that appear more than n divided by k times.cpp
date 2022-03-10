#include<bits/stdc++.h>
using namespace std;

vector<int> occurences(int arr[], int length, int k) {
    unordered_map<int, int> map;
    set<int> result;
    for(int i=0; i<length; i++) {
        map[arr[i]]++;
        if(map[arr[i]] > k) {
            result.insert(arr[i]);
        }
    }
    vector<int> vec(result.begin(), result.end());
    return vec;
}

int main() {
    int arr[] = {3, 1, 2, 2, 1, 2, 3, 3};
    int k = 4;
    int length = sizeof(arr)/sizeof(arr[0]);
    cout<<"Elements of the Array are: ";
    for(int i=0; i<length; i++) cout<<arr[i]<<" ";
    cout<<"\nList of Elements those appears more than "<<length/k<<" times are: ";
    vector<int> result = occurences(arr, length, length/k);
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";
    return 0;
}