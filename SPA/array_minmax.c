#include<stdio.h>
/// Program to Find minimum and maximum values in Array

void main()
{
    int a[50],n,min=0,max=0,i,j;
    printf("\n\nEnter the number of elements");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(a[j]>max)
            max=a[i];
        if(a[j]<min)
            min=a[i];
    }
    printf("\nMinimum is %d\nMaximum is %d",min,max);
}
