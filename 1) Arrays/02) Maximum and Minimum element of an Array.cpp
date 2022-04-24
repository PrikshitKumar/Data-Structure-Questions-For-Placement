#include <bits/stdc++.h>
using namespace std;

class Values {
    public:
        int min;
        int max;
};

Values minMaxElement(int arr[], int length) {
    Values obj;
    if(length == 1) {
        obj.min = obj.max = arr[0];
    }
    else if(length == 2) {
        if(arr[0] == arr[1]) {
            obj.min = obj.max = arr[0];
        }
        else {
            obj.min = arr[0]<arr[1]?arr[0]:arr[1];
            obj.max = arr[0]>arr[1]?arr[0]:arr[1];
        }
    }
    else {
        obj.min = obj.max = arr[0];
        for(int i=1; i<length; i++) {
            if(obj.min > arr[i]) obj.min = arr[i];
            if(obj.max < arr[i]) obj.max = arr[i];
        }
    }
    return obj;
}

int main() {
    int arr[] = {1, 5 , 8, 9, 10, 3, 7};
    int length = sizeof(arr)/sizeof(arr[0]);
    cout<<"Elements of the Array are: ";
    for(int i=0;i<length;i++) {
        cout<<arr[i]<<" ";
    }
    Values obj = minMaxElement(arr, length);
    cout<<"\nMinimum Element: "<<obj.min;
    cout<<"\nMaximum Element: "<<obj.max;
    return 0;
}
