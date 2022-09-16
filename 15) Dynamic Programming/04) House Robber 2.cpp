#include <bits/stdc++.h> 
using namespace std;

#define lli long long int
lli maximumNonAdjacentSum(vector<int> &nums) {
    lli prev1 = nums[0];
    lli prev2 = 0;
    for(int i=1; i<nums.size(); i++) {
        lli pick = nums[i];
        if(i > 1) pick += prev2;
        lli notPick = prev1;

        lli curr = max(pick, notPick);
        prev2 = prev1; 
        prev1 = curr;
    }
    return prev1;
}

long long int houseRobber(vector<int> &valueInHouse) {
    vector<int> vec1, vec2;
    int len = valueInHouse.size();
    if(len == 1) return valueInHouse[0];
    for(int i=0; i<len; i++) {
        if(i != 0) vec1.push_back(valueInHouse[i]);
        if(i != len-1) vec2.push_back(valueInHouse[i]);
    }
    return max(maximumNonAdjacentSum(vec1), maximumNonAdjacentSum(vec2));
}

int main() {
    vector<int> vec {2, 1, 4, 9};
    cout<<"Elements of the Array are: ";
    for(int i=0; i<vec.size(); i++) cout<<vec[i]<<" ";
    cout<<"\nMaximum Money that can be robbed by thief without robbing adjcent houses is: "<<houseRobber(vec);
    return 0;
}