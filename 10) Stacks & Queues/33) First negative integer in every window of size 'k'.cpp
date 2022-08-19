#include<bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    queue<long long> q;
    vector<long long> ans;

    for(int i=0; i<K-1; i++) {
        if(A[i] < 0) q.push(A[i]);
    }

    for(int i=K-1; i<N; i++) {
        if(A[i] < 0) q.push(A[i]);
        if(!q.empty()) {
            ans.push_back(q.front());
            if(q.front() == A[i-K+1]) q.pop();
        }
        else ans.push_back(0);
    }

    return ans;
}

int main() {
    long long int arr[] = {-8, 2, 3, -6, 10};
    long long int k = 2, len = 5;
    cout<<"Values of the Vector are: ";
    for(int i=0; i<len; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n1st negative value in specified Window of Size "<<k<<" are: ";
    vector<long long> ans = printFirstNegativeInteger(arr, len, k);
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    return 0;
}