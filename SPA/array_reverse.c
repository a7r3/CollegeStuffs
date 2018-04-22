#include<stdio.h>
/// Program to print contents of Array in reverse

void main()
{
    int i,n;
    char a[50];
    printf("\n\nEnter no. of elements\n\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%c",&a[i]);
    }
    for(;i>=0;i--)          // i = n-1 from last loop
    {
        printf("\n%c",a[i]);
    }
}
