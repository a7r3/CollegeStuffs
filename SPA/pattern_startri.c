#include<stdio.h>
/// Pattern printing program
/*
   *
  * *
 * * *
* * * *    */
void main()
{
    int i,j,sp;
    for(i=1;i<=4;i++)
    {
        for(sp=3;sp>=i;sp--)
        {
            printf(" ");
        }
        for(j=1;j<=i;j++)
        {
            //        v--- That space is important!
            printf("* ");
        }
        printf("\n");       // Moving down the triangle
    }
}
