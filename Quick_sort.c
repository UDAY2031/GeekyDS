#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quicksort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to generate random numbers
void generateRandomNumbers(int arr[], int size) {
    srand(time(0));  // Seed the random number generator
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;  // Generate numbers between 0 and 999
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];  // Variable-length array (VLA) to store elements

    // Generate random numbers and print the unsorted array
    generateRandomNumbers(arr, size);
    printf("Unsorted array:\n");
    printArray(arr, size);

    // Measure execution time of sorting
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    quickSort(arr, 0, size - 1);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print sorted array and execution time
    printf("\nSorted array:\n");
    printArray(arr, size);
    printf("\nExecution time: %f seconds\n", cpu_time_used);

    return 0;
}

