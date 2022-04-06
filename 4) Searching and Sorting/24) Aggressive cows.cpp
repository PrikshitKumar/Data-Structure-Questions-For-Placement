#include<bits/stdc++.h>
using namespace std;

bool canPlaceCows(int arr[], int length, int k, int distance) {
    int currCowPosition = arr[0], count = 1;
    for(int i=0; i<length; i++) {
        if(arr[i]-currCowPosition >= distance) {
            count++;
            currCowPosition = arr[i];
        }
        if(count == k) return true;
    }
    return false;
}

int chkPlace(int arr[], int length, int k) {
    int low = arr[0], high = arr[length-1]-arr[0];
    int result = -1;
    while(low <= high) {
        int mid = (low+high) >> 1;
        if(canPlaceCows(arr, length, k, mid)) {
            result = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    return result;
}

int main() {
/*  
    Input:  
        t = 1
        n = 5, c = 3
        arr[] = {1, 2, 8, 4, 9}

    Output: 3
*/

    int t;
    cin>>t;
    while(t--) {
        int n, c;
        cin>>n>>c;
        int arr[n] = {0};
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }
        sort(arr, arr+n);
        for(int i=0; i<n; i++)
            cout<<"Stall is present at Position Number: "<<arr[i]<<endl;
        cout<<"Maximum Distance between Cows is: "<<chkPlace(arr, n, c)<<endl;
    }
    return 0;
}