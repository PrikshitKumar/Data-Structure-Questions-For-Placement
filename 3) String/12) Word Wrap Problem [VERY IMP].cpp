#include<bits/stdc++.h>
using namespace std;

/* Greedy Method: It didn't give the overall optimal Solution, it just take care of current situation and
    chk the possibilities whether cuurent sitution could solve with optimal solution or not. 
    So, we will have to use the DP Approach for the solution of this problem. Because DP, first consider
    all the situations and the result and according to that, it will return the best optimal solution. 
*/   
// Greedy Approach:-
/*
int solveWordWrap(vector<int> &nums, int k) {
    int cost = 0;
    for(int i=0; i<nums.size(); ) {
        int itr = i, temp = 0;
        while((temp + nums[itr] + 1 <= k) && (itr < nums.size())) {
            temp += nums[itr] + 1;
            itr++;
            if((itr == nums.size()-1) && (temp + nums[itr] <= k)) {
                itr++;
                break;
            }
        }
        if(itr == nums.size()) break;
        temp = k - (temp-1);
        cost += pow(temp, 2);
        i = itr;
    }
    return cost;
}
*/

// DP Approach:- (Optimal)
int solveWordWrap(vector<int> &nums, int k) {

}

int main() {
    vector<int> nums {3,2,2,5}; // O/p: 10
    int k = 6;
    // vector<int> nums = {3,2,2}; // O/p: 5
    // int k = 4;
    // vector<int> nums {6, 6, 7, 4, 4}; // O/p: 222
    // int k = 9; 
    cout<<"Length of Words at 'ith' positions are: ";
    for(int i=0; i<nums.size(); i++) cout<<nums[i]<<" ";
    cout<<"\nNo. of words per Line (Line Width) are (including Space): "<<k<<endl;
    cout<<"Cost for maintain the Line Width property is: "<<solveWordWrap(nums, k)<<endl;;
    return 0;
}