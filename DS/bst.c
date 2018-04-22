/// Menu-Driven program to demonstrate Binary Search Tree

#include<stdio.h>
#include<stdlib.h>

struct node
{
	// | LEFT | DATA | RIGHT |
	struct node *left;
	int element;
	struct node *right;
} *root, *inter;


void insertNode()
{
	int e;
	inter = (struct node *)malloc(sizeof(struct node));
	if(root == NULL)
		root = inter;
	// TODO : Verify the Condition
	while(inter->left != NULL && inter->right != NULL)
	{
		if(e <= inter->element)
			inter = inter->left;
		else if(e > inter->element)
			inter = inter->right;
	}
        printf("\nElement > ");
        scanf("%d",&inter->element);
}

// LEFT ROOT RIGHT //
void traverseIn(struct node *t)
{
	if(t!=NULL)
	{
		printf("%d ",t->left->element); // Left Subtree
		traverseIn(t->left);
		printf("%d ",t->element); // Root
		traverseIn(t->right);
		printf("%d ",t->right->element); //Right Subtree
	}
}

// ROOT LEFT RIGHT //
void traversePre(struct node *t)
{
 	if(t!=NULL)
        {
		printf("%d ",t->element); // Root
                printf("%d ",t->left->element); // Left Subtree
                traversePre(t->left);
		traversePre(t->right);
                printf("%d ",t->right->element); //Right Subtree
        }
}

// LEFT RIGHT ROOT //
void traversePost(struct node *t)
{
	if(t!=NULL)
        {
                printf("%d ",t->left->element); // Left Subtree
                traversePost(t->left);
                traversePost(t->right);
                printf("%d ",t->right->element); //Right Subtree
        	printf("%d ",t->element); // Root
	}

}

void traverse()
{
	int op=0;
	while(op!=4)
	{
		printf("\n\n==== Traversal Menu ====");
		printf("\n1. InOrder Traversal");
		printf("\n2. PreOrder Traversal");
		printf("\n3. PostOrder Traversal");
		printf("\n4. Return to Main Menu");
		printf("\n========================");
		printf("\n> ");
		scanf("%d",&op);
		switch(op)
		{
			case 1: traverseIn(root); break;
			case 2: traversePre(root); break;
			case 3: traversePost(root); break;
			case 4: break;
			default: printf("\nInvalid Selection\n");
		}
	}
}

void searchNode()
{
	printf("\nSearch Element > ");
	int e;
	scanf("%d",&e);
	inter = root;
	while(e != inter->element)
        {
                if(e <= inter->element)
                        inter = inter->left;
                else if(e > inter->element)
                        inter = inter->right;
        }
	if(e == inter->element)
		printf("\nElement %d found at %p\n",inter->element,inter);

}

void main()
{
	int op=0;
	while(op!=4)
	{
		printf("\n\n==== Binary Search Tree ====");
		printf("\n1. Insert Node");
		printf("\n2. Traverse BST");
		printf("\n3. Search Node");
		printf("\n4. EXIT");
		printf("\n========================");
                printf("\n> ");
		scanf("%d",&op);
		switch(op)
		{
			case 1: insertNode(); break;
			case 2: traverse(); break;
			case 3: searchNode(); break;
			case 4: break;
			default: printf("\nInvalid Selection\n");
		}
	}
}
