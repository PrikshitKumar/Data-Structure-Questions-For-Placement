#include<bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) {
    // code here 
    vector<int> result;
    int direction = 0, count = 0;
    int rowStart = 0, rowEnd = r, colStart = 0, colEnd = c;
    while(count < r*c) {
        if(direction == 0) {
            for(int i=colStart; i<colEnd; i++) {
                result.push_back(matrix[rowStart][i]);
                count++;
            }
            rowStart++;
            direction = 1;
        }
        else if(direction == 1) {
            for(int i=rowStart; i<rowEnd; i++) {
                result.push_back(matrix[i][colEnd-1]);
                count++;
            }
            colEnd--;
            direction = 2;
        }
        else if(direction == 2) {
            for(int i=colEnd-1; i>=colStart; i--) {
                result.push_back(matrix[rowEnd-1][i]);
                count++;
            }
            rowEnd--;
            direction = 3;
        }
        else if(direction == 3) {
            for(int i=rowEnd-1; i>=rowStart; i--) {
                result.push_back(matrix[i][colStart]);
                count++;
            }
            colStart++;
            direction = 0;
        }
    }
    return result;
}

int main() {
    vector<vector<int>> matrix {{1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12},
                                {13, 14, 15,16}};
    int numberOfRows = matrix.size();
    int numberOfColumns = matrix[0].size();
    cout<<"The Elements of the Matrix are: "<<endl;
    for(int i=0; i<numberOfRows; i++) {
        for(int j=0; j<numberOfColumns; j++) {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    vector<int> result = spirallyTraverse(matrix, numberOfRows, numberOfColumns);
    cout<<"\nSpiral Traversing of the Matrix is: "<<endl;
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";
    return 0;
}
