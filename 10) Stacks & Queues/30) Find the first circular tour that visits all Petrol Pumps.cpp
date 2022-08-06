#include<bits/stdc++.h>
using namespace std;

struct petrolPump {
    int petrol;
    int distance;
};

int tour(petrolPump p[],int n) {
    int totalPetrol = 0, totalDistance = 0;
    for(int i=0; i<n; i++) {
        totalPetrol += p[i].petrol;
        totalDistance += p[i].distance;
    }
    if(totalPetrol < totalDistance) return -1;
    int tank = 0, ans = 0;
    for(int i=0; i<n; i++) {
        tank += p[i].petrol - p[i].distance;
        if(tank < 0) {
            ans = i+1;
            tank = 0;
        }
    }
    return ans;
}

int main() {
    petrolPump p[4] = {{4, 6}, {6, 5}, {7, 3}, {4, 5}}; 
    int n = 4;
    cout<<"Total Petrol in Tank and Distance have to covered is:\n";
    for(int i=0; i<n; i++) {
        cout<<"{ "<<p[i].petrol<<", "<<p[i].distance<<" }"<<endl;
    }
    cout<<"Can we cover all the stations? "<<tour(p, n);
    return 0;
}