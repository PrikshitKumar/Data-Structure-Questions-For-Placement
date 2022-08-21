#include<bits/stdc++.h>
using namespace std;

string firstNonRepeating(string A){
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
    cout<<"Orginal String is: "<<str;
    cout<<"\nResultant String is: "<<firstNonRepeating(str);
    return 0;
}