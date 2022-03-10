#include<bits/stdc++.h>
using namespace std;

int isPalindrome(string S) {
    string temp = "";
    for(int i=S.size()-1; i>=0; i--) {
        temp += S[i];
    }
    return temp == S;
}

int main() {
    string str = "abba";
    cout<<"Original String is: "<<str<<endl;
    cout<<"Whether String is Palindrome or not? "<<isPalindrome(str);
    return 0;
}