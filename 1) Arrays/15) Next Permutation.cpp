#include<bits/stdc++.h>
using namespace std;

/* We have two Approaches for solving this Problem: 
    i) Get all the possible Permutations of the given Number and Sort them in Asscending Order. 
        Now iterate through the loop, find the current number. And, because of sorting, we will get the 
        next permutation on [i+1] index.
        But, the Time Complexity of this Approach is: O(n^2).
    ii) This approach is the Optmised Version of getting the next Permutation of the given number with 
        O(n) Time Complexity.
        The Algorithm is: 
        Let's take a Number for better explanation, Number = 13542
        a) Iterate from the Last, and find the number that is less than it's immediate next number.
            arr[i] < arr[i+1]. So, 1st Number: arr[i]. 
            So, 1st Number = 3, 1st Number Index = 1.
        b) Iterate from the Last, and find the number that is greater than the First Number.
            arr[i] > firstNumber. So, 2nd Number: arr[i];
            So, 2nd Number = 4, 2nd Number Index = 3.
        c) Swap both the Numbers with each other.
            swap(arr[1stNumberIndex], arr[2ndNumberIndex]);
            So, Now the number is: 14532
        d) Reverse the Next Numbers after 1st Number Index.
            reverse(1stNumberIndex, till last);
            So, Now the number will become: 14235, and this is the next Permutation of the given Number.
        The intution behind this approach is that, as we have to always find the lexographical number means
        arranging in Dictionary Order, i.e, in Asscending Order. Because of this Dictionary Order, we only 
        reverse the numbers after 1st Number Index. 
        If we take any digit that is not in the order of Dictionary, that will gave an Error and we will get 
        the wrong Permutation of the given Number. Eg: 12354, or something.

    Here One more problem is there, what if all the digits of the number are in already Asscending Order.
    Eg: 54321, In this case, we will not proceed with the 1st, 2nd, and 3rd Step. But, we will go with last
    Step, that is Reverse the Number. Because, according to Dictionary Order, after ending all the numbers
    we have to start from 1st Number again.
    So, after Reverse the Number we will get: 12345, and this is the immediate permutation of the given no.

    Also the Time Complexity is Approach is O(n), as we only once traversed the array for find the number 
    that is less than it's immediate number, O(n), after that we only once traversed though the array for 
    finding the number that is greater than 1st Number, O(n), last we traversed through the array for 
    reversing the number after the 1st Number index, O(n).
    So, O(n) + O(n) + O(n) = O(3n) = O(n) approaximately.

    Youtube URL: https://youtu.be/LuLCLgMElus
*/

void swap(int &num1, int &num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void reverse(vector<int> &numbers, int start, int end) {
    while(start < end) {
        swap(numbers[start], numbers[end]);
        start++; end--;
    }
}

void nextPermutation(vector<int> &arr, int length) {
    int index1 = -1, index2 = -1;
    for(int i=length-2; i>=0; i--) {
        if(arr[i] < arr[i+1]) {
            index1 = i;
            break;
        }
    }
    if(index1 != -1) {
        for(int i=length-1; i>index1; i--) {
            if(arr[i] > arr[index1]) {
                index2 = i;
                break;
            } 
        }
        swap(arr[index1], arr[index2]);
    }
    reverse(arr, index1+1, length-1);
}

int main() {
    // vector<int> arr {1, 2, 3, 6, 5, 4};
    vector<int> arr {3, 2, 1};
    int length = arr.size();
    cout<<"Number inside Array is: ";
    for(int i=0; i<length; i++) cout<<arr[i]<<" ";
    cout<<"\nThe Immidiate Permutation of the given number is: ";
    nextPermutation(arr, length);
    for(int i=0; i<length; i++) cout<<arr[i]<<" ";
    return 0;
}