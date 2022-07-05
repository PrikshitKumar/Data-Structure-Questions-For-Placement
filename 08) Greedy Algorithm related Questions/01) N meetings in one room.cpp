#include<bits/stdc++.h>
using namespace std;

int maxMeetings(int start[], int end[], int n) {
    pair<int, int> a[n+1];
    for (int i=0; i<n; i++) {
        a[i].first = end[i];
        a[i].second = i;
    }
    sort(a, a+n);

    int numberOfMeets = 1;
    int time_limit = a[0].first;
    
    for(int i=1; i<n; i++) {
        if(start[a[i].second] > time_limit) {
            numberOfMeets++;
            time_limit = a[i].first;
        }
    }
    return numberOfMeets;
}

int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] =  {2, 4, 6, 7, 9, 9};
    int length = sizeof(start)/sizeof(start[0]);
    cout<<"Starting-Ending Time of Meetings is: ";
    for(int i=0; i<length; i++) {
        cout<<endl<<start[i]<<" "<<end[i];
    }
    cout<<"\nNumber of Meetings can be held in One Room: "<<maxMeetings(start, end, length); 
    return 0;
}