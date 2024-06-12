// 1.	Write a C program to find root of nonlinear equation using bisection method.

//Bisection Method
#include <stdio.h>
#include <math.h>
#define MAX 20
#define E 0.00001
#define f(x) (x*x - 4*x - 10)

int main() {
    int count = 0;
    float x1, x2, x0;
    printf("Enter the initial guess values x1 and x2\n");
    scanf("%f %f", &x1, &x2);

    if (f(x1) * f(x2) > 0) {
        printf("The guess values don't bracket the root. Change the guess values.\n");
    } else {
        while (count < MAX) {
            x0 = (x1 + x2) / 2;
            if (fabs(f(x0)) < E) {
                printf("\nThe root is %f", x0);
                printf("\nNumber of iterations is %d", count);
                return 0;
            } else {
                if (f(x0) > 0) {
                    x2 = x0;
                } else if (f(x0) < 0) {
                    x1 = x0;
                }
                count++;
            }
        }
        printf("\nThe process doesn't converge.\n");
    }
    return 0;
}
