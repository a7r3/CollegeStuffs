#include<stdio.h>
/// Program to print 'n' numbers
// n is user specified
void main()
{
    int c=1,n;
    printf("\n\nHow many numbers should I print ?\n");
    scanf("%d",&n);
    while(c<=n)
    {
        printf("\n%d",c);
        c++;
    }
}
