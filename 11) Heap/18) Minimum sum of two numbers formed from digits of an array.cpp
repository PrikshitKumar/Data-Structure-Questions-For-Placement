#include<bits/stdc++.h>
using namespace std;

string add(string s1, string s2) {
    int len1 = s1.size()-1, len2 = s2.size()-1;
    string ans = "";
    int carry = 0;
    while((len1 >= 0) && (len2 >= 0)) {
        int a = s1[len1--] - '0';
        int b = s2[len2--] - '0';
        int sum = a + b + carry;
        ans += (sum % 10) + '0';
        carry = sum / 10;
    }
    while(len1 >= 0) {
        int sum = (s1[len1--] - '0') + carry;
        ans += (sum % 10) + '0';
        carry /= 10;
    }
    while(carry != 0) {
        ans += (carry % 10) + '0';
        carry /= 10;
    }
    return ans;
}

string solve(int arr[], int n) {
    sort(arr, arr+n);
    string s1 = "", s2 = "";
    for(int i=0; i<n; i+=2) {
        s1 += (arr[i] + '0');
        if(i+1 < n) s2 += (arr[i+1] + '0');
    }
    string ans = add(s1, s2);
    reverse(ans.begin(), ans.end());
    
    int start = 0;
    while(ans[start] == '0') start++;
    ans = ans.substr(start);
    
    return ans;
}

int main() {
    int size = 5;
    int arr[] = {5, 3, 0, 7, 4};
    cout<<"Elements of the Array are: ";
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
    cout<<"\nMinimum Sum of Two Numbers fromed from Digits of an Array would be: "<<solve(arr, size);
    return 0;
}