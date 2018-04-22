#include<stdio.h>
/// Program to calculate Factorial
long int fact(int a);

void main()
{
    int a,c,n;
    printf("\n\nEnter the number whose Factorial is to be calculated\n\n");
    scanf("%d",&n);
    printf("\nFactorial of %d is %ld",n,fact(n));
}

long int fact(int a)
{
    if(a>0)
        return a*fact(--a);
    else
        return 1;
}

/* How this works ?

fact returns a long int value
Suppose argument is 5

fact(5) says: I'd *return*...
5 * fact(--5) = 5 * fact(4)
fact(4) says: I'd *return*...
4 * fact(--4) = 4 * fact(3)
fact(3) says: I'd *return*...
3 * fact(--3) = 3 * fact(2)
fact(2) says: I'd *return*...
2 * fact(--2) = 2 * fact(1)
fact(1) says: I'd *return*...
1 * fact(--1) = 1 * fact(0)
fact(0) says: (a>0 condition is false, so 1 is returned)
1

Going from Bottom to top...

Answer returned would be

5 * fact(4)
|
5 * (4 * fact(3))
|
5 * 4 * (3 * fact(2))
|
5 * 4 * 3 * (2 * fact (1))
|
5 * 4 * 3 * 2 * (1 * fact(0))
|
5 * 4 * 3 * 2 * 1 * 1
|
120
|
Profit!

*/
