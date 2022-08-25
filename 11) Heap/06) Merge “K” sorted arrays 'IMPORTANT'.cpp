#include<bits/stdc++.h>
using namespace std;

class Data {
public: 
    int val, arrayPos, valPos;
    Data(int val, int arrayPos, int valPos) {
        this->val = val;
        this->arrayPos = arrayPos;
        this->valPos = valPos;
    }
};

struct comparator {
    bool operator()(Data &d1, Data &d2) {
        return d1.val > d2.val;
    }
};

vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
    vector<int> result;
    priority_queue<Data, vector<Data>, comparator> pq;
    for(int i=0; i<K; i++) {
        Data dt(arr[i][0], i, 0);
        pq.push(dt);
    }
    
    while(!pq.empty()) {
        Data curr = pq.top();
        pq.pop();
        result.push_back(curr.val);
        int arrayPos = curr.arrayPos;
        int valPos = curr.valPos;
        if(valPos+1 < arr[arrayPos].size()) {
            Data dt(arr[arrayPos][valPos+1], arrayPos, valPos+1);
            pq.push(dt);
        }
    }
    
    return result;
}

int main() {
    vector<vector<int>> vec {{1,2,3,4},{2,2,3,4},{5,5,6,6},{7,8,9,9}};
    int k = 4;  // size of vec (4*4)
    cout<<"Elements of the Array are:\n";
    for(int i=0; i<k; i++) {
        for(int j=0; j<k; j++) {
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"After Merging the Values of '"<<k<<"' vectors:";
    vector<int> result = mergeKArrays(vec, k);
    for(int i=0; i<result.size(); i++) {
        if(i%k == 0) cout<<endl;
        cout<<result[i]<<" ";
    }
    return 0;
}