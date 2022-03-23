#include<bits/stdc++.h>
using namespace std;

int kthSmallest(vector<vector<int>> mat, int k) {
    map<int, int> occurrences;
    set<int> values;
    for(int i=0; i<mat.size(); i++) {
        for(int j=0; j<mat[i].size(); j++) {
            values.insert(mat[i][j]);
            occurrences[mat[i][j]]++;
        }
    }
    set<int>::iterator it;
    for(it=values.begin(); it!=values.end(); it++) {
        k -= occurrences[*it];
        if(k<=0) return *it;
    }
    return -1;
}

int main() {
    vector<vector<int>> matrix {{16, 28, 60, 64},
                                {22, 41, 63, 91},
                                {27, 50, 87, 93},
                                {36, 78, 87, 94 }};
    int k = 7;
    cout<<"Elements of the Matrix are:\n";
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[i].size(); j++) {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<k<<"th Smallest Element in Matrix is: "<<kthSmallest(matrix, k);
    return 0;
}