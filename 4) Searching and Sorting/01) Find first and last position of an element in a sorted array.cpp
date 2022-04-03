#include<bits/stdc++.h>
using namespace std;

int first(int arr[], int n, int x) {
    int low = 0, high = n - 1, res = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else {
            res = mid;
            high = mid - 1;
        }
    }
    return res;
}

int last(int arr[], int n, int x) {
    int low = 0, high = n - 1, res = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else {
            res = mid;
            low = mid + 1;
        }
    }
    return res;
}

vector<int> find(int arr[], int n , int x ) {
    // code here
    vector<int> result(2,0);
    result[0] = first(arr, n, x);
    result[1] = last(arr, n, x);
    return result;
}

int main() {
    int arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int size = sizeof(arr)/sizeof(arr[0]);
    int x = 5;
    cout<<"Elements of the Array are: ";
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
    vector<int> result = find(arr, size, x);
    cout<<"\nFirst Occurrence of "<<x<<" is at Index No.: "<<result[0];
    cout<<"\nLast Occurrence of "<<x<<" is at Index No.: "<<result[1];
    return 0;
}
