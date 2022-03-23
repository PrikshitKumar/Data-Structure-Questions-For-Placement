#include<bits/stdc++.h>
using namespace std;

void rotationBy90(vector<vector<int>> &matrix) {
    for(int i=0; i<matrix.size(); i++) {
        for(int j=matrix.size()-1; j>=0; j--) {
            cout<<matrix[j][i]<<"\t";
        }
        cout<<endl;
    }
}

int main() {
    vector<vector<int>> matrix {{ 1, 2, 3, 4},
                                { 5, 6, 7, 8},
                                { 9, 10, 11, 12},
                                { 13, 14, 15, 16}};
    cout<<"Before Rotation: "<<endl;
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[i].size(); j++) {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\nAfter Rotation:\n";
    rotationBy90(matrix);
    return 0;
}