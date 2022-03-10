#include<bits/stdc++.h>
using namespace std;

string isSubset(int arr1[], int arr2[], int length1, int length2) {
    unordered_map<int, int> temp;
    for(int i=0; i<length1; i++) {
        temp[arr1[i]]++;
    }
    for(int i=0; i<length2; i++) {
        if(!temp[arr2[i]]) {
            return "No";
        }
    }
    return "Yes";
}

int main() {
    int arr1[] = {11, 1, 13, 21, 3, 7};
    int arr2[] = {11, 3, 7, 1};
    int length1 = sizeof(arr1)/sizeof(arr1[0]);
    int length2 = sizeof(arr2)/sizeof(arr2[0]);
    cout<<"Elements of the 1st Array are: ";
    for(int i=0; i<length1; i++) cout<<arr1[i]<<" ";
    cout<<"\nElements of the 2nd Array are: ";
    for(int i=0; i<length2; i++) cout<<arr2[i]<<" ";
    cout<<"\n2nd Array is a Subset of 1st Array? "<<isSubset(arr1, arr2, length1, length2);
    return 0;
}