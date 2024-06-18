//Jacobi Iteration
#include<stdio.h>
#include<math.h>

#define MAX 10
#define E 0.01
#define N 10

int main() 
{
    int i, j, k, n;
    float a[MAX][MAX], x[MAX], x0[MAX], residual[MAX], sum, max_residual;

    printf("Enter the number of unknowns: ");
    scanf("%d", &n);

    printf("Enter %dx%d elements for the augmented matrix:\n", n, n + 1);
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n + 1; j++) 
        {
            scanf("%f", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++) 
    {
        x0[i] = 0;  // Initialize initial guess vector with zeros
    }

    for (k = 0; k < N; k++) 
    {
        for (i = 0; i < n; i++) 
        {
            sum = 0;
            for (j = 0; j < n; j++) 
            {
                if (i != j) 
                {
                    sum += a[i][j] * x0[j];
                }
            }
            x[i] = (-sum + a[i][n]) / a[i][i]; // Jacobi iteration formula
        }

        // Calculate the residual vector
        max_residual = 0;
        for (i = 0; i < n; i++) 
        {
            residual[i] = fabs(x[i] - x0[i]);
            if (residual[i] > max_residual) 
            {
                max_residual = residual[i];
            }
        }

        // Check for convergence
        if (max_residual < E) 
        {
            break;
        }

        // Update the initial guess for the next iteration
        for (i = 0; i < n; i++) 
        {
            x0[i] = x[i];
        }
    }

    if (k == N) 
    {
        printf("Maximum number of iterations exceeded.\n");
    } 
    else 
    {
        printf("The solution set is:\n");
        for (i = 0; i < n; i++) 
        {
            printf("x[%d]=%.3f\n", i + 1, x[i]);
        }
    }

    printf("\nThe number of iterations: %d\n", k + 1);
     printf("\nBy Saroj Dhakal.");

    return 0;
}
