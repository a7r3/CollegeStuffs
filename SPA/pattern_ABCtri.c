#include<stdio.h>
/// A Pattern printing program
/*
   A
  B C
 D E F
G H I J    */
void main()
{
    int i,j,sp;
    char alpha='A';
    for(i=1;i<=4;i++)
    {
        for(sp=3;sp>=i;sp--)
        {
            printf(" ");
        }
        for(j=1;j<=i;j++)
        {
            //        v--- That space is important!
            printf("%c ",alpha);
            alpha++;        // Increment ASCII value of alpha
        }
        printf("\n");       // Moving down the triangle
    }
}
