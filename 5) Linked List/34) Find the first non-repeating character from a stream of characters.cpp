#include<bits/stdc++.h>
using namespace std;

// Approach-1 : Gives TLE
/* string FirstNonRepeating(string A) {
    vector<int> freq(26, 0);
    vector<char> temp;
    string result = "";
    for(int i=0; i<A.length(); i++) {
        if(!freq[A[i]]-'a') {
            temp.push_back(A[i]);
        }
        freq[A[i]-'a']++;
        int flag = 0;
        for(int j=0; j<temp.size(); j++) {
            if(freq[temp[j]-'a'] == 1) {
                result += temp[j];
                flag = 1;
                break;
            }
        }
        if(flag == 0) result += '#';
    }
    return result;
} */

string FirstNonRepeating(string A) {
    // Code here
    unordered_map<char,int> count;
    queue <int> q;
    string ans = "";
    
    for(int i=0; i<A.length(); i++) {
        char ch = A[i];
        count[ch]++;
        q.push(ch);
    
        while(!q.empty()) {
            if(count[q.front()] > 1) {
                q.pop();
            }
            else {
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()) {
            ans.push_back('#');
        }
    }
    return ans;
}


int main() {
    string str = "aabc";
    // string str = "hrqcvsvszpsjammdrw";
    cout<<"String is: "<<str;
    cout<<"\nResult: "<<FirstNonRepeating(str);
    return 0;
}