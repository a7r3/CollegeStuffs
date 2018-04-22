#include<stdio.h>
/// Program which Assigns grades according to your marks
void main()
{
    float marks;
    printf("\nEnter your marks\n");
    scanf("%f",&marks);
    if (marks<40)
    {
        printf("\nFAIL");
    }
    else if (marks>=40 && marks<60)
    {
        printf("\nPASS");
    }
    else if (marks>=60 && marks<=80)
    {
        printf("\nOutstanding");
    }
}
