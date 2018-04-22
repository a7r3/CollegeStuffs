#include<stdio.h>
/// Program to calculate Factorial
void main()
{
    int a,c,n;
    printf("\n\nEnter the number whose Factorial is to be calculated\n\n");
    scanf("%d",&n);
    a=1;            // Result
    c=n;            // Counter
    while(c>0)      // Until c>0 ==========vv
    {
        a=a*n;
        c--;        // Decrement Counter ==^^
    }
    printf("\nFactorial of %d : %d",c,a);
}
