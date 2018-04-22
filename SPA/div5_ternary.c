// INPUTS: 115
#include<stdio.h>
/// Program which makes use of ternary operator
void main()
{
    int num;
    printf("\n\nEnter a number\n\n");
    scanf("%d",&num);
    (num%5==0)?printf("\nThe number is divisible by 5"):printf("\nThe number is indivisible by 5");
}
