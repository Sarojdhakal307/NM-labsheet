//Composite Simpson's 1/3 rule
#include<stdio.h>
#include<math.h>
#define f(x) 1/(1+x)
int main()
{
    float a, h, x0, xn, fx0, fxn, term, v;
    int i, k;
    printf("Enter Lower and Upper Limits: ");
    scanf("%f %f", &x0, &xn);
    printf("\nEnter the number of segments: ");
    scanf("%d", &k);
    h = (xn - x0)/k;
    fx0 = f(x0);
    fxn = f(xn);
    term = f(x0)+f(xn);
    for (i=1; i<=k-1; i=i+2)
    {
        a = x0+i*h;
        term = term + 4*(f(a));
    }
    for (i = 2; i <= k-2 ; i = i+2)
    {
        a = x0+i*h;
        term = term + 2*(f(a));
    }
    v = (h/3)*term;
    printf("\nValue of Integration = %f", v);
     printf("\nBy Saroj Dhakal.");

    return 0;
}