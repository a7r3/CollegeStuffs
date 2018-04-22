#include<stdio.h>
/// Program to calculate reverse of a number using Recursion
void reverse(int a);

void main()
{
    int n;
    printf("\nEnter a number\n");
    scanf("%d",&n);
    reverse(n);
}

void reverse(int a)
{
    if(a>0)
    {
        printf("%d",a%10);  // Print the last digit of the number
        reverse(a/10);
        // Call the function with argument divided by 10,
        // so that we could extract the next digit on the next run
    }
}
