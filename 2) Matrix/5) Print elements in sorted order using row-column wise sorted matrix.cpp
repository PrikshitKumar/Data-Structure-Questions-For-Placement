#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
    // code here
    vector<int> temp;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            temp.push_back(Mat[i][j]);
        }
    }
    sort(temp.begin(), temp.end());
    int itr = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            Mat[i][j] = temp[itr++];
        }
    }
    return Mat;
}

int main() {
    vector<vector<int>> matrix {{10,20,30,40},
                                {15,25,35,45}, 
                                {27,29,37,48}, 
                                {32,33,39,50}};
    int length = matrix.size();
    cout<<"Elements of the Matrix are: "<<endl;
    for(int i=0; i<length; i++) {
        for(int j=0; j<length; j++) {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"After Sorting, the Elements of the Matrix are: ";
    matrix = sortedMatrix(length, matrix);
    
    cout<<"Elements of the Matrix are: "<<endl;
    for(int i=0; i<length; i++) {
        for(int j=0; j<length; j++) {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}