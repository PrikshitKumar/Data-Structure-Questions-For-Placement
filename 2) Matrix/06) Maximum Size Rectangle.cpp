#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<vector<int>> &matrix) {
    
}


/*int calculateMax(vector<int> arr) {
    int result = 0;
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] != 0) {
            int count = 0, j = i;
            while(arr[j] <= arr[i] && arr[j] != 0) {
                count++;
                j++;
            }
            int temp = arr[i]*count;
            if(result < temp) result = temp;
        }
    }
    return result;
}

int maxArea(vector<vector<int>> &matrix) {
    int maxSize = 0;
    vector<int> currentRow(matrix.size(), 0);
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[i].size(); j++) {
            if(matrix[i][j] == 1) {
                currentRow[i] += matrix[i][j];
            }
            else {
                currentRow[i] = 0;
            }
        }
        int temp = calculateMax(currentRow);
        if(maxSize < temp) maxSize = temp;
    }
    return maxSize;
}
*/
int main() {
    vector<vector<int>> matrix {{0, 1, 1, 0},
                                {1, 1, 1, 1},
                                {1, 1, 1, 1},
                                {1, 1, 0, 0}};
    cout<<"Elements of the Matrix are: "<<endl;
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[i].size(); j++) {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"Maximum Size of Rectangle formed is: "<<maxArea(matrix);
    return 0;
}
