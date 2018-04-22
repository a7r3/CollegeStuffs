#include<stdio.h>
/// Program to evaluate transpose of a multidim array
void iomat(int a,int b,int x[a][b],int op);
void transposeof(int r,int c,int mata[r][c],int matb[c][r]);

int main()
{
	int r=0,c=0,a[10][10],b[10][10];
	printf("\n\nEnter the order of the matrix\n\n");
	scanf("%d%d",&r,&c);
	iomat(r,c,a,1);
	printf("\n\nBuilding Transpose Matrix\n\n");
	transposeof(r,c,a,b);
	if(r!=c)
		iomat(c,r,b,0);
	else
		iomat(c,r,a,0);
	return 0;
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

void transposeof(int r,int c,int mata[r][c],int matb[c][r])
{
	int i,j,t;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(r==c)
			{
				if(i>j)
				{
					t=mata[i][j];
					mata[i][j]=mata[j][i];
					mata[j][i]=t;
				}
			}
			else
			{
				matb[j][i]=mata[i][j];
			}
		}
	}
}
