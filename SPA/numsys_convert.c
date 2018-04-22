// INPUTS: 73 1
/* Note: For compiling with the GCC pass the flags -lm
/* i.e. gcc -lm numsys_convert.c
    On GCC version 'gcc (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609'
    -l means an option to link a library
    m indicates the math lib (libm.so) */
/* Works fine with Turbo C */
#include<stdio.h>
#include<math.h>
/// Program to convert a Decimal number to either of their Binary, Octal, or Hexadecimal equivalents
void main()
{
	long int i,n,q,sb,base;
	printf("\n\nEnter a decimal no\n\n");
	scanf("%ld",&n);
	printf("\n\nSelect the base\n");
	printf("\nEnter 1 for Binary Conv\nEnter 2 for Octal Conv\nEnter 3 for Hexadecimal conv\n\n");
	scanf("%ld",&sb);
	switch(sb)
	{
		case 1:
			base=2;
			break;
		case 2:
			base=8;
			break;
		case 3:
			base=16;
			break;
		default:
			printf("\nInvalid Op\n");
			break;
	}
	//printf("%d",base); DEBUG
    /* 7 to keep the answer under 8 digits*/
	for(i=7;i>=0;i--)
	{
        /* pow(x,y) -> returns the value of x^y */
		q=n/(long int)pow(base,i);
		switch(q)
		{
            /* Hexadecimal system can have the remainders
                which are greater than 10 (why should 2 and 8 have :P). And these numbers
                are to be translated to their Hex equivalent */
			case 10:
				printf("A");
	            break;
			case 11:
				printf("B");
				break;
			case 12:
	            printf("C");
				break;
			case 13:
				printf("D");
				break;
			case 14:
				printf("E");
				break;
			case 15:
				printf("F");
				break;
			default:
				printf("%ld",q);
				break;
		}
		n=n%(long int)pow(base,i);
	}
    printf("\n\n");
}
