#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int size, int curr) {
    int largest = curr;
    int left = (curr*2)+1;
    int right = (curr*2)+2;

    if(left < size && arr[largest] < arr[left]) {
        largest = left;
    }
    if(right < size && arr[largest] < arr[right]) {
        largest = right;
    }

    if(largest != curr) {
        swap(arr[largest], arr[curr]);
        heapify(arr, size, largest);
    }    
}

void buildHeap(int arr[], int size) {
    for(int i=(size/2)-1; i>=0; i--) {
        heapify(arr, size, i);
    }
}

void print(int arr[], int size) {
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<"Elements of Array before Sorting: ";
    print(arr, len);
    buildHeap(arr, len);
    cout<<"After apply Heap Sort: ";
    print(arr, len);
    print(arr, len);
}



// Complete Implementation of Heap Tree



// #include<bits/stdc++.h>
// using namespace std;

// // MAX HEAP
// class Heap {
//     public:
//         int arr[100] = {0};
//         int size = 0;
        
//         void insert(int data) {
//             int currIndex = size;
//             arr[currIndex] = data;

//             while(currIndex > 0) {
//                 int parent = (currIndex-1)/2;
//                 if(arr[parent] < arr[currIndex]) {
//                     swap(arr[parent], arr[currIndex]);
//                     currIndex = parent;
//                 }
//                 else return;
//             }
//             size++;
//         }

//         void print() {
//             cout<<"Elements of the Array are: ";
//             for(int i=0; i<size; i++) cout<<arr[i]<<" ";
//             cout<<endl;
//         }
        
//         void print(int arr[], int size) {
//             cout<<"Elements of the Array are: ";
//             for(int i=0; i<size; i++) cout<<arr[i]<<" ";
//             cout<<endl;
//         }

//         void deleteElement() {
//             if(size == 0) {
//                 cout<<"Array is Empty.\n";
//                 return;
//             }
//             arr[0] = arr[--size];
            
//             int i = 0;
//             while(i < size) {
//                 int leftIndex = (2*i)+1;
//                 int rightIndex = (2*i)+2;
//                 if(leftIndex < size && arr[i] < arr[leftIndex]) {
//                     swap(arr[leftIndex], arr[i]);
//                     i = leftIndex;
//                 }
//                 else if(rightIndex < size && arr[i] < rightIndex) {
//                     swap(arr[rightIndex], arr[i]);
//                     i = rightIndex;
//                 }
//                 else return;
//             }
//         }

//         void heapify(int arr[], int size, int curr) {   /* This is the function for taking the 'current'
//             element to it's right place according to the Heap Rules. */
//             int largest = curr;
//             int left = (curr*2)+1;
//             int right = (curr*2)+2;

//             if(left < size && arr[largest] < arr[left]) {
//                 largest = left;
//             }
//             if(right < size && arr[largest] < arr[right]) {
//                 largest = right;
//             }

//             if(largest != curr) {
//                 swap(arr[largest], arr[curr]);
//                 heapify(arr, size, largest);
//             }
//         }

//         void heapSort(int arr[], int n) {
//             int size = 0;
//             while(size < n-1) {
//                 swap(arr[size], arr[n-1]);
//                 size++;
//                 heapify(arr, size, n-1);
//             }
//         }
// };

// int main() {
//     Heap h;
//     // h.insert(50);
//     // h.insert(51);
//     // h.insert(52);
//     // h.insert(53);
//     // h.insert(54);
//     // h.print();
//     // h.deleteElement();
//     // h.print();
    
//     int arr[6] = {-1, 54, 53, 55, 52, 50};
//     int size = sizeof(arr)/sizeof(arr[0]);
//     h.print(arr, size);
//     for(int i=(size/2)-1; i>=0; i--) {
//         h.heapify(arr, size, i);
//     }
//     h.print(arr, size);
//     cout<<"Heap Sort:-\n";
//     h.heapSort(arr, size);
//     h.print(arr, size);
//     return 0;
// }