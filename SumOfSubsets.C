//Sum of Subsets
#include <stdio.h>

#define MAX_SIZE 100

// Function to check if there is a subset with given sum
int isSubsetSum(int set[], int n, int sum) {
int i;    // Base Cases
    if (sum == 0)
    return 1;
    if (n == 0 && sum != 0)
    return 0;

    // If last element is greater than sum, then ignore it
    if (set[n - 1] > sum)
    return isSubsetSum(set, n - 1, sum);

    // Check if sum can be obtained by including the last element or excluding it
    return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
}

// Function to find subsets with the given sum
void findSubsets(int set[], int n, int sum, int subset[], int subsetSize, int idx) {
int i;
    if (sum == 0) {
    // Print the subset
    printf("Subset found: ");
    for (i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }

    if (idx == n)
        return;

    // Include the current element
    subset[subsetSize] = set[idx];
    findSubsets(set, n, sum - set[idx], subset, subsetSize + 1, idx + 1);

    // Exclude the current element
    findSubsets(set, n, sum, subset, subsetSize, idx + 1);
}

int main() {
    int set[] = {10, 7, 5, 18, 12, 20, 15};
    int n = sizeof(set) / sizeof(set[0]);
    int sum = 35;
    int subset[MAX_SIZE];
    if (isSubsetSum(set, n, sum)) {
    printf("Subset with sum %d exists.\n", sum);
    findSubsets(set, n, sum, subset, 0, 0);
    } else {
        printf("No subset with sum %d exists.\n", sum);
    }

    return 0;
}
