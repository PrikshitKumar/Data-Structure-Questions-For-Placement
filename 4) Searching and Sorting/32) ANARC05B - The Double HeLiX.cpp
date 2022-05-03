#include<bits/stdc++.h>
using namespace std;

vector<int> findCommonElements(vector<int> &data1, vector<int> &data2) {
    unordered_map<int, int> temp;
    vector<int> commonElements;
    for(int i=0; i<data1.size(); i++) temp[data1[i]]++;
    for(int i=0; i<data2.size(); i++) {
        if(temp[data2[i]]) {
            commonElements.push_back(data2[i]);
            temp[data2[i]]--;
        }
    }
    return commonElements;
}

int findMax(vector<int> &data1, vector<int> &data2) {
    vector<int> commonElements = findCommonElements(data1, data2);
    int sum1 = 0, sum2 = 0, result = 0;
    if(commonElements.size() == 0) {
        for(int i=0; i<data1.size(); i++) sum1 += data1[i];
        for(int i=0; i<data2.size(); i++) sum2 += data2[i];
        result = max(sum1, sum2);
    }
    else {
        int it1 = 0, it2 = 0;
        for(int i=0; i<commonElements.size(); i++) {
            while(data1[it1] != commonElements[i]) sum1 += data1[it1++];
            while(data2[it2] != commonElements[i]) sum2 += data2[it2++];
            result += max(sum1, sum2);
            sum1 = sum2 = 0;
        }

        // Add Remaining Elements
        while(it1 < data1.size()) sum1 += data1[it1++];
        while(it2 < data2.size()) sum2 += data2[it2++];
        result += max(sum1, sum2);
    }
    return result;
}

int main() {
/* 
    Input Format: n, v1 v2 ... vn
    Input: 
        13 3 5 7 9 20 25 30 40 55 56 57 60 62
        11 1 4 7 11 14 25 44 47 55 57 100
        4 -5 100 1000 1005
        3 -12 1000 1001
    Output: 
        450
        2100
*/
    // int m = 13;
    // vector<int> data1 {3, 5, 7, 9, 20, 25, 30, 40, 55, 56, 57, 60, 62};
    // int n = 11;
    // vector<int> data2 {1, 4, 7, 11, 14, 25, 44, 47, 55, 57, 100};
    int m = 4;
    vector<int> data1 {-5, 100, 1000, 1005};
    int n = 3;
    vector<int> data2 {-12, 1000, 1001};
    cout<<"Elements of the 1st Array are:\n";
    for(int i=0; i<m; i++) cout<<data1[i]<<" ";
    cout<<"\nElements of the 2st Array are:\n";
    for(int i=0; i<n; i++) cout<<data2[i]<<" ";
    cout<<"\nMaximum Result from given Data is: "<<findMax(data1, data2);
    return 0;
}