#include<bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int N) {
    set<int> hashSet;
    for(int i=0; i<N; i++) {
        hashSet.insert(arr[i]);
    }
    int result = 0;
    for(int i=0; i<N; i++) {
        int temp = arr[i];
        if(hashSet.count(temp-1) == 0) {
            int count = 0;
            while(hashSet.count(temp++) != 0) {
                count++;
            }
            result = count>result ? count: result;
        }
    }
    return result;
}

int main() {
    int arr[] = {2, 6, 1, 9, 4, 5, 3};
    int length = sizeof(arr)/sizeof(arr[0]);
    cout<<"Elements of the Array are: ";
    for(int i=0; i<length; i++) cout<<arr[i]<<" ";
    cout<<"\nThe Length of Longest Consecutive SubSequence is: "<<findLongestConseqSubseq(arr, length);
    return 0;
}