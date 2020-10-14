#include <iostream>

using namespace std;

void swap(int *arr1, int *arr2) {
    int temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}

void bubbleSort(int *arr, int size) {
    int i, j;
    for (int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main () {
    int ar[] = { 1,4,3,12,9, 2, 14, 4 };
    int size = sizeof(ar)/sizeof(ar[0]);
    bubbleSort(ar, size);
    cout << "Printing table" << endl;
    for (int i = 0; i < size; i++) {
        cout << ar[i] << endl;
    }
}
