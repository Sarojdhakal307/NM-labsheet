//Integration using Trapezoidal Rule
#include<stdio.h>
#include<math.h>
#define f(x) (pow(x,3)+2)
int main()
{
    float h, x0, x1, fx0, fx1, v;
    printf("Enter the lower and upper limit: ");
    scanf("%f %f", &x0, &x1);
    h = x1 - x0;
    fx0 = f(x0);
    fx1 = f(x1);
    v = (h/2)*(fx0+fx1);
    printf("\nThe value of integration is: %f", v);
     printf("\nBy Saroj Dhakal.");
    return 0;
}