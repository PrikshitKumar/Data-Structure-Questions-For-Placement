#include<bits/stdc++.h>
using namespace std;

int maxSubStrings(string str) {
    int zeroes = 0, ones = 0;
    int result = 0;
    for (int i=0; i<str.length(); i++) {
        if(str[i] == '0') zeroes++;
        else ones++;
        
        if(zeroes == ones) {
            result++;
            zeroes = ones = 0;
        }
    }
 
    if(zeroes != ones) return -1;
    return result;
}

int main() {
    string str = "0100110101"; // O/p: 4
    // string str = "0111100010"; // O/p: 3
    // string stre = "0000000000"; // O/p: -1
    cout<<"Number of Substrings having equal 0's and 1's of '"<<str<<"' are: "<<maxSubStrings(str);
    return 0;
}