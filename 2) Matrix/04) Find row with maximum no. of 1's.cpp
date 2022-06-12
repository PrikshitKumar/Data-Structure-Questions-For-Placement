#include<bits/stdc++.h>
using namespace std;

int countOnes(vector<int> v) {
    int count = 0;
    for(int i=0; i<v.size(); i++) {
        if(v[i] == 1) count++;
    }
    return count;
}
int rowWithMax1s(vector<vector<int> > arr) {
    int count = 0;
    int result = -1;
    for(int i=0; i<arr.size(); i++) {
        int t = countOnes(arr[i]);
        if(t > count) {
            count = t;
            result = i;
        }
    }
    return result;
}

int main() {
    vector<vector<int>> matrix {{0, 1, 1, 1},
                                {0, 0, 1, 1},
                                {1, 1, 1, 1},
                                {0, 0, 0, 0}};
    cout<<"Elements of the Matrix are: "<<endl;
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[i].size(); j++) {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"Row with maximum No. of 1's is (according to 0 based indexing): "<<rowWithMax1s(matrix);
    return 0;
}
