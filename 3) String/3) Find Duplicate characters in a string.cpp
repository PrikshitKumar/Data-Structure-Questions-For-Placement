#include<bits/stdc++.h>
using namespace std;

void checkDuplicates(string str) {
    unordered_map<char, int> occurrences;
    for(int i=0; i<str.size(); i++) {
        occurrences[str[i]]++;
    }
    unordered_map<char, int>::iterator itr;
    for(itr=occurrences.begin(); itr!=occurrences.end(); itr++) {
        if(itr->second > 1) {
            cout<<endl<<itr->first<<", Count = "<<itr->second;
        }
    }
}

int main() {
    string str = "Prikshit Kumar";
    cout<<"Original String is: "<<str<<endl;
    cout<<"Duplicate Occurrences are: ";
    checkDuplicates(str);
    return 0;
}