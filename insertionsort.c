#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        // Shift elements to the right to create a position for key
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main() {
    int n;

    // Input the number of elements
    printf("Enter the size: ");
    scanf("%d", &n);

    int a[n];

    // Input array elements
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Perform insertion sort
    insertionSort(a, n);

    // Print sorted array
    printf("Sorted elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

