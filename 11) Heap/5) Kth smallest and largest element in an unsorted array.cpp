#include <iostream>
using namespace std;
void heapify(int arr[], int size, int curr) {
	int largest = curr;
	int left = (2*curr)+1;
	int right = (2*curr)+2;

	if(left < size && arr[left] > arr[largest]) {
		largest = left;
    }
	if (right < size && arr[right] > arr[largest]) {
		largest = right;
    }

	if(largest != curr) {
		swap(arr[curr], arr[largest]);
		heapify(arr, size, largest);
	}
}

void heapSort(int arr[], int size) {
	for(int i=(size/2)-1; i>=0; i--) {
		heapify(arr, size, i);
    }
	for(int i=size-1; i>0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

// A utility function to print array of size n
void printArray(int arr[], int N)
{
	for (int i = 0; i < N; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout<<"Elements of the Array are: ";
    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    heapSort(arr, size);
    cout<<"\nElements of Array after Sorting: ";
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
    cout<<"\n'"<<k<<"' th Smallest element of the Array is: "<<arr[k-1];
    cout<<"\n'"<<k<<"' th largest element of the Array is: "<<arr[size-k];
    return 0;
}