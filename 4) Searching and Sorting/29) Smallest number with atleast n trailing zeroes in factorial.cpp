#include<bits/stdc++.h>
using namespace std;

int trailz(int n){
    int s = 0;
    while(n >= 5) {
        s += (n/5);
        n /= 5;
    }
    return s;
}

int findNum(int n) {
    //complete the function here
    int low = 1, high = 5*n, mid;
    while(low <= high) {
        mid = low + (high-low)/2;
        if(trailz(mid) == n && mid%5 == 0) return mid;
        else if(trailz(mid) < n) low = mid+1;
        else high = mid-1;
    }
}

int main() {
    int n = 1;
    cout<<"Number that has atleast "<<n<<" zeroes in it's Factorial is: "<<findNum(n);
    return 0;
}