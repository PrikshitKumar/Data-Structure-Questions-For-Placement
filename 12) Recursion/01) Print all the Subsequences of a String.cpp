#include<bits/stdc++.h>
using namespace std;

void printSubsequences(int arr[], int len, int curr, vector<int> &vec) {
    if(curr >= len) {
        for(int i=0; i<vec.size(); i++) cout<<vec[i];
        if(vec.size() == 0) cout<<"{ }";
        cout<<endl;
        return;
    }
    vec.push_back(arr[curr]);
    printSubsequences(arr, len, curr+1, vec);   // Select Current Element
    vec.pop_back();
    printSubsequences(arr, len, curr+1, vec);   // Without Selecting Current Element
}

int main() {
    int arr[] = {1, 2, 1};
    int len = 3;
    vector<int> vec;
    printSubsequences(arr, len, 0, vec);
    return 0;
}