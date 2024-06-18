/*Composite Trapezoidal rule*/
#include<stdio.h>
#include<math.h>
#define MAX 10
#define f(x) sqrt((pow(x,2)+1))

int main()
{
    int i,n;
    float a,b,f[MAX],h,sum=0,Ig;
    printf("Enter the initial value of x: ");
    scanf("%f",&a);
    printf("Enter the final value of x: ");
    scanf("%f",&b);
    printf("Enter the no. of segments: ");
    scanf("%d",&n);
    h=(b-a)/n;
    for(i=0;i<=n;i++)
        f[i]=f(a+i*h);
    for(i=1;i<=n-1;i++)
        sum+=f[i];
    Ig=(h/2)*(f[0]+f[n]+2*sum);
    printf("\nThe integration is %f",Ig);
     printf("\nBy Saroj Dhakal.");

    return 0;
}
