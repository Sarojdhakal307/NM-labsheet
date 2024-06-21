//Doo-Little LU decomposition  
#include <stdio.h>
#include <conio.h>

int main() 
{
    int n, i, j, k;
    float sum = 0;
    float a[10][10], u[10][10], l[10][10];

    printf("Enter dimension of matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of matrix:\n");
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            scanf("%f", &a[i][j]);
        }
    }

    // Compute elements of L and U matrix
    for (j = 0; j < n; j++) 
    {
        u[0][j] = a[0][j];
    }

    for (i = 0; i < n; i++) 
    {
        l[i][i] = 1;
        l[i][0] = a[i][0] / u[0][0];
    }

    for (j = 1; j < n; j++) 
    {
        for (i = 1; i <= j; i++) 
        {
            for (k = 0; k <= i; k++) 
            {
                sum += l[i][k] * u[k][j];
            }
            u[i][j] = a[i][j] - sum;
            sum = 0;
        }
        for (i = j + 1; i < n; i++) 
        {
            for (k = 0; k <= j - 1; k++) 
            {
                sum += l[i][k] * u[k][j];
            }
            l[i][j] = (a[i][j] - sum) / u[j][j];
            sum = 0;
        }
    }

    printf("\n*****L matrix*****\n");
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            printf("%.2f\t", l[i][j]);
        }
        printf("\n");
    }

    printf("\n*****U matrix*****\n");
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            printf("%.2f\t", u[i][j]);
        }
        printf("\n");
    }

     printf("\nBy Saroj Dhakal.");

    return 0;
}
