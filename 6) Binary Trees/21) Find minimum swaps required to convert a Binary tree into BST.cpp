#include<bits/stdc++.h>
using namespace std;

void inorderTraversal(int arr[], vector<int> &v, int size, int index) {
	if(index >= size) return;
	inorderTraversal(arr, v, size, (2*index)+1);
	v.push_back(arr[index]);
	inorderTraversal(arr, v, size, (2*index)+2);
}

/* Intution: The idea is to use the fact that inorder traversal of Binary Search Tree is in increasing 
    order of their value. So, find the inorder traversal of the Binary Tree and store it in the array 
    and try to sort the array. The minimum number of swap required to get the array sorted will be the 
    answer. 
    Time Complexity: O(nlogn).
*/
int minSwaps(vector<int> &v) {
	vector<pair<int,int>> temp(v.size());
	int ans = 0;
	for(int i=0; i<v.size(); i++) {
		temp[i].first = v[i]; 
        temp[i].second = i;
    }
	sort(temp.begin(), temp.end());
	for(int i=0; i<temp.size(); i++) {
		if(i == temp[i].second) continue;
		else {
			swap(temp[i].first, temp[temp[i].second].first);
			swap(temp[i].second, temp[temp[i].second].second);
		}
		
		if(i != temp[i].second) i--; // Chk whether the swaped element index is in sorted Order or not!
		ans++;
	}
	return ans;
}

int main() {
	int arr[] = {5, 6, 7, 8, 9, 10, 11};
	int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Complete Tree Level-Order Traversal:\n";
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
	vector<int> v;
	inorderTraversal(arr, v, size, 0);
    cout<<"\nPreOrder Traversal of Complete Tree is:\n";
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<"\nMinimum Number of Swaps to convert Binary Tree to Binary Search Tree: ";
	cout<<minSwaps(v)<<endl;
    return 0;
}