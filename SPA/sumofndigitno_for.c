#include<stdio.h>
/// Program to calculate sum of 'n' digit number
void main()
{
    int num,r,sum=0;
    printf("\n\nEnter a number\n\n");
    scanf("%d",&num);
    for(;num>0;num=num/10)
    {
        r=num%10;
        sum=sum+r;
    }
    printf("\n\nSum of digits of the given n-digit number is : %d",sum);
}
