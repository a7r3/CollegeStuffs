/// Program to implement Circular Queue using Array
#include <stdio.h>
#define MAX 10

// Queue-like Array
int Q[MAX];
// Menu Driven, Operation Selector
int op=0;
// Front Pointer for Queue
int f=-1;
// Rear Pointer for Queue
int r=-1;
// Value, Element
int val,e;
// Counter
int i;

void insert(int e)
{
	// Overflow Condition
	// If rear is just behind front
	// OR
	// front is at Start, and rear is at the End of Queue
	if((f==r+1) || (f==0 && r==MAX-1))
		printf("\nStack Overflow\n");
	// If Queue hasn't been created yet
	else if(f==-1 && r==-1)
	{
		// New Queue
		f=0;
		r=0;
		// Insert element in Queue
		Q[r]=e;
		printf("\nElement inserted at %d\n",r);
	}
	else
	{
		// Rear is set to zero if it reaches MAX
                // Since if 'r+1' = MAX, then mod operation would
                // ... return 0, and new 'r' is at 0
		r=(r+1)%MAX;
		// Insert element at rear position
		Q[r]=e;
		printf("\nElement inserted at %d\n",r);
	}
}

int del()
{
	// Underflow Conditions
	if(f==-1 && r==-1)
	{
		printf("\nUnderflow. 404 No Element Found\n");
		return -1;
	}
	else if(f==r)
	{
		// That was the last of us
		val=Q[f];
		// Reset Queue
		f=-1;
		r=-1;
		// Return it back
		return val;
	}
	else
	{
		// Grab the Element which is about to be deleted
		val=Q[f];
		// Front is set to zero if it reaches MAX
		// Since if 'f+1' = MAX, then mod operation would
		// ... return 0, and new 'f' is at 0
		f=(f+1)%MAX;
		// Return the grabbed element
		return val;
	}
}

void display()
{
	// Queue Empty ?
	printf("\nPrinting Queue\n");
	if(f==-1 && r==-1)
		printf("Queue Empty, nothing to show\n");
	else
	{
		int limit=MAX-1;
		// Is rear ahead of front ?
		// x x f 4 5 6 7 r x x
		if(r>f || f==r)
			limit=r;
		for(i=f;i<=limit;i++)
			printf("| %d ",Q[i]);
		// Is rear behind front ?
		// 1 2 r x x x f 3 4 5
		// In that case, print from 'f' to 'MAX-1' i.e. 5,
		// which is done above
		// Then start from 0 till 'r'
		if(r<f)
			for(i=0;i<=r;i++)
				printf("| %d ",Q[i]);
		printf("|\n");
	}
}

int main()
{
	while(op!=4)
	{
		printf("\n\n========= Circular Queue Emulator ===========");
		printf("\nSpecify the operation you want to perform\n");
		printf("1 - Insert an Element\n");
		printf("2 - Delete an Element\n");
		printf("3 - Show the Queue\n");
		printf("4 - EXIT\n");
		printf("============================================");
		printf("\n\n[>] ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("\nSpecify the element to be inserted\n");
				scanf("%d",&e);
				insert(e);
				break;
			case 2:
				if((val=del())!=-1)
					printf("\nDeleted Element %d from Queue Successfully\n",val);
				else
					printf("\nStack Empty\n");
				break;
			case 3:	display(); break;
			case 4: printf("\n\n[!] EXIT\n\n"); return 0;
			default: printf("\nInvalid Selection\n");
		}
	}
}
