#include<stdio.h>
/// Program to print Odd numbers upto 'n'
// 'n' - user defined input
void main()
{
    int a,n;
    printf("\n\nEnter a number\n");
    scanf("%d",&n);
    a=1;
    while(a<=n)
    {
        printf("%d\n",a);
        a=a+2;
    }
}
