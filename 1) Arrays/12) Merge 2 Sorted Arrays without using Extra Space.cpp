#include<bits/stdc++.h>
using namespace std;

/* There could be two approaches for solving this problem: 
    i) by using Insertion Sort: Iterate through 1st Array and compare the elements of 2nd Array at the same 
        time, if the element of 2nd Array is smaller than the current element of 1st Array. Then, swap the 
        element. And, sort the 2nd Array before proceeding furthur.
        Eg: arr1[] = {1, 5, 9, 10, 15, 20}; and arr2[] = {2, 3, 8, 13};
        arr1[i] = 1, and arr2[j] = 2; As arr[i] < arr2[j] do nothing and increment in i by 1;
        arr1[i] = 5, and arr2[j] = 2; As arr[i] > arr2[j], swap the value and sort the 2nd Array.
        i.e., arr1[] = {1, 2, 9, 10, 15, 20}; and arr2[] = {5, 3, 8, 13};
        After Sort the 2nd Array: arr2[] = {3, 5, 8, 13};
        Again Repeat this process untill we reach the end of 1st Array.

    ii) This method is the optimal way to Sort the Arrays in O(1) space. The name of this method is "GAP" 
        method. In this method we take the summation of the length of both the Arrays and divide that value 
        by 2 and take the ceil value of that. like, if m=5, n=4 then, (5+4)/2 = 9/2 = 5 (ceil value).
        And this 5 is consider as GAP. So, gap = 5; means the gap between i and j must be 5.
        And, also for using this GAP method, we have to consider these two different arrays as a one array 
        with size m+n, i.e., 6+4 = 10.
        Eg: arr1[] = {1, 5, 9, 10, 15, 20}; and arr2[] = {2, 3, 8, 13}; and gap = (6+4)/2 = 5
        arr[i] = 1, and arr[j] = 20; As, arr[i] < arr[j] do nothing and increment in i by 1;
        arr[i] = 5, and arr[j] = 2; As, arr[i] > arr[j] swap the values of arr[i] and arr[j]; and increment
        the values of i by 1;
        Means, now arr1[] = {1, 2, 9, 10, 15, 20}; and arr2[] = {5, 3, 8, 13};
        now, arr[i] = 9, and arr[j] = 3; Repeat this Process untill we didn't reach the end of the 2nd Array.
        And, after this as "gap" = 5, we also have to repeat this Swap Process until gap not becomes 1. 
        The formula is same, i.e., first time, gap = (m+n)/2; after that gap = gap/2. And repeat the same 
        process until gap is not equals to 1.
        
    Youtube Link: https://youtu.be/hVl2b3bLzBw
*/

void swap(int &num1, int &num2) {
    int temp = num1; 
    num1 = num2; 
    num2 = temp;
}

void merge(vector<int> &vect1, vector<int> &vect2, int m, int n) {
    double gap = ceil(double(m+n)/2);
    for(gap; gap>0; gap = ceil(gap/2)) {
        for(int i=0; i<m+n; i++) {
            int j = i+gap;
            if(i < m && j < m) {
                if(vect1[i] > vect1[j]) {
                    swap(vect1[i], vect1[j]);
                }
            }
            else if(i < m && j >= m) {
                if(vect1[i] > vect2[j-m]) {
                    swap(vect1[i], vect2[j-m]);
                }
            }
            else if(i >= m && j < m+n) {
                if(vect2[i-m] > vect2[j-m]) {
                    swap(vect2[i-m], vect2[j-m]);
                }
            }
            else break; // When j > m+n;
        }
        // cout<<endl<<"Gap: "<<gap;
        // cout<<endl<<"Array 1: ";
        // for(int i=0; i<m; i++) cout<<vect1[i]<<" ";
        // cout<<endl<<"Array 2: ";
        // for(int i=0; i<n; i++) cout<<vect2[i]<<" ";
        if(gap == 1) break;
    }
}

int main() {
    int m, n;
    cout<<"Enter the size of Arrays: ";
    cin>>m>>n;
    vector<int> vect1(m, 0), vect2(n, 0);
    cout<<"Enter the values in 1st Array: ";
    for(int i=0; i<m; i++) cin>>vect1[i];
    cout<<"Enter the values in 2nd Array: ";
    for(int i=0; i<n; i++) cin>>vect2[i];
    cout<<"Elements of 1st Array before Merging: ";
    for(int i=0; i<m; i++) cout<<vect1[i]<<" ";
    cout<<"\nElements of 2nd Array before Merging: ";
    for(int i=0; i<n; i++) cout<<vect2[i]<<" ";
    merge(vect1, vect2, m, n);
    cout<<"\nElements of 1st Array after Merging: ";
    for(int i=0; i<m; i++) cout<<vect1[i]<<" ";
    cout<<"\nElements of 2nd Array after Merging: ";
    for(int i=0; i<n; i++) cout<<vect2[i]<<" ";
    return 0;
}