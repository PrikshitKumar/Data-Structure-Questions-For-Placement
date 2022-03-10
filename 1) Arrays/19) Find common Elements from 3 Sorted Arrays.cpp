#include<bits/stdc++.h>
using namespace std;

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3) {
    set<int> result;
    int i=0, j=0, k=0;
    while(i<n1 && j<n2 && k<n3) {
        if((A[i] == B[j]) && (B[j] == C[k])) { 
            result.insert(A[i]);
            i++; j++; k++;
        }
        else if(A[i] < B[j]) {
            i++;
        }
        else if(B[j] < C[k]) {
            j++;
        }
        else {
            k++;
        }
    }
    vector<int> vec(result.begin(), result.end());
    return vec;
}

int main() {
    int arr1[] = {1, 5, 10, 20, 40, 80};
    int arr2[] = {6, 7, 20, 80, 100};
    int arr3[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int length1 = sizeof(arr1)/sizeof(arr1[0]);
    int length2 = sizeof(arr2)/sizeof(arr2[0]);
    int length3 = sizeof(arr3)/sizeof(arr3[0]);
    cout<<"Elements of First Array: ";
    for(int i=0; i<length1; i++) cout<<arr1[i]<<" ";
    cout<<"\nElements of Second Array: ";
    for(int i=0; i<length2; i++) cout<<arr2[i]<<" ";
    cout<<"\nElements of Third Array: ";
    for(int i=0; i<length3; i++) cout<<arr3[i]<<" ";
    vector<int> result = commonElements(arr1, arr2, arr3, length1, length2, length3);
    cout<<"\nCommon Elements in all the Sorted Arrays are: ";
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";
    return 0;
}