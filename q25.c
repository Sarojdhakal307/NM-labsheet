//Poisson's Equation
#include <stdio.h>
#include <math.h>

#define MAX 10
#define ERROR 0.01

// Function to calculate the source term g(x, y) = 2 * x^2 * y^2
float calculateSourceTerm(float x, float y) {
    return 2 * x * x * y * y;
}

int main() {
    int n, m, i, j;
    float sum, maxError, new_x[MAX+2][MAX+2], old_x[MAX+2][MAX+2];
    float tl, tr, tu, tb;
    float source[MAX+2][MAX+2]; // Source term

    printf("Enter length and width of the plate: ");
    scanf("%d %d", &m, &n);

    printf("Enter number of grid points (n for nxn grid): ");
    scanf("%d", &n);

    printf("Enter temperatures at left, right, bottom, and upper part of the plate respectively: ");
    scanf("%f %f %f %f", &tl, &tr, &tb, &tu);

    float dx = (float)m / (n + 1); // Grid spacing in x direction
    float dy = (float)m / (n + 1); // Grid spacing in y direction

    // Initialize grid points with boundary conditions and source term
    for (i = 0; i <= n+1; i++) {
        for (j = 0; j <= n+1; j++) {
            if (i == 0) {
                new_x[i][j] = tb; // bottom boundary
            } else if (i == n+1) {
                new_x[i][j] = tu; // top boundary
            } else if (j == 0) {
                new_x[i][j] = tl; // left boundary
            } else if (j == n+1) {
                new_x[i][j] = tr; // right boundary
            } else {
                new_x[i][j] = 0.0; // initial guess for internal points
            }
            old_x[i][j] = new_x[i][j];
            
            // Calculate the source term at each grid point
            float x = i * dx;
            float y = j * dy;
            source[i][j] = calculateSourceTerm(x, y);
        }
    }

    // Gauss-Seidel Iteration
    do {
        maxError = 0.0;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                sum = 0.25 * (new_x[i+1][j] + new_x[i-1][j] + new_x[i][j+1] + new_x[i][j-1]) - source[i][j] * dx * dy / 4.0;
                float error = fabs(sum - new_x[i][j]);
                if (error > maxError) {
                    maxError = error;
                }
                new_x[i][j] = sum;
            }
        }

        // Update old_x for next iteration
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                old_x[i][j] = new_x[i][j];
            }
        }
    } while (maxError > ERROR);

    // Print the resulting four corner values
    printf("Top-left corner: %.2f\n", new_x[1][1]);
    printf("Top-right corner: %.2f\n", new_x[1][n]);
    printf("Bottom-left corner: %.2f\n", new_x[n][1]);
    printf("Bottom-right corner: %.2f\n", new_x[n][n]);
     printf("\nBy Saroj Dhakal.");

    return 0;
}
