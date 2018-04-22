/// Program to emulate a linked list using structures, values from user, MENU DRIVEN - Operations use Start Node as Reference
// downloadmoaroptimizations.com

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int element;
	struct node *next;
} *head, *preinter, *inter;

void insertStart()
{
	inter=(struct node *)malloc(sizeof(struct node));
	inter->next=head;
	head=inter;
	printf("\nElement > ");
	scanf("%d",&head->element);
}

void insertEnd()
{
	inter=head;
	while(inter->next != NULL)
		inter=inter->next;
	inter->next=(struct node *)malloc(sizeof(struct node));
	inter=inter->next;
    printf("\nElement > ");
    scanf("%d",&inter->element);
}

void deleteEnd()
{
	inter=head;
	while(inter->next != NULL)
	{
		preinter=inter;
		inter=inter->next;
	}
	preinter->next=inter->next;
	free(inter);
}

void deleteStart()
{
	inter=head->next;
	free(head);
	head=inter;
}

void insertPos(int p)
{
	struct node *newNode=(struct node *)malloc(sizeof(struct node));
	inter=head;
	while(p!=1)
	{
		preinter=inter;
		inter=inter->next;
		p--;
	}
	preinter->next=newNode;
	newNode->next=inter;
	printf("\nElement > ");
	scanf("%d",&newNode->element);
}

void deletePos(int p)
{
	inter=head;
	while(p!=1)
	{
		preinter=inter;
		inter=inter->next;
		p--;
	}
	preinter->next=inter->next;
	free(inter);
}

void traverseList()
{
	inter=head;
	while(inter->next!=NULL)
	{
		printf("[ %d | %p ]",inter->element,inter->next);
		if(inter->next!=NULL)
			printf(" --> ");
		inter=inter->next;
	}
	printf("[ %d | %p ]\n",inter->element,inter->next);
}

int main()
{
	int pos;
	int op=0;
	while(op!=7)
	{
		printf("\n\n======== Linked List Emulator ========\n");
		printf("1. Insert node at End\n");
		printf("2. Delete node at End\n");
		printf("3. Insert node before Start\n");
		printf("4. Delete node at Start\n");
		printf("5. Insert node at a Position\n");
		printf("6. Delete node at a Position\n");
		printf("7. Traverse Linked List\n");
		printf("8. Exit\n");
		printf("======================================\n");
		printf("[>] ");
		scanf("%d",&op);
		switch(op)
		{
			case 1: insertEnd(); break;
			case 2: deleteEnd(); break;
			case 3: insertStart(); break;
			case 4: deleteStart(); break;
			case 5: printf("\nPosition > "); scanf("%d",&pos); insertPos(pos); break;
			case 6: printf("\nPosition > "); scanf("%d",&pos); deletePos(pos); break;
			case 7: traverseList(); break;
			case 8: return 0;
			default: printf("\nInvalid Selection");
		}
	}
	return 0;
}
