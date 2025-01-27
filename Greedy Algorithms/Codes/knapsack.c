#include <stdio.h>
#define MAX_N 100
#define MAX_W 1000

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int values[], int weights[], int n, int W) {
    int i, j;
    int K[MAX_N+1][MAX_W+1];

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                K[i][j] = 0;
            } else if (weights[i-1] <= j) {
                K[i][j] = max(values[i-1] + K[i-1][j-weights[i-1]], K[i-1][j]);
            } else {
                K[i][j] = K[i-1][j];
            }
        }
    }
    return K[n][W];
}

int main() {
    int n, W, i;
    int values[MAX_N], weights[MAX_N];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the values and weights of the items:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &values[i], &weights[i]);
    }

    printf("Enter the maximum weight capacity: ");
    scanf("%d", &W);

    printf("The maximum value that can be obtained is: %d\n", knapsack(values, weights, n, W));
    return 0;
}
