#include<bits/stdc++.h>
using namespace std;

int countSmallerThanEqualsToMid(vector<int> v, int val) {
    int low = 0, high = v.size()-1;
    while(low <= high) {
        int mid = (low+high)/2;
        if(v[mid] <= val) low = mid+1;
        else high = mid-1;
    }
    return low;
}
int getMedian(vector<vector<int>> &matrix){
    // code here
    int low = 1, high = 1e9;
    int rowSize = matrix.size();
    int colSize = matrix[0].size();
    while(low <= high) {
        int mid = (low+high)/2;
        int count = 0;
        for(int i=0; i<rowSize; i++) {
            count += countSmallerThanEqualsToMid(matrix[i], mid);
        } 
        if(count <= (rowSize*colSize)/2) low = mid+1;
        else high = mid-1;
    }
    return low;
}

int main() {
    vector<vector<int>> matrix {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    cout<<"Elements of an Matrix are: "<<endl;
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[0].size(); j++) {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"Median of the given Matrix is: "<<getMedian(matrix);
    return 0;
}