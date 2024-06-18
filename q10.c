/*Simpson's 1/3 Rule*/
#include<stdio.h>
#include<math.h>
#define f(x) (sin(x))

int main()
{
    int i,n=2;
    float a,b,f[3],h,Ig;
    printf("Enter the initial value of x: ");
    scanf("%f",&a);
    printf("Enter the final value of x: ");
    scanf("%f",&b);
    h=(b-a)/n;
    for(i=0;i<=n;i++)
        f[i]=f(a+i*h);
    Ig=(h/3)*(f[0]+f[n]+4*f[1]);
    printf("\nThe integration is %f",Ig);
     printf("\nBy Saroj Dhakal.");

    return 0;
}
