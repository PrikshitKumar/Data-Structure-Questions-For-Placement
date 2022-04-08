#include<bits/stdc++.h>
using namespace std;

int inSequence(int a, int b, int c){
    if(a == b) return 1;
    if(c == 0) return 0;
    if( (b - a) % c == 0 && b > a && c > 0) return 1;
    else if( (b - a) % c == 0 && b < a && c < 0) return 1;
    return 0;
}

int main() {
    // int a = 1, b = 2, c = 3;
    int a = 1, b = 3, c = 2;
    // a = First Term, c = Common Difference, b = Term in AP Exists or not
    cout<<b<<" Exits in AP? "<<inSequence(a, b, c);
    return 0;
}