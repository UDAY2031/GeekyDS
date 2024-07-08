#include <stdio.h>
#include <stdlib.h>

// Structure to represent a request
struct Request {
    int start, finish, value;
};

// Function to find the latest non-conflicting request before the current request
int latestNonConflict(struct Request requests[], int i) {
    for (int j = i - 1; j >= 0; j--) {
        if (requests[j].finish <= requests[i].start) {
            return j;
        }
    }
    return -1;
}

// Function to compare two requests based on finish time
int compare(const void *a, const void *b) {
    struct Request *reqA = (struct Request *)a;
    struct Request *reqB = (struct Request *)b;
    return reqA->finish - reqB->finish;
}

// Function to find the maximum profit
int maxProfit(struct Request requests[], int n) {
    qsort(requests, n, sizeof(struct Request), compare);

    int *dp = (int *)malloc(n * sizeof(int));
    dp[0] = requests[0].value;

    for (int i = 1; i < n; i++) {
        int inclProf = requests[i].value;
        int l = latestNonConflict(requests, i);
        if (l != -1) {
            inclProf += dp[l];
        }
        dp[i] = inclProf > dp[i - 1] ? inclProf : dp[i - 1];
    }

    int result = dp[n - 1];
    free(dp);
    return result;
}

int main() {
    struct Request requests[] = {
        {1, 2, 100},
        {2, 5, 200},
        {3, 6, 300},
        {4, 8, 400},
        {5, 9, 500},
        {6, 10, 100}
    };
    int n = sizeof(requests) / sizeof(requests[0]);

    int maxProfitValue = maxProfit(requests, n);
    printf("Maximum profit: %d\n", maxProfitValue);

    return 0;
}

