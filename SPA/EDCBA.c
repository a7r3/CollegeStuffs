#include<stdio.h>
/// A Pattern Program
void main()
{
    int i,j;
    for(i=1;i<=5;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%c",(char)(70-j));
        }
        printf("\n");
    }
}
