#include<bits/stdc++.h>
using namespace std;

int kthElement(int arr1[], int arr2[], int n, int m, int k) {
	if(n>m) {
		return kthElement(arr2, arr1, m, n, k);
	}
	
	int low = max(0, k-m), high = min(k, n);
	while(low <= high) {
		int cut1 = (low+high) >> 1;
		int cut2 = k-cut1;
		int l1 = cut1==0 ? INT_MIN : arr1[cut1-1];
		int l2 = cut2 == 0 ? INT_MIN : arr2[cut2-1];
		int r1 = cut1 == n ? INT_MAX : arr1[cut1];
		int r2 = cut2 == m ? INT_MAX : arr2[cut2];
		
		if(l1 <= r2 && l2 <= r1) {
			return max(l1, l2);
		} 
		else if(l1 > r2) {
			high = cut1 - 1;
		}
		else {
			low = cut1 + 1;
		}
	}
	return 1;
}

int main() {
	int arr1[] = {2, 3, 6, 7, 9};
	int length1 = sizeof(arr1)/sizeof(arr1[0]);
	int arr2[] = {1, 4, 8, 10};
	int length2 = sizeof(arr2)/sizeof(arr2[0]);
	int k = 5;
	cout<<"Elements of the Array1 are: ";
	for(int i=0; i<length1; i++) cout<<arr1[i]<<" ";
	cout<<"\nElements of the Array2 are: ";
	for(int i=0; i<length2; i++) cout<<arr2[i]<<" ";
	cout<<endl<<k<<"th Smallest Element is: "<<kthElement(arr1, arr2, length1, length2, k);	
	return 0;
}