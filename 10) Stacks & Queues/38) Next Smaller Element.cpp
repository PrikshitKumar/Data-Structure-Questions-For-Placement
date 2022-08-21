#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(int arr[], int len) {
    vector<int> result(len, 0);
    stack<int> st;
    for(int i=len-1; i>=0; i--) {
        while(!st.empty() && st.top() > arr[i]) st.pop();
        if(st.empty()) result[i] = -1;
        else result[i] = st.top();
        st.push(arr[i]);
    }
    return result;
}

int main() {
    int arr[] = {4, 8, 5, 2, 25};
    // int arr[] = {11, 13, 21, 3};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<"Elements of the Array are: ";
    for(int i=0; i<len; i++) {
        cout<<arr[i]<<" ";
    }
    vector<int> res = nextSmallerElement(arr, len);
    // len = sizeof(res)/sizeof(res[0]);
    cout<<"\nNext Smaller Elements for each 'ith' Element is: ";
    for(int i=0; i<res.size(); i++) {
        cout<<res[i]<<" ";
    }
    return 0;
}