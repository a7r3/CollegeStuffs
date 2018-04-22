#include<stdio.h>
/// Program to check whether the given number is a prime number or not
void primecheck(int a, int o);

void main()
{
    int n;
    printf("\n\nEnter a number\n\n");
    scanf("%d",&n);
    primecheck(n,n);
}

void primecheck(int a, int o)
{
    if(a>0)
    {
        if(o%a!=0)              // If number (which is less than original number) doesn't completely divide n
            primecheck(--a,o);  // then move on by passing the first argument to be less than the number by 1
        else
            printf("\n%d is NOT prime\n",o);
    }
    else
    {
        printf("\n%d IS a Prime number\n",o);
    }
}
