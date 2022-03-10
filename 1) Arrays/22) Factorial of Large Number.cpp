#include<bits/stdc++.h>
using namespace std;

vector<int> factorial(int N){
    vector<int> result {1};
    for(int i=2; i<=N; i++) {
        int carry = 0;
        for(int j=0; j<result.size(); j++) {
            int value = result[j]*i + carry;
            result[j] = value%10;
            carry = value/10;
        }
        while(carry != 0) {
            result.push_back(carry%10);
            carry /= 10;
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int num;
    cout<<"Enter the Number: ";
    cin>>num;
    vector<int> result = factorial(num);
    cout<<"Factorial of a Number is: ";
    for(int i=0; i<result.size(); i++) cout<<result[i];
    return 0;
}