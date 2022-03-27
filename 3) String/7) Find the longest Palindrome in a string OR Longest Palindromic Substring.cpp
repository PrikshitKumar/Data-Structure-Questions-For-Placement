#include<bits/stdc++.h>
using namespace std;

string longestPalin (string S) {
    int low, high;
    int start = 0, end = 1;
    for(int i=1; i<S.length(); i++) {
        low = i-1;
        high = i;
        
        while(low>=0 && high<S.length() && S[low]==S[high]) {
            if(high-low+1 > end) {
                start = low;
                end = high-low+1;
            }
            low--;
            high++;
        }
        
        low = i-1;
        high = i+1;
        
        while(low>=0 && high<S.length() && S[low]==S[high]) {
            if(high-low+1 > end) {
                start = low;
                end = high-low+1;
            }
            low--;
            high++;
        }
    }
    return S.substr(start, end);
}

int main() {
    string str = "aaaabbaa";
    cout<<"Original String: "<<str<<endl;
    cout<<"Longest Palindrome of '"<< str <<"' is: "<<longestPalin(str);
    return 0;
}