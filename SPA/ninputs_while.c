#include<stdio.h>
/// Take input from user and continue taking it if user enters 'Y' or 'y' as input
// For *NIX systems:
// Due to consideration of Carriage return in *nix systems, scanf has an escape sequence
// \r added.
// BUG: It accepts non-acceptable, single character input ONCE before exiting.
// More than one character input and it quits.
void main()
{
    char in='y';
//    printf("%d\n",in);
    while(in==89||in==121)
    {
        printf("\nWanna continue ?\n");
        // Non-Unix Systems, uncomment the next line and comment the second line below this
        //scanf("%c",&in);
        scanf("%c\r",&in);
    }
}
