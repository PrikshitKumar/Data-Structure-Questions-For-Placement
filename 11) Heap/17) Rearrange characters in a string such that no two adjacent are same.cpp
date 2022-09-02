#include<bits/stdc++.h>
using namespace std;

string rearrangeString(string s) {
    unordered_map<char, int> mp;
    for(int i=0; i<s.size(); i++) mp[s[i]]++;

    priority_queue<pair<int, char>> maxHeap;
    for(auto x:mp) {
        maxHeap.push({x.second,x.first});
    }

    string ans = "";

    while(!maxHeap.empty()){
        auto block = maxHeap.top();
        maxHeap.pop();

        if(!ans.empty() && ans.back() == block.second) {
            if(maxHeap.empty()) return "-1";

            auto temp = maxHeap.top();
            maxHeap.pop();

            maxHeap.push(block);
            block = temp;
        }
        
        ans.push_back(block.second);

        if(block.first-1 > 0) {
            maxHeap.push({block.first-1, block.second});
        }
    }

    return ans;
}

int main() {
    string str = "aab";
    cout<<"Original String is: "<<str;
    string ans = rearrangeString(str);
    if(ans.empty()) cout<<"\nCannot ReOrganize the String!!";
    cout<<"\nReOrganization of String where each character didn't match with its previous or next character: "<<ans;
    return 0;
}