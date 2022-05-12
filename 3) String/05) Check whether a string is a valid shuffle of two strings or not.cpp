#include<bits/stdc++.h>
using namespace std;

bool checkShuffle(string str1, string str2, string temp) {
    unordered_map<char, int> map;
    for(int i=0; i<str1.size(); i++) {
        map[str1[i]]++;
    }
    for(int i=0; i<str2.size(); i++) {
        map[str2[i]]++;
    }
    for(int i=0; i<temp.size(); i++) {
        if(map[temp[i]] != 0) {
            map[temp[i]]--;
        }
        else return false;
    }
    return true;
}

int main() {
    string str1 = "xy", str2 = "12", temp;
    cout<<"String 1 is: "<<str1<<"\nString 2 is: "<<str2<<endl;
    cout<<"Enter the Shuffled String: ";
    cin>>temp;
    cout<<"Whether the '"<<temp<< "' is valid Shuffle of '"<<str1<<"' and '"<<str2<<"' or not? ";
    if(checkShuffle(str1, str2, temp)) cout<<"Yes";
    else cout<<"No";
    return 0;
}
