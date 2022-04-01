#include<bits/stdc++.h>
using namespace std;

vector<int> findStrength(vector<int> &arr, int pow) {
	vector<int> result(2, 0);
	int start = 0;
	while(start < arr.size() && arr[start] <= pow) {
		result[1] += arr[start];
		result[0] = ++start;
	}
	return result;
}
 
int main() {
/*  Input: 
    7
    1 2 3 4 5 6 7
    3
    3
    10
    2

    Output: 
    3 6
    7 28
    2 3
*/
	int n;
	cin>>n;
	vector<int> arr(n, 0);
	for(int i=0; i<n; i++) cin>>arr[i];
	sort(arr.begin(), arr.end());
	int q;
	cin>>q;
	for(int i=0; i<q; i++) {
		int pow;
		cin>>pow;
		vector<int> result = findStrength(arr, pow);
		cout<<result[0]<<" "<<result[1]<<endl;
	}
	return 0;
}