#include <bits/stdc++.h>
using namespace std;

class Interval {
    public:
	int start, end;
};

bool compareInterval(Interval i1, Interval i2) {
	return (i1.start < i2.start);
}

void mergeIntervals(Interval arr[], int n) {
	if (n <= 0)	return;

	stack<Interval> st;
	sort(arr, arr+n, compareInterval);

	st.push(arr[0]);
	for(int i=1; i<n; i++) {
		Interval top = st.top();
		if(top.end < arr[i].start) st.push(arr[i]);
		else if (top.end < arr[i].end) {
			top.end = arr[i].end;
			st.pop();
			st.push(top);
		}
	}

	cout << "The Merged Intervals are: ";
	while (!st.empty()) {
		Interval t = st.top();
		cout << "[" << t.start << "," << t.end << "] ";
		st.pop();
	}
	return;
}

int main() {
	Interval arr[] = { { 6, 8 }, { 1, 9 }, { 2, 4 }, { 4, 7 } };
	int size = sizeof(arr) / sizeof(arr[0]);
	mergeIntervals(arr, size);
	return 0;
}