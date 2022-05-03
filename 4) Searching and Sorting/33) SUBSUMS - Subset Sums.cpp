#include<bits/stdc++.h>
using namespace std;

void findSubsetSum(int currentIndex, int sum, vector<int> &vec, int size, vector<int> &subsetSum) {
    if(currentIndex == size) {
        subsetSum.push_back(sum);
        return;
    }

    // Pick the Element
    findSubsetSum(currentIndex+1, sum+vec[currentIndex], vec, size, subsetSum);
    // Without Picking the Element
    findSubsetSum(currentIndex+1, sum, vec, size, subsetSum);
}

int findSubsets(int size, vector<int> &vec, int a, int b) {
    vector<int> subsetSum;
    int subsetSumCount = 0;
    findSubsetSum(0, 0, vec, size, subsetSum);
    for(int i=0; i<subsetSum.size(); i++) {
        if(subsetSum[i] >= a && subsetSum[i] <= b) {
            subsetSumCount++;
        }
    }
    return subsetSumCount;
}

int main() {
    int size = 3, a = -1, b = 2;
    vector<int> data {1, -2, 3};
    cout<<"Elements of the Array are: ";
    for(int i=0; i<size; i++) cout<<data[i]<<" ";
    cout<<"\nNumber of Subsets having sum between "<<a<<", "<<b<<" are: "<<findSubsets(size, data, a, b);
    return 0;
}