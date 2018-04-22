#include<stdio.h>
/// Program to calculate GCD of two given numbers
// Logic : GCD will be always less than or equal to the smallest number
// So Initialize a counter of value equal to smallest number
// Try to divide both the numbers by the counter
//      If Remainder of both the divisions is zero, then that is the
//      greatest common factor of both these numbers
//      If either of the divisions has a non-zero remainder, then continue
//      the Iterations
void main()
{
    int a,b,less;
    printf("\n\nEnter two numbers\n\n");
    scanf("%d%d",&a,&b);
    if(a>b)
        less=b;
    else
        less=a;
    for(;less>0;less--)
    {
        // The number divides both a and b perfectly
        if(b%less==0 && a%less==0)
        {
            printf("\nGCD is %d",less);
            break;
        }
        else
        {
            continue;
        }
    }
}
