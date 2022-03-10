#include<bits/stdc++.h>
using namespace std;

void unionOfArrays(int arr1[], int arr2[], int length1, int length2) {
    vector<int> result;
    for(int i=0; i<length1; i++) {
        bool duplicate = false;
        for(int j=0; j<result.size(); j++) {
            if(result[j] == arr1[i]) {
                duplicate = true;
                break;
            }
        }
        if(!duplicate) {
            result.push_back(arr1[i]);
        }
    }

    for(int i=0; i<length2; i++) {
        bool duplicate = false;
        for(int j=0; j<result.size(); j++) {
            if(result[j] == arr2[i]) {
                duplicate = true;
                break;
            }
        }
        if(!duplicate) {
            result.push_back(arr2[i]);
        }
    }

    cout<<"\nUnion of the Arrays is: ";
    for(int i=0; i<result.size(); i++) {
        cout<<result[i]<<" ";
    }
}

void intersectionOfArrays(int arr1[], int arr2[], int length1, int length2) {
    vector<int> result;
    for(int i=0; i<length1; i++) {
        bool found = false;
        for(int j=0; j<length2; j++) {
            if(arr1[i] == arr2[j]) {
                found = true;
                break;
            }
        }
        if(found) {
            result.push_back(arr1[i]);
        }
    }
    cout<<"\nIntersection of the Arrays is: ";
    for(int i=0; i<result.size(); i++) {
        cout<<result[i]<<" ";
    }
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 7, 3};
    int length1 = sizeof(arr1)/sizeof(arr1[0]);
    int length2 = sizeof(arr2)/sizeof(arr2[0]);
    cout<<"The elements of Array_1 are: ";
    for(int i=0; i<length1; i++) {
        cout<<arr1[i]<<" ";
    }
    cout<<"\nThe elements of Array_2 are: ";
    for(int i=0; i<length2; i++) {
        cout<<arr2[i]<<" ";
    }
    unionOfArrays(arr1, arr2, length1, length2);
    intersectionOfArrays(arr1, arr2, length1, length2);
    return 0;
}