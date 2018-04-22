#include<stdio.h>
/// Program To calculate sum of the series
// (1!/1)+(2!/2)+(3!/3)+.....+(n!/n)
void main()
{
    int a,b,c=1,n,sum=0;
    printf("\n\nEnter the number\n\n");
    scanf("%d",&n);
    for(a=1;a<=n;a++)
    {
        c=1;
        for(b=1;b<=a;b++)
        {
            c=c*b;
        }
        sum=sum+(c/a);
    }
    printf("\n\nSum of series upto %d is : %d\n",n,sum);
}
