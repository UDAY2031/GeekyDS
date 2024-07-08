#include <stdio.h>
#include <stdbool.h>

// Function to determine if there is a subset with the given sum
bool isSubsetSum(int set[], int n, int sum) {
    // Create a 2D array to store the subset sum results
    bool subset[sum + 1];

    // Initialize the subset array
    for (int i = 0; i <= sum; ++i)
        subset[i] = false;
    subset[0] = true;

    // Fill the subset table in bottom-up manner
    for (int i = 0; i < n; ++i) {
        for (int j = sum; j >= set[i]; --j) {
            if (subset[j - set[i]])
                subset[j] = true;
        }
    }

    // Return the result
    return subset[sum];
}

int main() {
    int n, sum;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int set[n];
    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; ++i)
        scanf("%d", &set[i]);

    printf("Enter the sum to check: ");
    scanf("%d", &sum);

    if (isSubsetSum(set, n, sum))
        printf("Found a subset with given sum\n");
    else
        printf("No subset with given sum\n");

    return 0;
}

