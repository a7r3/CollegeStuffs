#include<stdio.h>
/// Program to calculate sum of n numbers
int sumof(int a);

void main()
{
    int n;
    printf("\n\nEnter a number\n\n");
    scanf("%d",&n);
    printf("\n\nSum of numbers upto %d is %d",n,sumof(n));
}

int sumof(int a)
{
    if(a>0)
        return a+(--a);
    else
        return 0;
}

/* How this works ?
Suppose given argument is 5

sumof(5) says: I'd return
5 + sumof(--5) = 5 + sumof(4)
sumof(4) says: I'd return
4 + sumof(--4) = 4 + sumof(3)
sumof(3) says: I'd return
3 + sumof(--3) = 3 + sumof(2)
sumof(2) says: I'd return
2 + sumof(--2) = 2 + sumof(1)
sumof(1) says: I'd return
1 + sumof(--1) = 1 + sumof(0)
sumof(0) says: but, but a>0 is not satisfied, so I'd return
1

Now, going from bottom to top...

sumof(5)
|
5 + sumof(4)
|
5 + (4 + sumof(3))
|
5 + 4 + (3 + sumof(2))
|
5 + 4 + 3 + (2 + sumof(1))
|
5 + 4 + 3 + 2 + (1 + sumof(0))
|
5 + 4 + 3 + 2 + 1 + 0
|
15
|
Profit!

*/
