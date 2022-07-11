#include<bits/stdc++.h>
using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n){
    vector<long long> ans(n);
    stack<long long> st;
    
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && st.top() < arr[i]) {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
    return ans;
}

int main() {
    vector<long long> arr{4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};
    cout<<"Elements of the Array are:\n";
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    arr = nextLargerElement(arr, arr.size());
    cout<<"\nNext Greater Element of the Array are:\n";
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    return 0;
}