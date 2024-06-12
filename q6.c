// 6.	Write a C program to interpolate usin`g Newton’s Divided difference method.

// Algorithm:

// 1.	Enter the number of data points n and the functional value f(x)
// 2.	Compute n divided difference terms as a0, a1, a2, a3, …
// 3.	Input xp value at which interpolation is required.
// 4.	Compute n degree Newton Interpolation Polynomial formula as
// Pn(x) = a0+a1(x-x0)+a2(x-x0)(x-x1)+ …
// 5.	Print the result
// 6.	Stop

// Source Code:

//Newton Interpolation#include <stdio.h>
#include<stdio.h>
#include<math.h>
#include<conio.h>
#define MAX 10

void main()
{  
    int i,j,n;
    float xp,fp,x[MAX],f[MAX],d[MAX][MAX],pro,sum=0,a[MAX];
    printf("Enter the number of data points:\nn = ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {  
        printf("\nInput the data of x[%d]&f[%d]",i-1,i-1);
        printf("\nx[%d]= ",i-1); scanf("%f",&x[i]);
        printf("\nf[%d]= ",i-1);scanf("%f",&f[i]);
    }
    for(i=1;i<=n;i++)
        d[i][1]=f[i];
    for(j=2;j<=n;j++)
        for(i=1;i<=n-j+1;i++)
            d[i][j]=(d[i+1][j-1]-d[i][j-1])/(x[i+j-1]-x[i]);
    for(j=1;j<=n;j++)
        a[j]=d[1][j];
    printf("Enter the value of xp point : ");
    scanf("%f",&xp);
    sum=a[1];
    for(i=2;i<=n;i++)
    {  
        pro=1.0;
        for(j=1;j<=i-1;j++)
            pro=pro*(xp-x[j]);
        sum=sum+a[i]*pro;
    }
    fp=sum;
    printf("\nAt xp=%f, fp = %f",xp,fp);
    getch();
}
