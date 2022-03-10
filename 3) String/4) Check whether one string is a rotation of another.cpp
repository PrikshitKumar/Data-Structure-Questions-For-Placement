#include<bits/stdc++.h>
using namespace std;

bool checkRotation(string str1, string str2) {
    if(str1.length() != str2.length()) return false;
    string temp = str1 + str1;
    int i = 0;
    for(int i=0; i<temp.size(); i++) {
        int j = 0;
        if(str2[j] == temp[i]) {
            for(j=0; j<str2.size(); j++) {
                if(str2[j] != temp[i+j]) break;
            }
        }
        if(j==str2.length()) return true;
    }
    return false;
}

int main() {
    string str1 = "abcd";
    string str2 = "cdab";
    cout<<"String 1: "<<str1<<"\nString 2: "<<str2<<endl;
    cout<<"Is String 2 is the rotation of String 1? "<<checkRotation(str1, str2);
    return 0;
}