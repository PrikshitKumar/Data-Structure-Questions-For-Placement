#include<bits/stdc++.h>
using namespace std;

string countAndSay(int n) {
    string result = "1";
    n -= 1;
    while(n--) {
        string temp = "";
        for(int i=0; i<result.size(); ) {
            int count = 0;
            for(int j=i; j<result.size(); j++) {
                if(result[i] == result[j]) count++;
                else break;
            }
            temp += to_string(count) + result[i];
            i += count;
        }
        result = temp;
    }
    return result;
}

int main() {
    int n = 5;
    cout<<"Count of Digits till "<< n <<" Iterations is: "<<countAndSay(n);
    return 0;
}
