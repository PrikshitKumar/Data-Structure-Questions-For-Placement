#include<bits/stdc++.h>
using namespace std;

/* Operations on Circular Queue:
    i) Front: Get the front item from queue.
    ii) Rear: Get the last item from queue.
    iii) enQueue(value): This function is used to insert an element into the circular queue. In a 
            circular queue, the new element is always inserted at Rear position. 
        a) Check whether queue is Full – Check ((rear == SIZE-1 && front == 0) || (rear == front-1)).
        b) If it is full then display Queue is full. If queue is not full then, check if 
            (rear == SIZE – 1 && front != 0) if it is true then set rear=0 and insert element.
    iv) deQueue(): This function is used to delete an element from the circular queue. In a circular 
            queue, the element is always deleted from front position. 
        a) Check whether queue is Empty means check (front==-1).
        b) If it is empty then display Queue is empty. If queue is not empty then step 3
        c) Check if (front==rear) if it is true then set front=rear= -1 else check if (front==size-1), 
            if it is true then set front=0 and return the element.
*/

class Queue {
	int rear, front;
	int size;
	int *arr;
public:
	Queue(int s) {
        front = rear = -1;
        size = s;
    	arr = new int[s];
	}

	void enQueue(int value);
	int deQueue();
	void displayQueue();
};

/* Function to create Circular queue */
void Queue::enQueue(int value) {
	if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))) {
		cout<<"\nQueue is Full";
		return;
	}
	else if(front == -1) {
		front = rear = 0;
		arr[rear] = value;
	}
	else if(rear==size-1 && front!=0) {
		rear = 0;
		arr[rear] = value;
	}
	else {
		rear++;
		arr[rear] = value;
	}
}

int Queue::deQueue() {
	if(front == -1) {
		printf("\nQueue is Empty");
		return INT_MIN;
	}

	int data = arr[front];
	arr[front] = -1;
	if (front == rear) {
		front = -1;
		rear = -1;
	}
	else if (front == size-1) front = 0;
	else front++;

	return data;
}

void Queue::displayQueue() {
	if(front == -1) {
		cout<<"\nQueue is Empty";
		return;
	}
	cout<<"\nElements in Circular Queue are: ";
	if (rear >= front) {
		for(int i=front; i<=rear; i++) cout<<arr[i]<<" ";
	}
	else {
		for(int i=front; i<size; i++) cout<<arr[i]<<" ";
		for(int i=0; i<=rear; i++) cout<<arr[i]<<" ";
	}
}

int main() {
	Queue q(5);

	// Inserting elements in Circular Queue
	q.enQueue(14);
	q.enQueue(22);
	q.enQueue(13);
	q.enQueue(-6);

	// Display elements present in Circular Queue
	q.displayQueue();

	// Deleting elements from Circular Queue
	printf("\nDeleted value = %d", q.deQueue());
	printf("\nDeleted value = %d", q.deQueue());
	q.displayQueue();
	q.enQueue(9);
	q.enQueue(20);
	q.enQueue(5);
	q.displayQueue();
	q.enQueue(20);
	return 0;
}