#include <stdio.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partitionLomuto(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low; 
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

void quickSortLomuto(int arr[], int low, int high) {
    if (low < high) {
        int p = partitionLomuto(arr, low, high);
        quickSortLomuto(arr, low, p - 1);
        quickSortLomuto(arr, p + 1, high);
    }
}

int partitionHoare(int arr[], int low, int high) {
    int pivot = arr[low + (high - low) / 2];
    int i = low - 1;
    int j = high + 1;
    while (1) {
        do { i++; } while (arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);
        if (i >= j) return j;
        swap(&arr[i], &arr[j]);
    }
}

void quickSortHoare(int arr[], int low, int high) {
    if (low < high) {
        int p = partitionHoare(arr, low, high);
        quickSortHoare(arr, low, p);
        quickSortHoare(arr, p + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int data1[] = {10, 7, 8, 9, 1, 5};
    int n1 = sizeof(data1) / sizeof(data1[0]);
    quickSortLomuto(data1, 0, n1 - 1);
    printf("Lomuto Sorted: ");
    printArray(data1, n1);
    int data2[] = {10, 7, 8, 9, 1, 5};
    int n2 = sizeof(data2) / sizeof(data2[0]);
    quickSortHoare(data2, 0, n2 - 1);
    printf("Hoare Sorted:  ");
    printArray(data2, n2);
    return 0;
}
