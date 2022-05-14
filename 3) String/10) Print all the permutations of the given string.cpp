#include<bits/stdc++.h>
using namespace std;

/*
    Method 1: Backtracking, recursion
        In this method, we freeze the 1st character and swap the other elements and print that. But we
        will have to swap again the elements (Backtracking) for getting the original String after 
        recursive calls. Eg: string = "abc"
        abc => a (b c), b (a c), c (b a)
        a (b c) => a (b c), a (c b) => a b (c), a c (b); [Redo all the swapping the operations by swaping 
            again the same indices.]
        b (a c) => b (a c), b (c a) => b a (c), b c (a);
        c (b a) => c (b a), c (a b) => c b (a), c a (b);

        Result: abc, acb, bac, bca, cba, cab
        Possible Permutations => Length of input: 3, So, 3! = 3 * 2 * 1 = 6
        TC : O(n*n!) -> O(n) is for traversing

        inside (brackets) are the characters those are gonna to swap.

    Method 2: This approach is similar to the 1st one, but here instead of swaping the indices we store 
        the picked element index in any Data Struture (like Array, Vector, etc.) And, we check for 
        every iteration whether the element that we are gonna to pick is used already or not by using 
        the pre-defined Data Structure.

    => Mehtod 1 is optimal Approach and didn't use any space for calculating the Permutations.
*/

// Mehtod 1: 
void permutations(string str, int left, int right) {
    if(left == right) {
        cout<<str<<endl;
        return;
    }
    for(int i=left; i<=right; i++) {
        swap(str[left], str[i]);
        permutations(str, left+1, right);
        // Backtracking - Redo all the changes!
        swap(str[left], str[i]); 
    }
}

// Method 2: 
void permutations(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[]) {
    if(ds.size() == nums.size()) {
        ans.push_back(ds);
        return;
    }
    for(int i=0; i<nums.size(); i++) {
        if(!freq[i]) {
            ds.push_back(nums[i]);
            freq[i] = 1;
            permutations(ds, nums, ans, freq);
            /* Backtracking - Redo all the changes and made the data similar to the data that we got in 
                the starting. */
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

int main() {
    string str = "abc";
    cout<<"Permutations of the '"<<str<<"' are: "<<endl;
    permutations(str, 0, str.length()-1);
    return 0;
}