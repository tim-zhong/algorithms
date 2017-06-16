/*
* Worst-case performance      O(n2)
* Best-case performance       O(n log n) (simple partition) or O(n) (three-way partition and equal keys)
* Average performance         O(n log n)
* Worst-case space complexity O(n) auxiliary (naive) or O(log n) auxiliary (Sedgewick 1978)
*/
#include <iostream>
using namespace std;

void swap(int *a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Lomuto partition scheme
int partitionLomuto(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1); // index of smaller element

    for(int j = low; j <= high - 1; j++) {
        // if current element element is smaller than or equal to pivot
        if(arr[j] <= pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        // pi is the partitioning index
        int pi = partitionLomuto(arr, low, high);

        //Seperately sort both subarrays
        quickSort(arr, low, pi-1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printArray(arr, size);
    quickSort(arr, 0, size-1);
    printArray(arr, size);
    
    return 0;
}
