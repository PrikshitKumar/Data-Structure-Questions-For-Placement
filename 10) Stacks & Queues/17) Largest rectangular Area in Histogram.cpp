#include<bits/stdc++.h>
using namespace std;

vector<long long > nextSmallerElement(long long  *arr, int n) {
    stack<long long > s;
    s.push(-1);
    vector<long long > ans(n);
    
    for(long long  i=n-1; i>=0 ; i--) {
        long long  curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<long long > prevSmallerElement(long long * arr, int n) {
    stack<long long > s;
    s.push(-1);
    vector<long long > ans(n);
    
    for(long long  i=0; i<n; i++) {
        long long  curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans; 
}    



long long  largestRectangleArea(long long * heights, int n) {
    vector<long long > next(n);
    next = nextSmallerElement(heights, n);

    vector<long long > prev(n);
    prev = prevSmallerElement(heights, n);
    
    long long  area = INT_MIN;
    for(long long  i=0; i<n; i++) {
        long long  l = heights[i];
        
        if(next[i] == -1) {
            next[i] = n;
        }
        long long  b = next[i] - prev[i] - 1;
        long long  newArea = l*b;
        area = max(area, newArea);
    }
    return area;
}

//Function to find largest rectangular area possible in a given histogram.
long long getMaxArea(long long arr[], int n) {
    long long ans = largestRectangleArea(arr, n);
    return ans;
}

int main() {
    long long arr[] = {6,2,5,4,5,1,6};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout<<"Maximum Area of Rectangle in the given Histogram is: "<<getMaxArea(arr, len);
    return 0;
}