#include<stdio.h>
/// Program to calculate sum of two matrices, 2x2

void main()
{
    int i,j,a[2][2],b[2][2];
    printf("\n\nEnter 4 elements of 1st Matrix\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("\na%d%d : ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("\n\nEnter 4 elements of 2nd Matrix\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("\na%d%d : ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("\n\nSum of Matrices is...\n\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%d",a[i][j]+b[i][j]);
        }
        printf("\n");
    }
}
