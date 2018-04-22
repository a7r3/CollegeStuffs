#include<stdio.h>
/// Program to check whether the given matrix is a Magic matrix

void main()
{
	int a[50][50],m=0,i,j,k,n;
	printf("\n\nEnter the number of elements\n\n");
	scanf("%d",&n);
	printf("\n\nEnter the Elements for %dx%d\n\n",n,n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);

	for(k=1;k<=n*n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[i][j]==k)
				{
					m++;
					break;
				}
				else
					continue;
			}

		}
	}

	if(m==n*n)
		printf("\n\nThe Given Matrix is a Magic Square\n\n");
	else
		printf("\n\nNo Magic :(\n\n");
}
