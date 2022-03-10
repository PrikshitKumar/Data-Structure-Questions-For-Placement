#include<bits/stdc++.h>
using namespace std;

bool find3Numbers(int arr[], int n, int X) {
    sort(arr, arr+n);
    for(int i=0; i<n-2; i++) {
        int left = i+1;
        int right = n-1;
        while(left < right) {
            if(arr[i]+arr[left]+arr[right] == X) {
                return 1;
            }
            else if(arr[i]+arr[left]+arr[right] < X) {
                left++;
            }
            else right--;
        }
    }
    return 0;
}

int main() {
    int arr[] = {1, 4, 45, 6, 10, 8};
    int length = sizeof(arr)/sizeof(arr[0]);
    int X = 13;
    cout<<"Elements of the Array are: ";
    for(int i=0; i<length; i++) cout<<arr[i]<<" ";
    cout<<"\nIs there any 3 numbers those equals to 'X' after summation? "<<find3Numbers(arr, length, X);
    return 0;
}