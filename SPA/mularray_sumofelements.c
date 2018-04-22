#include<stdio.h>
/// Program to calculate the sum of elements using function
int sumofa(int a,int b,int x[a][b]);
void imat(int c,int d,int y[c][d]);

void main()
{
    int a[50][50],r,c;
    printf("\n\nSpecify the order of the Matrix (Rows*Columns)\n\n");
    scanf("%d%d",&r,&c);
    imat(r,c,a);
    printf("\n\nSum of elements of the Matrix is %d",sumofa(r,c,a));
}

int sumofa(int a,int b,int x[a][b])
{
    int sum=0,i,j;
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            sum+=x[i][j];
        }
    }
    return sum;
}

void imat(int c,int d,int y[c][d])
{
    int i,j;
    for(i=0;i<c;i++)
    {
        for(j=0;j<d;j++)
        {
            scanf("%d",&y[i][j]);
        }
    }
}
