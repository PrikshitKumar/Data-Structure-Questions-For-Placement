#include<bits/stdc++.h>
using namespace std;

bool isPossible(int chiefs, int *ranks, int maxTime, int pratas) {
    int pratasCount = 0;
    for(int i=0; i<chiefs; i++) {
        int time = ranks[i], it = 2;
        while(time <= maxTime) {
            pratasCount++;
            time += ranks[i] * it++;
        }
        if(pratasCount >= pratas) return true;
    }
    return false;
}

int minTime(int pratas, int chiefs, int *ranks) {
    int start = 1, end = 1e8;
    int time = -1;
    while(start <= end) {
        int mid = (start + end) >> 1;
        if(isPossible(chiefs, ranks, mid, pratas)) {
            time = mid;
            end = mid-1;
        }
        else start = mid+1;
    }
    return time;
}

int main() {
/*  Input: 
    test Casese = 3
    number of Pratas = 10
    number of Cooks = 4 
    Rank of all cooks = 1 2 3 4
    number of Pratas = 8
    number of Cooks = 1 
    Rank of all cooks = 1
    number of Pratas = 8
    number of Cooks = 8 
    Rank of all cooks = 1 1 1 1 1 1 1 1
    Output:
    12 (minutes taken)
    36
    1
*/
    int pratas = 10, chiefs = 4;
    int rank[4] = {1, 2, 3, 4};
    cout<<"Minimum Time Taken by Chefs to cook "<<pratas<<" Pratas is: "<<minTime(pratas, chiefs, rank);
    return 0;
}