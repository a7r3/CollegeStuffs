/// Menu-Driven Program to imitate a Stack using an Array

#include<stdio.h>

void menu(int a[], int *n, int *op)
{
	int e,i;
	printf("\n============= Stack Emulator ===============");
	printf("\nSpecify the operation you want to perform\n");
	printf("1 - Push an Element\n");
	printf("2 - Pop an Element\n");
	printf("3 - Show the Stack\n");
	printf("4 - EXIT\n");
	printf("============================================");
	printf("\n[>] ");
	scanf("%d",op);
	switch(*op)
	{
		case 1:
			if(*n>=10)
			{
				 printf("\nStackOverflowTM\n\nStack FULL, cannot add element");
				 printf("\nAborting\n");
			}
			else
			{
				printf("\n\nSpecify the Element to be inserted\n");
				scanf("%d",&e);
				a[(int)*n]=e;
				(*n)++;
				printf("\n\nElement inserted into the stack\n\n");
			}
			break;
		case 2:
			printf("Deleting Topmost Element %d at Position %d",a[*n-1],*n-1);
			a[(int)*n-1]=0;
			printf("\nDeleted Element Successfully\n\n");
			(*n)--;
			printf("%d",*n);
			break;
		case 3:
			printf("\n\nPrinting Stack Elements");
			for(i=*n-1;i>=0;i--)
				printf("\n| %d |",a[i]);
			printf("\n-------");
			printf("\n");
			break;
		case 4:
			break;
		default:
			printf("\nInvalid Selection\n");
			break;
	}
}

void main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,0};
	int n=10, op=0;
	while(op!=4)
		menu(a,&n,&op);
	// Uncomment if you're using TC
	// getch();
}
