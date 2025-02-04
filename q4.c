// 4.	Write a C program to find root of nonlinear equation using fixed point iteration method.c

//Fixed point method
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 20
#define E 0.0001
#define g(x) (exp(x)-2) //exp(x)-x-2=0, x=exp(x)-2

int main()
{   int count=1;
    float x0,x1,error;
    printf("Enter the initial guess value. ");
    scanf("%f",&x0);
    begin:
        x1=g(x0), error=x1-x0;
        if(fabs(error)<E)
        {
            printf("The root is %f",x1);
            printf("\nNo. of iterations is %d",count);
        }
        else
        {
            x0=x1;
            count++;
            if(count<MAX) goto begin;
            else
                printf("The process doesn\'t converge.");
        }

     printf("\nBy Saroj Dhakal.");

    return 0;
}

