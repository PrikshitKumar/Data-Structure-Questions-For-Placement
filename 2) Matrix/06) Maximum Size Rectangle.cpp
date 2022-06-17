#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  private:
  
  vector<int> nextSmallerElement(int *arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(int* arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans; 
    }    
    
  
  
  int largestRectangleArea(int* heights, int n) {
        //int n= heights.size();
        
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
            
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        
        int area = INT_MIN;
        for(int i=0; i<n; i++) {
            int l = heights[i];
            
            if(next[i] == -1) {
                next[i] = n;
            }
             int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }
  public:
    int maxArea(int M[4][4], int n, int m) {
        
        //compute area for first row
        int area = largestRectangleArea(M[0], m);
        
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<m; j++) {
                
                //row udpate: by adding previous row's value
                if(M[i][j] != 0)
                    M[i][j] = M[i][j] + M[i-1][j];
                else
                    M[i][j] = 0;
            }
            
            //entire row is updated now
            area = max(area, largestRectangleArea(M[i],m));
            
        }
        return area;
    }
};


// { Driver Code Starts.
int main() { 
/*  Input:
    n = 4, m = 4
    M[][] = {{0 1 1 0},
            {1 1 1 1},
            {1 1 1 1},
            {1 1 0 0}}
    Output: 8 
*/   
    int n = 4, m = 4;
    int M[4][4] = {{0, 1, 1, 0},
            {1, 1, 1, 1},
            {1, 1, 1, 1},
            {1, 1, 0, 0}};
    cout<<"Elements of the Histogram are:";
    for(int i=0; i<n; i++) {
        cout<<endl;
        for(int j=0; j<m; j++) {
            cout<<M[i][j]<<" ";
        }
    }
    Solution obj;
    cout <<"\nMaximum Size Rectangle is: "<<obj.maxArea(M, n, m) << endl;
    return 0;
}