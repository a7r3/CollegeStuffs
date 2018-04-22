#include<stdio.h>
/// Program to reverse the rows a given n-order matrix

void main()
{
    int a[50][50],r1,c1,i,j,t;
    printf("\n\nSpecify the order for Matrix 1\n\n");
    scanf("%d%d",&r1,&c1);
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            scanf("%d",&a[i][j]);
        }
        printf("\n");
    }

    printf("\n\nRowReversing\n\n");
    for(i=0;i<r1/2;i++)
    {
        for(j=0;j<c1;j++)
        {
            t=a[i][j];
            a[i][j]=a[r1-i-1][j];
            a[r1-i-1][j]=t;
        }
    }

    printf("\n\nPrinting Reverse Matrix\n\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }

}
