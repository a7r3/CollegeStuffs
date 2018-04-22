#include<stdio.h>
/// Program to calculate the sum of elements of a Matrix using function
int sumofa(int c,int d,int x[c][d]);
void imat(int e,int f,int y[e][f]);

void main()
{
    int a[50][50],r,c;
    printf("\n\nSpecify the order the matrix (Rows*Colums)\n\n");
    scanf("%d%d",&r,&c);
    imat(r,c,a);
    printf("\n\nSum of Elements of the Matrix is %d",sumofa(r,c,a));
}

int sumofa(int c,int d,int x[c][d])
{
    int sum=0,i,j;
    for(i=0;i<c;i++)
    {
        for(j=0;j<d;j++)
        {
                sum+=x[i][j];
        }
    }
    return sum;
}

void imat(int e,int f,int y[e][f])
{
    int k,l;
    for(k=0;k<e;k++)
    {
        for(l=0;l<f;l++)
        {
            scanf("%d",&y[k][l]);
        }
    }
}
