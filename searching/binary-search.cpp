#include <iostream>
#include <math.h>

using namespace std; 

int binary_search(int element, int arr[], int min, int max) {
    cout << "runing binary min:" << min << " max " << max << endl;
    int midPoint = ((max - min) / 2) + min;
    cout << midPoint << endl;
    if(arr[midPoint] == element) return midPoint;
    if(arr[midPoint] > element) {
        return binary_search(element, arr, min, midPoint - 1);
    } else {
        return binary_search(element, arr, midPoint, max);
    }
}

int main () {
    int arr[] = { 1, 2, 3, 4, 5, 6 ,8, 9, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << size << endl;
    int index = binary_search(1, arr, 1, size);

    cout << index << "win"; 


}