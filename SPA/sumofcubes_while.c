#include<stdio.h>
/// Program to calculate the sum of cubes of 'n' numbers
void main()
{
    int a=1,b,n,sc=0;
    printf("\n\nEnter the number of inputs\n\n");
    scanf("%d",&n);
    while(a<=n)
    {
        printf("\n\nNumber %d\n",a);
        scanf("%d",&b);
        sc=sc+b*b*b;
        a++;
    }
    printf("\n\nSum of cubes of these numbers is : %d",sc);
}
