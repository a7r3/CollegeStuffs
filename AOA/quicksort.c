#include<stdio.h>
#define RED "\x1b[31m"
#define NONE "\x1b[0m"

void quickSort(int x[10], int lb, int ub);
int partition();

void main()
{
	int a[10], n, i;
	printf("\nEnter the no. of Elements\n");
	scanf("%d",&n);
	printf("\nEnter %d Elements\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quickSort(a,0,n-1);
	printf(RED"\n\nSorted Array\n"NONE);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}

void quickSort(int x[10], int lb, int ub)
{
	// Pivot Position
	int j, i;
	// If there are ONE or NONE elements to the left, we're done
	if(lb < ub) {
		// Get the Pivot Position
		j = partition(x, lb, ub);

		// DEBUG STATEMENTS
		// Indicate the Next Iteration, with the new Pivot
		//
		//printf("\n");
		//for(i=lb;i<j;i++)
		//	printf("%d ", x[i]);
		//
		//printf(RED "%d " NONE, x[j]);
		//
		//for(i=j+1;i<=ub;i++)
		//	printf("%d ", x[i]);
		//
		//printf("\n");
		//

		// Recursive call to Left and Right SubArrays (w.r.t Pivot)
		quickSort(x, lb, j-1);
		quickSort(x, j+1, ub);
	}
}

int partition (int A[], int start , int end) {
    int i = start + 1;
    int piv = A[start];
    int t, j;
    for(j =start + 1; j <= end ; j++ )
    {
          if (A[j] < piv) {
            t = A[j];
            A[j] = A[i];
            A[i] = t;
            i += 1;
        }
    }
    t = A[start] ,
    A[start] = A[i-1];
    A[i-1] = t;

    return i-1;
}
