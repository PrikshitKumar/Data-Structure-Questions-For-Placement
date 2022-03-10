#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int rows = matrix.size(), columns = matrix[0].size();
    int start = 0, end = matrix[0].size()-1;
    while(matrix[start][end] < target && start < rows-1) {
        start++;
    }
    if(start < rows) {
        for(int i=0; i<=end; i++) {
            if(matrix[start][i] == target)
                return true;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> matrix {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int numberOfRows = matrix.size();
    int numberOfColumns = matrix[0].size();
    cout<<"Elements of the Matrix are: "<<endl;
    for(int i=0; i<numberOfRows; i++) {
        for(int j=0; j<numberOfColumns; j++) {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    int target;
    cout<<"Enter any Number that you want to search in Matrix: ";
    cin>>target;
    cout<<"Is "<<target<<" present in Matrix? "<<searchMatrix(matrix, target);
    return 0;
}