#include<stdio.h>
/// Program to Search for an element in an Array

void main()
{
    int a[5]={0,7,3,5,2},n,i;
    printf("\nEnter the Element you want to Find (0-9)\nTry your luck\n");
    scanf("%d",&n);
    for(i=0;i<5;i++)
    {
        if(a[i]==n)
        {
            printf("\n\nElement %d found at place %d",a[i],i+1);
            break;
        }
        else
            continue;
    }
    if(i==5)
        printf("Element %d not found, Kbye",n);
}
