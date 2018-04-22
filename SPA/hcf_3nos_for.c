#include<stdio.h>
/// Program to calculate GCD of two given numbers
// Logic : GCD will be always less than or equal the smallest number
// So Initialize a counter of value equal to smallest number
// Try to divide both the numbers by the counter
//      If Remainder of both the divisions is zero, then that is the
//      greatest common factor of both these numbers
//      If either of the divisions has a non-zero remainder, then continue
//      the Iteration
void main()
{
    int a,b,c,less;
    printf("\n\nEnter three numbers\n\n");
    scanf("%d%d%d",&a,&b,&c);
    if(a<b && a<c)
    {
        less=a;
    }
    else if(b<a && b<c)
    {
        less=b;
    }
    else if (c<a && c<b)
    {
        less=c;
    }
    for(;less>0;less--)
    {
        // If (The number divides all three numbers perfectly)
        if(b%less==0 && a%less==0 && c%less==0)
        {   // then Victory
            printf("\nGCD is %d",less);
            break;
        }
        else
        {   // Don't lose hope and...
            continue;
        }
    }
}
