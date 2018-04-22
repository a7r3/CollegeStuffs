#include<stdio.h>
/// Program to calculate average of 'n' numbers provided by user

void main()
{
    // num, sum, counter, no. of obs, no. of inputs
    int a,b=0,i,c,n;
    float avg;
    printf("\n\nEnter the number of inputs\n");
    scanf("%d",&n);
    c=n; // Effective Number of Observations
    for(i=0;i<=n;i++)
    {
        printf("\nEnter your Input\n");
        scanf("%d",&a);
        if(a<0)
        {
            printf("\n\nNegative value %d not considered",a);
            c--; // Effective no of observations reduced by 1
            continue;
        }
        b+=a; // new(sum)=old(sum)+current(input)
    }
    avg=(float)b/c; // Calculate floating value of integers 'b' and 'c'
    printf("\n\nAverage of these numbers is : %f",avg);
}
