#include<bits/stdc++.h>
using namespace std;

class MyQueue {
    public: 
        int data, front, rear, size;
        vector<int> queueArray;

        MyQueue(int size) {
            this->size = size;
            front = rear = -1;
            queueArray.resize(size, -1);
        }

        void enqueue(int data) {
            if(front == -1) {
                queueArray[++front] = data;
                rear++;
            }
            else {
                queueArray[++rear] = data;
            }
        }
        int dequeue() {
            return queueArray[front++];
        }
        int getFront() {
            return queueArray[front];
        }
        int getRear() {
            return queueArray[rear];
        }
        bool isEmpty() {
            return front == -1;
        }
        int getSize() {
            return (rear - front + 1);
        }
};

int main() {
    MyQueue queueArray(5);
    cout<<"Inserting Elements in Queue: ";
    for(int i=0; i<5; i++) {
        queueArray.enqueue((i+1)*10);
        cout<<queueArray.getRear()<<" ";
    }
    cout<<"\nSize of the Queue is: "<<queueArray.getSize();
    cout<<"\nElements of the Queue are: ";
    for(int i=0; i<5; i++) {
        cout<<queueArray.dequeue()<<" ";
    }
    cout<<"\nSize of the Queue is: "<<queueArray.getSize();
    return 0;
}