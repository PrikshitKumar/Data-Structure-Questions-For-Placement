#include<bits/stdc++.h>
using namespace std;

bool checkStackPermutation(int ip[], int op[], int n) {
	stack<int> s;
	int j=0;
	for(int i=0; i<n; i++) {
		s.push(ip[i]);
		while(!s.empty() && s.top()==op[j]) {
    		s.pop();
	    	j++;
		}
	}
	
	if(s.empty()) return true;
	return false;
}

int main() {
	int input[] = {4,5,6,7,8};
	int output[] = {8,7,6,5,4};
	int n = 5;
    cout<<"Elements of Input Array are: "<<endl;
    for(int i=0; i<n; i++) {
        cout<<input[i]<<" ";
    }
    cout<<"\nElements of Output Array are: "<<endl;
    for(int i=0; i<n; i++) {
        cout<<output[i]<<" ";
    }
    cout<<"\nCheck whether the any permutation of the Input Array Elements match with the Output Array Elements or not? ";
	if (checkStackPermutation(input, output, n)) cout << "Yes";
	else cout << "Not Possible";
	return 0;
}