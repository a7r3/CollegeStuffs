/// Program to convert an Infix expression to a Postfix expression
#include <stdio.h>
#include <string.h>
#define MAX 20
char st[MAX];
int top=-1;

void push(char a);
char pop();
int getWeight(char a);
void in2post(char source[20], char target[20]);
int isOperator(char a);

void main()
{
	char infix[20], postfix[20];
	printf("\n\nEnter an Infix expression\n\n");
	scanf("%s",infix);
	strcpy(postfix,"");
	in2post(infix,postfix);
	printf("\n\nPostfix expression is : %s\n\n",postfix);
}

void push(char a)
{
	top++;
	st[top]=a;
}

char pop()
{
	top--;
	return st[top+1];
}

int isOperator(char a)
{
	if ( a == '+' ||  a == '-' || a == '/' || a == '*' || a == '%' )
		return 1;
	return 0;
}

int getWeight(char a)
{
	switch(a)
	{
		case '+': case '-': return 0; break;
		case '/': case '*': case '%': return 1; break;
	}
}

void in2post(char source[20], char target[20])
{
	char temp;
	int i=0; // Source Expression Index
	int j=0; // Target Expression Index
	while(source[i] != '\0') // while we haven't reached End of the String
	{
		// If element is a digit or an alphabet
		// Push it to Postfix expression directly
		if(isdigit(source[i]) || isalpha(source[i]))
		{
			target[j]=source[i];
			j++; // One operand added, increment the index
			i++; // Proceed to next character in Infix
		}
		// If element is opening Parantheses
		// Push it directly to stack
		else if (source[i] == '(')
		{
			push(source[i]);
			// Move on
			i++;
		}
		// If element is closing Parantheses
		// Repeatedly pop() until an '(' is encountered
		else if (source[i] == ')')
		{
			temp=pop();
			while(temp != '(')
			{
				target[j]=temp;
				j++;
				temp=pop();
			}
			// Move on
			i++;
		}
		// If element is an operator
		else if (isOperator(source[i]))
		{
			// while element has lower precedence than the topmost element in the stack
			while(getWeight(source[i]) < getWeight(st[top]) && st[top] != '(')
			{
				// pop it out!
				temp=pop();
				target[j]=temp;
				j++;
			}
			// push the element onto the stack
			push(source[i]);
			// Move on
			i++;
		}
	}
	// while stack isn't empty,
	// pop() all the elements into the postfix expression
	while(top!=-1)
	{
		temp=pop();
		target[j]=temp;
		j++;
	}
}
