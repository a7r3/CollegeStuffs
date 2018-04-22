/// Program to Validate Bracket Expressions
#include<stdio.h>

// Maximum No. of elements
#define MAX 20
// Bracket Stack
char st[MAX];

int isValid(char x[]);
int isOpening(char x);
int isClosing(char x);
int isMatching(char x);
void push(char x);
char pop();
int top=-1;

void main()
{
	char exp[MAX];
	printf("\nSpecify the Bracket-Expression\n");
	scanf("%s",exp);
	if(isValid(exp))
		printf("\nExpression is VALID\n");
	else
		printf("\nExpression is Invalid\n");
}

int isValid(char x[MAX])
{
	int i=0;
	// While we don't reach the end of the road
	while(x[i]!='\0')
	{
		if(isOpening(x[i])) // Opening Bracket ?
		{
			push(x[i]); // YES. Push it
			i++; // Move on
		}
		else if(isClosing(x[i])) // Closing Bracket ?
		{
			// Closing Bracket Matches with its Corresponding Opening Bracket ?
			if(isMatching(x[i]))
				i++; // Move on
			else
				return 0;
		}
		else // U so meh
			return 0;
	}
	if(top==-1) // If String is Empty, expression is VALID
		return 1;
	else
		return 0;
}

int isOpening(char y)
{
	if(y=='(' || y=='{' || y=='[')
		return 1;
	else
		return 0;
}

int isClosing(char y)
{
	if(y==')'|| y=='}'|| y==']')
		return 1;
	else
		return 0;
}

int isMatching(char y)
{
	char temp=pop();
	if (temp=='(' && y==')')
		return 1;
	else if (temp=='{' && y=='}')
		return 1;
	else if (temp=='[' && y==']')
		return 1;
	else
		return 0;
}

void push(char y)
{
	if(top<MAX)
		top++; st[top]=y;
}

char pop()
{
	if(top>=0)
		top--; return st[top+1];
}
