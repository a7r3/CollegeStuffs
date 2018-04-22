/// Program to Evaluate a PostFix expression
#include <stdio.h>
#include <ctype.h>
#define MAX 20
float st[MAX];
int top=-1;

void push(float f);
float pop();
float evalPost(char exp[20]);

void main()
{
	char exp[20];
	printf("\n\nEnter Postfix Expression\n\n");
	scanf("%s",exp);
	printf("\n\nPostfix Evaluation : %f\n\n",evalPost(exp));
}

void push(float f)
{
	top++;
	st[top]=f;
}

float pop()
{
	top--;
	return st[top+1];
}

float evalPost(char exp[20])
{
	int i=0;
	float op1,op2,val;
	while(exp[i] != '\0')
	{
		if(isdigit(exp[i]))
			push((float)(exp[i]-'0'));
		else
		{
			op2=pop();
			op1=pop();
			switch(exp[i])
			{
				case '+': val=op1+op2; break;
				case '-': val=op1-op2; break;
				case '*': val=op1*op2; break;
				case '/': val=op1/op2; break;
//				case '%': val=op1%op2; break;
			}
			push(val);
		}
		i++;
	}
	return pop();
}
