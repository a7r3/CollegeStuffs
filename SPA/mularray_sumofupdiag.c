#include<stdio.h>
/// Program to calculate sum of upper diagonal elements of an array

void main()
{
    int n,i,j,sum=0,a[50][50];
    printf("\n\nEnter the order of the matrix (Singular)\n\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j>i)
                sum+=a[i][j];
            else
                continue;
        }
    }
    printf("\n\nSum of the upper diagonal elements is %d",sum);
}
