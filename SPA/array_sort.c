#include<stdio.h>
/// Program to arrange 'n' elements in Ascending and Descending order

void main()
{
    int a[50],i,j,k,l,n,t;
    printf("\n\nEnter the number of elements");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(j=0;j<n-1;j++)
    {
        for(k=j;k<=n;k++)
        {
            if(a[k]>a[k+1])
            {
                t=a[k];
                a[k]=a[k+1];
                a[k+1]=t;
            }
        }
    }
    // Printing time
    printf("\n\nAscending Order\n\n");
    for(l=0;l<n;l++)
    {
        printf("%d\n",a[l]);
    }
    printf("\n\nDescending Order\n\n");
    for(;l>=0;l--)
    {
        printf("%d\n",a[l]);
    }
}
