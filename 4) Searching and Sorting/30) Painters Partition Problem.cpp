#include<bits/stdc++.h>
using namespace std;

bool paintersAllocation(vector<int> &arr, int max, int p) {
    int painters = 1, temp = 0;
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] > max) return false;
        if((temp+arr[i]) > max) {
            temp = arr[i];
            painters++;
        }
        else temp += arr[i];
    }
    if(painters <= p) return true;
    return false;
}

int paint(int A, int B, vector<int> &C) {
    int low = INT_MIN, high = 0;
    int result = -1;
    for(int i=0; i<C.size(); i++) {
        high += C[i];
        low = (C[i] < low) ? C[i] : low; 
    }
    while(low <= high) {
        int mid = (low + high) >> 1;
        if(paintersAllocation(C, mid, A)) {
            result = mid*B;
            high = mid-1;
        }
        else low = mid+1;
    }
    return result % 10000003;
}

int main() {
    int A = 10, B = 1;
    vector<int> C {1, 8, 11, 3};
    cout<<"Task for Painters to paint following units of Wall: ";
    for(int i=0; i<C.size(); i++) cout<<C[i]<<" ";
    cout<<endl<<"Total Time Taken: "<<paint(A, B, C);   
    return 0;
}