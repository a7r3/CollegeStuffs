#include<stdio.h>
/// A Pattern printing program
void main()
{
    int i,j;
    for(i=1;i<=5;i++)
    {
        if(i%2!=0) // If not even row
        {
            for(j=1;j<=i;j++)
            {
                // then print ascending series
                printf("%d",j);
            }
        }
        else
        {
            for(j=i;j>0;j--)
            {
                // then print descending series
                printf("%d",j);
            }
        }
        printf("\n");
    }
}
