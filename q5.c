// 5.	Write a C program to interpolate using Lagrange's method.

// Algorithm:

// 	Enter the number of data points n and functional value f(x)
// 	Input xp value at which interpolation is required.
// 	Calculate n degree Lagrange’s Interpolation polynomial formula,
// Pn(x) = ∑_(i=0)^n▒〖f_i l_i (x)〗
// Where,
// li(x)=∏_(j=0,   j≠i)^n▒(x-x_j)/(x_i-x_j )
// 	Print the Result
// 	Stop

// Source Code:

//Lagrange's Interpolation
#include<stdio.h>
#include<math.h>
#include<conio.h>
#define MAX 10

int main()
{ 
    int i,j,n;
    float x[MAX],f[MAX],sum=0,pro,xp,fp;
    printf("Enter the number of data points: ");
    printf("\nn= "); scanf("%d",&n);
    for(i=0;i<n;i++)
    {  
        printf("\nInput the data points for x[%d]&f[%d]",i,i);
        printf("\nx[%d] = ",i);scanf("%f",&x[i]);
        printf("\nf[%d] = ",i);scanf("%f",&f[i]);
    }
    printf("\nInput the specified value of x: ");
    scanf("%f",&xp);
    for(i=0;i<=n;i++)
    {  
        pro=1.0;
        for(j=0;j<=n;j++)
        {
        if(i!=j)
            pro=pro*(xp-x[j])/(x[i]-x[j]);
        }
        sum=sum+pro*f[i];
    }
    fp=sum;
    printf("\nThe required functional value at %f = %f",xp,fp);
    getch();     
    return 0;
}
