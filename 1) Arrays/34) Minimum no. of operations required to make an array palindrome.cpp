#include<bits/stdc++.h>
using namespace std;

int checkPalindrome(int num) {
    int temp = num;
    int result = 0, count = 0;
    while(temp != 0) {
        result = (result*10) + temp%10;
        temp /= 10; 
    }
    return (result==num)?1:0;
}

int PalinArray(int arr[], int length)
{
    for(int i=0; i<length; i++) {
        if(!checkPalindrome(arr[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int arr[] = {121, 131, 20};
    int length = sizeof(arr)/sizeof(arr[0]);
    cout<<"Elements of an Array are: ";
    for(int i=0; i<length; i++) cout<<arr[i]<<" ";
    cout<<"\nIs all the numbers of Array are Palindrome? "<<PalinArray(arr, length);
    return 0;
}