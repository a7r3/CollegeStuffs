#include<stdio.h>
/// Program to calculate the Multiplication of two Matrices
void iomat(int a,int b,int x[a][b],int op);
void matmul(int ry, int cy,int cz,int y[ry][cy],int z[cy][cz],int r[ry][cz]);


void main()
{
    int a[50][50],b[50][50],r1,c1,r2,c2,c[50][50];
    printf("\n\nSpecify the order for Matrix 1\n\n");
    scanf("%d%d",&r1,&c1);
    printf("\n\nSpecify the order for Matrix 2\n\n");
    scanf("%d%d",&r2,&c2);
    if(c1!=r2)
        goto hell;
    iomat(r1,c1,a,1);
    iomat(r2,c2,b,1);
    printf("\n\nPerforming Matrix Multiplication\n\n");
    matmul(r1,c1,c2,a,b,c);
    printf("\n\nThe Multiplication Matrix is\n\n");
    iomat(r1,c2,c,0);
    hell: getchar();
}

void iomat(int a,int b,int x[a][b],int op)
{
    int i,j;
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            if(op)
                    scanf("%d",&x[i][j]);
            else
                    printf("%d\t",x[i][j]);
        }
        printf("\n");
    }
}

void matmul(int ry, int cy,int cz,int y[ry][cy],int z[cy][cz],int r[ry][cz])
{
    int i,j,k;
    for(i=0;i<ry;i++)
    {
        for(j=0;j<cz;j++)
        {
            for(k=0;k<cy;k++)
            {
                r[i][j]+=y[i][k]*z[k][j];
            }
        }
    }
}
