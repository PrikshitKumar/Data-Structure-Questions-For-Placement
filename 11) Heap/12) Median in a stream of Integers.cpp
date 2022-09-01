#include<bits/stdc++.h>
using namespace std;

void balanceHeaps();

priority_queue<int, vector<int>> minHeap;
priority_queue<int, vector<int>, greater<int>> maxHeap;
int minSize = 0, maxSize = 0;

//Function to insert heap.
void insertHeap(int &x) {
    maxHeap.push(x);
    maxSize++;
    
    minHeap.push(maxHeap.top());
    minSize++;
    
    maxHeap.pop();
    maxSize--;
    
    balanceHeaps();
}

//Function to balance heaps.
void balanceHeaps() {
    if(minHeap.size() > maxHeap.size()) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
        maxSize++;
        minSize--;
    }
}

//Function to return Median.
double getMedian() {
    if(maxSize > minSize) return maxHeap.top();
    else return (maxHeap.top() + minHeap.top()) / 2.00;
}

int main() {
    int arr[] = {5, 15, 1, 3};
    int size = 4;
    cout<<"Elements of the Array are: ";
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";

    cout<<"\nMedian In a Stream of Integers is: ";
    for(int i=0; i<size; i++) {
        insertHeap(arr[i]);
        cout<<getMedian()<<" ";
    }   

    return 0;
}