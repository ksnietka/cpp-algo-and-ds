#include <iostream>

using namespace std;
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while(j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

}
int main () {
    int arr[] = {3, 1, 4, 5, 8, 9, 6, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    };
    
}