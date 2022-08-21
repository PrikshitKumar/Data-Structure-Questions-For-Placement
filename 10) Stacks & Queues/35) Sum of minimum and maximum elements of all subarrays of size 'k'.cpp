#include<bits/stdc++.h>
using namespace std;

int SumOfKsubArray(vector<int> &arr, int k) {
    int sum = 0;
    deque<int> s(k), g(k);
    for(int i=0; i<arr.size(); i++) {
        if(i >= k) {
            sum += (arr[s.front()] + arr[g.front()]);
        } 

        while(!s.empty() && s.front() <= i-k) s.pop_front();
        while(!g.empty() && g.front() <= i-k) g.pop_front();

        while(!s.empty() && arr[s.back()] >= arr[i]) s.pop_back();
        while(!g.empty() && arr[g.back()] <= arr[i]) g.pop_back();

        s.push_back(i);
        g.push_back(i);
    }
    sum += (arr[s.front()] + arr[g.front()]);
    return sum;
}

int main() {
    vector<int> vec {2, 5, -1, 7, -3, -1, -2};  
    int k = 4;
    cout<<"Elements of the Array are: ";
    for(int i=0; i<vec.size(); i++) {
        cout<<vec[i]<<" ";
    }
    cout<<"\nSum of minimum and maximum Elements of all Sub-Arrays of size "<<k<<" are: "<<SumOfKsubArray(vec, k);
    return 0;
}