#include<bits/stdc++.h>
using namespace std;

/*
Method 1: Recursive Approach:- Either to Pick the Character or not. (POWER SET)
Method 2: Bit Manipulation:- 
        Bitwise Operation (Follows the same patter, either to pick the character at ith position or not)
        1 - stands for picking the elemenet.
        0 - stands for not picking the element.
        Eg: length of "abc" is 3. So, 2^3 = 8 subsequences can be made from "abc";
        iterations  |   2   |   1   |   0   -> Indexes of String ("abc" = 3, So, 0,1,2).
            0       |   0   |   0   |   0   ->  NULL or EMPTY String
            1       |   0   |   0   |   1   ->  "a"
            2       |   0   |   1   |   0   ->  "b"
            3       |   0   |   1   |   1   ->  "ab"
            4       |   1   |   0   |   0   ->  "c"
            5       |   1   |   0   |   1   ->  "ac"
            6       |   1   |   1   |   0   ->  "bc"
            7       |   1   |   1   |   1   ->  "abc"
*/

// Method 1: 
void powerSet(string str, int it, string curr) {
    if(it == str.length()) {
        if(curr == "") return;
        cout<<curr<<endl;
        return;
    }
    // Picking the Element
    powerSet(str, it+1, curr+str[it]);
    // Without Picking the Element
    powerSet(str, it+1, curr);
}

// Method 2: TC: O(2^n * n)
void allPossibleSubSequences(string str) {
    int len = str.size();
    vector<string> result;
    for(int i=0; i<(1<<len); i++) { // left shift 1 by len means 1<<3 (000, 001, 010, 100): 1 0 0 => 2^3
        //TC: O(2^n)
        string temp = "";
        for(int j=0; j<len; j++) {
            // TC: O(n)
            if(i & (1<<j)) temp += str[j];
        }
        if(temp.length() > 0) result.push_back(temp);
    }
    for(int i=0; i<result.size(); i++) cout<<result[i]<<endl;
}

int main() {
    string str = "abc";
    cout<<"All the Subsequences of '"<<str<<"' are: "<<endl;
    // powerSet(str, 0, "");
    allPossibleSubSequences(str);
    return 0;
}
