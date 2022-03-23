#include<bits/stdc++.h>
using namespace std;

void commonElements(vector<vector<int>> matrix) {
    map<int, int> values;
    for(int i=0; i<matrix.size(); i++) {
        set<int> temp;
        for(int j=0; j<matrix[i].size(); j++) {
            temp.insert(matrix[i][j]);
        }
        set<int>::iterator it;
        for(it=temp.begin(); it!=temp.end(); it++) {
            values[*it]++;
        }
    }
    cout<<"Common Elements in the Matrix are: ";
    map<int, int>::iterator it;
    for(it=values.begin(); it!=values.end(); it++) {
        if(it->second >= matrix.size()) {
            cout<<it->first<<" ";
        }
    }
}

int main() {
    vector<vector<int>> matrix {{1, 2, 1, 4, 8},
                                {3, 7, 8, 5, 1},
                                {8, 7, 7, 3, 1},
                                {8, 1, 2, 7, 9}};
    cout<<"Elements of the Matrix are:\n";
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[i].size(); j++) {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    commonElements(matrix);
    return 0;
}