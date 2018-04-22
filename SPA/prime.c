#include<stdio.h>
/// Program to check whether the given number is a prime number or not
void main()
{
    int i,n;
    printf("\n\nEnter a number\n\n");
    scanf("%d",&n);
    for(i=2;i=n/2;i++)
    {
        if(n%i==0 && n!=i) // If a number less than 'n' divides it perfectly, then it is composite
        {
            printf("\n\nThe given number %d is not prime\n\n",n);
            break; // get out of the iteration
        }
    }
    if(i==n/2) // If the iteration is complete
    {
        printf("\nThe given number is Prime\n\n");
    }
}
