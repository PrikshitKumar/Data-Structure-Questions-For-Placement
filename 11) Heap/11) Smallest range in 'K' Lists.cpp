#include<bits/stdc++.h>
using namespace std;
#define N 1000

class Node {
    public:
        int data, row, col;
        
        Node(int data, int row, int col){
            this->data = data;
            this->row = row;
            this->col = col;
        }
};

class compare {
    public:
        bool operator()(Node* a, Node* b) {
            return (a->data > b->data);
        }
};

pair<int,int> findSmallestRange(vector<vector<int>> KSortedArray, int n, int k) {
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    
    for(int i=0; i<k; i++) {
        int element = KSortedArray[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new Node(element, i, 0));
    }
    
    int start = mini, end = maxi;
    while(!minHeap.empty()) {
        Node* temp = minHeap.top();
        minHeap.pop();
        
        mini = temp->data;
        if(maxi-mini < end-start) {
            start = mini;
            end = maxi;
        }

        if(temp->col+1 < n) {
            maxi = max(maxi, KSortedArray[temp->row][temp->col+1]);
            minHeap.push(new Node(KSortedArray[temp->row][temp->col+1], temp->row, temp->col+1));
        }
        else break;
    }
    return {start, end};
}

int main() {
    int n = 5, k = 3;
    vector<vector<int>> arr {{1, 3, 5, 7, 9}, {0, 2, 4, 6, 8}, {2, 3, 5, 7, 11}};
    cout<<"Elements of the Array are:\n";
    for(int i=0; i<k; i++) {
        for(int j=0; j<n; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    pair<int, int> result = findSmallestRange(arr, n, k);
    cout<<"Smallest Range in Lists that can have atleast 1 element between is: {"<<result.first<<" "<<result.second<<"}";
    return 0;
}