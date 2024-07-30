#include <stdio.h>
#include <stdlib.h>

// Function to compare integers, used for sorting
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to calculate the minimum number of days
int minDays(int *ratings, int N, int K) {
    qsort(ratings, N, sizeof(int), compare); // Sort the ratings in ascending order
    int days = 0;
    int i = 0;

    while (i < N) {
        days++; // Start a new day
        int prevRating = ratings[i]; // The first problem solved on this day
        int j = i + 1;

        // Add problems to the same day if the rating difference condition is met
        while (j < N && ratings[j] - prevRating >= K) {
            prevRating = ratings[j];
            j++;
        }
        i = j; // Move to the next problem for the new day
    }

    return days;
}

int main() {
    int T;
    scanf("%d", &T); // Read the number of test cases

    for (int t = 0; t < T; t++) {
        int N, K;
        scanf("%d %d", &N, &K); // Read N and K for the current test case

        int *ratings = (int *)malloc(N * sizeof(int)); // Allocate memory for the ratings array
        for (int i = 0; i < N; i++) {
            scanf("%d", &ratings[i]); // Read the ratings
        }

        int result = minDays(ratings, N, K); // Calculate the minimum days
        printf("%d\n", result); // Output the result

        free(ratings); // Free the allocated memory
    }

    return 0;
}
