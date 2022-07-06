#include<bits/stdc++.h>
using namespace std;

class Job {
    public:
        int id;
        int dead;
        int profit;
};

bool comparison(Job obj1, Job obj2) {
    return (obj1.profit > obj2.profit);
}

vector<int> JobScheduling(Job arr[], int n) { 
    sort(arr, arr+n, comparison);
    int maximum = 0;
    for(int i=0; i<n; i++) {
        if(arr[i].dead > maximum) {
            maximum = arr[i].dead;
        }
    }
    vector<int> result(2, 0);
    vector<int> slots(maximum+1, -1);
    for(int i=0; i<n; i++) {
        int start = arr[i].dead;
        while(start > 0) {
            if(slots[start] == -1) {
                slots[start] = i;
                result[0]++;
                result[1] += arr[i].profit;
                break;
            }
            start--;
        }
    }
    return result;
} 

int main() {
    Job arr[6];
    arr[0].id = 1;
    arr[0].dead = 2;
    arr[0].profit = 100;
    arr[1].id = 3;
    arr[1].dead = 2;
    arr[1].profit = 27;
    arr[2].id = 4;
    arr[2].dead = 1;
    arr[2].profit = 25;
    arr[3].id = 2;
    arr[3].dead = 1;
    arr[3].profit = 19;
    arr[4].id = 5;
    arr[4].dead = 1;
    arr[4].profit = 15;

    cout<<"Data of Jobs are: ";
    for(int i=0; i<5; i++) {
        cout<<endl<<arr[i].id<<" "<<arr[i].dead<<" "<<arr[i].profit;
    }
    vector<int> result = JobScheduling(arr, 5);
    cout<<"\nNumber of Jobs:- "<<result[0];
    cout<<"\nMaximum Profit:- "<<result[1];
    return 0;
}