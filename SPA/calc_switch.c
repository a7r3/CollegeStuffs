// INPUTS: 5 3 -
#include<stdio.h>
/// Program to play with numbers
void main()
{
    float a,b;
    char op;
    printf("\nEnter two numbers\n");
    scanf("%f%f",&a,&b);
    printf("\nEnter the operation you want to perform");
    scanf("%s",&op);
    switch(op)
    {
        case '+':
            printf("\nAddition is %f",a+b);
            break;
        case '-':
            printf("\nSubtraction is %f",a-b);
            break;
        case '/':
            printf("\nDivision is %f",a/b);
            break;
        case '*':
            printf("\nMultiplication is %f",a*b);
            break;
        default:
            printf("\nInvalid operation : %c",op);
    }
}
