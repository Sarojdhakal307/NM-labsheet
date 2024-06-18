//Romberg Integration
#include<stdio.h>
#include<math.h>
#define f(x) (1/(x))
int main()
{
    float x0, xn, T[10][10], h, sm, sl, a;
    int i, k, c, r, m, p, q;
    printf("Enter Lower and Upper limit: ");
    scanf("%f %f", &x0 , &xn);
    printf("Enter p & q of required T(p,q):");
    scanf("%d %d", &p, &q);
    h = xn - x0;
    T[0][0] = (h/2)*(f(x0)+f(xn));
    for ( i = 1; i <= p; i++)
    {
        sl = pow(2,i-1);
        sm = 0;
        for (k = 1; k <= sl; k++)
        {
            a = x0 + (((2*k-1)*h)/pow(2,i));
            sm = sm + (f(a));
        }
        T[i][0] = T[i-1][0]/2+sm*h/pow(2,i);
    }
    for ( c = 1; c<=p; c++)
    {
        for (k = 1; k<=c && k<=q; k++)
        {
            m = c- k;
            T[m+k][k] = (pow(4,k)*T[m+k][k-1]-T[m+k-1][k-1])/(pow(4,k)-1);
        }
    }
    printf("\nRomberg Estimate of Integration = %f\n", T[p][q]);
     printf("\nBy Saroj Dhakal.");

    return 0;
}