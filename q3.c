//secant method 
#include <stdio.h>
#include <math.h>

#define MAX_ITER 20
#define EPSILON 0.0001
#define f(x) (exp(x)-x-2)

int main() {
    int count = 1;
    float x1, x2, x3, f1, f2;
    
    printf("Enter two initial guess values: ");
    scanf("%f%f", &x1, &x2);
    
begin:
    f1 = f(x1);
    f2 = f(x2);
    x3 = x2 - f2 * (x2 - x1) / (f2 - f1);
    
    if (fabs((x3 - x2) / x3) < EPSILON) {
        printf("The root is %f\n", x3);
        printf("Number of iterations: %d\n", count);
    } else {
        x1 = x2;
        f1 = f2;
        x2 = x3;
        count++;
        if (count < MAX_ITER) 
            goto begin;
        else
            printf("The process doesn't converge.\n");
    }
    
     printf("\nBy Saroj Dhakal.");

    return 0;
}
