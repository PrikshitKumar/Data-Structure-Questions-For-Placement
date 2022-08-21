#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

int findSumSquares(string str, int k) {
	int len = str.length();
	if (k >= len) return 0;

	int frequency[MAX_CHAR] = {0};
	for(int i=0; i<len; i++)
		frequency[str[i] - 'a']++;

	priority_queue<int> q;
	for (int i = 0; i < MAX_CHAR; i++)
		q.push(frequency[i]);

	while(k--) {
		int temp = q.top();
		q.pop();
		temp = temp - 1;
		q.push(temp);
	}

	int result = 0;
	while (!q.empty()) {
		int temp = q.top();
		result += pow(temp, 2);
		q.pop();
	}

	return result;
}

int main() {
    string str = "abbccc";
    int k = 1;
    cout<<"Sum of Squares of character counts in string '"<<str<<"'after removing '"<<k<<"' characters is: "<<findSumSquares(str, k);
    return 0;
}