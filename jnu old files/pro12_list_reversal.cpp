#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node * next;
}*front,*rear;

struct node * getnode(void);
void freenode (struct node*);
int empty();
void insert(int );
int remove();
void display();
int countElements();
void listReversal();

int main()
{
	rear=NULL;
	front=NULL;
	int o,add,end=100;
	while(end!=0)
	{
		
	printf("Menu\n1.Addition\n2.Deletion\n3.Display\n4.Count Nodes\n5.List Reversal\n6.Exit\n");
	scanf("%d",&o);
	switch(o)
	{
		case 1:
			printf("\n\nEnter the value of node to be added:");
			scanf("%d",&add);
			insert(add);
			printf("\nInserted\n");
			break;
		case 2:
			if(empty()==1)
			{
				printf("Queue Underflow");
			}
			else
			{
				printf("\n%dDeleted:",remove());
			}
			break;
		case 3:
			printf("\nElements in the linked list :\n");
			display();
			break;
		case 4:
			printf("Number of Elements in the list=%d",countElements());
			break;
		case 5:
			listReversal();
			break;
		case 6:
			exit(1);
		default:
			printf("Wrong choice Entered");
	};
	printf("\n\n\t\t*********************\n\n");
	};
	return 0;
}

int empty()
{
	return ((front==NULL)?1:-1);
}

void insert(int x)
{
	struct node * p;
	p=(struct node *) malloc(sizeof(struct node));
	p->info=x;
	p->next=NULL;
	
	if(rear==NULL)
		front=p;
	else 
		rear->next=p;
	rear=p;
	return;
}

int remove()
{
	struct node* p;
	int x;
	
	p=front;
	x=p->info;
	front=p->next;
	if(front==NULL)
		rear=NULL;
	free(p);
	return x;
}

void display()
{
	struct node *p;
	p=front;
	while(p!=NULL)
	{
		printf("%d -> ",p->info);
		p=p->next;
	}
	printf("!!!\n");
	return;
}

int countElements()
{
	int count=0;
	struct node *p;
	p=front;
	while(p!=NULL)
	{
		++count;
		p=p->next;
	}
	return count;
}

void listReversal()
{
	rear=front;
	struct node* prev=NULL;
	struct node *current =front;
	struct node *nextElement=NULL;
	while(current!=NULL)
	{
		nextElement=current->next;
		current->next=prev;
		prev=current;
		current=nextElement;
	}
	front=prev;
	printf("\nList reversed\n");
	return;
}


