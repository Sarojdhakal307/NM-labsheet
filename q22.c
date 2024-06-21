//Gauss Seidel Iteration
#include <stdio.h>
#include <math.h>

#define Error 0.01

int main() {
    int n, i, j, k;
    float sum, error, maxError, a[10][10], b[10], new_x[10], old_x[10];

    printf("Enter the dimension of system of equations: ");
    scanf("%d", &n);

    printf("Enter coefficients row-wise: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter B vector: \n");
    for (i = 0; i < n; i++) {
        scanf("%f", &b[i]);
    }

    for (i = 0; i < n; i++) {
        new_x[i] = 0.0; // Initial guess
    }

    while (1) {
        maxError = 0.0;
        for (i = 0; i < n; i++) {
            sum = b[i];
            for (j = 0; j < n; j++) {
                if (i != j) {
                    sum -= a[i][j] * new_x[j];
                }
            }

            if (fabs(a[i][i]) < 1e-6) {
                printf("Division by zero detected. The matrix may be singular or poorly scaled.\n");
                return -1;
            }

            old_x[i] = new_x[i];
            new_x[i] = sum / a[i][i];
            error = fabs((new_x[i] - old_x[i]) / new_x[i]);
            if (error > maxError) {
                maxError = error;
            }
        }

        if (maxError < Error) {
            break;
        }
    }

    printf("Solution: \n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i + 1, new_x[i]);
    }
     printf("\nBy Saroj Dhakal.");


    return 0;
}
