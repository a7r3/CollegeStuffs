#include<stdio.h>
/// Program to print Fibonacci series upto user specified input 'n'
void main()
{
    int n1=0,n2=1,n3,n;
    printf("\n\nEnter the limit for Fibonacci series");
    scanf("%d",&n);
    printf("\n%d\n%d",n1,n2);
    while(n>2)
    {
        n3=n1+n2;   // (n)th num = (n-1)th num - (n-2)th num
        n1=n2;
        n2=n3;
        printf("%d\n",n3);
        n--;
    }
}
