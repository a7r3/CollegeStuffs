#include<stdio.h>
/// Program to calculate sum of digits of 5 digit number
void main()
{
    int a,b,r,sum;
    printf("\n\nEnter a FIVE digit number\n\n");
    scanf("%d",&a);
    sum=0;
    for(b=1;b<=5;b++)
    {
        r=a%10;
        a=a/10;
        sum=sum+r;
    }
    printf("\n\nSum of digits of the entered number : %d\n",sum);
}
