#include<stdio.h>
/// Program which checks whether a number is an Armstrong number or not
long int cubeof(int p);
int armcheck(int a);

void main()
{
    int n;
    printf("\n\nEnter a number\n\n");
    scanf("%d",&n);
    if(armcheck(n)==1)          // Function says it is Armstrong
        printf("\n%d is an Armstrong number",n);
    else
        printf("\n%d is NOT an Armstrong number",n);
}

long int cubeof(int p)
{
    return p*p*p;
}

int armcheck(int a)
{
    int num=a,sum=0,r;
    for(;num>0;num=num/10)
    {
        r=num%10;               // Extract the Last Digit
        sum=sum+(cubeof(r));    // Raise it to 3 and Add it to "sum"
    }
    if(a==sum)                  // Armstrong Condition : 1^3+5^3+3^3 = 153 (number) ?
        return 1;               // Yes it is
    else
        return 0;               // No it is not
}
