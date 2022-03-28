#include<bits/stdc++.h>
using namespace std;

int countSquares(int N) {
    // code here
    int n = 1, count = 0;
    while(n*n < N) {
        n++;
        count++;
    }
    return count;
}

int main() {
    int n = 9;
    cout<<"Perfect Squares Numbers less than "<<n<<" are: "<<countSquares(n);
    return 0;
}