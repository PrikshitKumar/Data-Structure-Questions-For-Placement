#include<bits/stdc++.h>
using namespace std;

// Youtube Link: https://youtu.be/NTop3VTjmxk
int findMedian(int arr1[], int arr2[], int length1, int length2) {
    int low = 0, high = length1;
    while(low <= high) {
        int cut1 = (low+high)/2;
        int cut2 = (length1+length2+1)/2 - cut1;

        int left1 = (cut1 == 0) ? INT_MIN : arr1[cut1-1];
        int left2 = (cut2 == 0) ? INT_MIN: arr2[cut2-1];

        int right1 = (cut1 == 0) ? INT_MAX : arr1[cut1];
        int right2 = (cut2 == 0) ? INT_MAX : arr2[cut2];

        if(left1 <= right2 && left2 <= right1) {
            if((length1+length2)%2 == 0) {
                return (max(left1, left2) + min(right1, right2)) / 2;
            }
            else {
                return max(left1, left2);
            }
        }
        else if(left1 > right2) {
            high = cut1-1;
        }
        else {
            low = cut1+1;
        }
    }
    return 0;
}

int main() {
    int arr1[] = {};
    int arr2[] = {};
    int length1 = sizeof(arr1)/sizeof(arr1[0]);
    int length2 = sizeof(arr2)/sizeof(arr2[0]);
    cout<<"Elements of an Array 1 are: ";
    for(int i=0; i<length1; i++) cout<<arr1[i]<<" ";
    cout<<"\nElements of an Array 2 are: ";
    for(int i=0; i<length2; i++) cout<<arr2[i]<<" ";
    cout<<"\nMedian of 2 Sorted Arrays of Different Size is: ";
    if(length1 < length2) findMedian(arr1, arr2, length1, length2);
    else findMedian(arr2, arr1, length2, length1);
    return 0;
}