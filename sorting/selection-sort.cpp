#include <iostream>

using namespace std;

void swap(int *px, int *py) {
    int temp = *px;
    *px = *py;
    *py = temp;
}
int selectionSort(int arr[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        int maxIndex = i;
        for (j = i; j < size; j++) {
            
            if (arr[maxIndex] < arr[j]) {
                maxIndex = j;
            };
        }
        swap(&arr[i], &arr[maxIndex]);
    };
}

int main () {
    int arr[] = { 1, 4, 3, 9, 6, 13};
    int size = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, size);
    for(int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    };
    
    return 1;
}