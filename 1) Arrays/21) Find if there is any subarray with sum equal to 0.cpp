#include<bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[], int n)
{
    unordered_map<int, int> map;
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
        if(arr[i] == 0 || map[sum] || sum==0) {
            return true;
        }
        map[sum]++;
    }
    return false;
}

int main() {
    int arr[] = {4, 2, -3, 1, 6};
    int length = sizeof(arr)/sizeof(arr[0]);
    cout<<"Elements of the Array are: ";
    for(int i=0; i<length; i++) cout<<arr[i]<<" ";
    cout<<"\nIs there any Subarray with Sum = 0? ";
    string result = (subArrayExists(arr, length)==1)?"Yes":"No";
    cout<<result;
    return 0;
}