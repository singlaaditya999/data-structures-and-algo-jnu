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
void delete_negative();

int main()
{
	rear=NULL;
	front=NULL;
	int o,add,end=100;
	while(end!=0)
	{
		
	printf("Menu\n1.Push\n2.Pop\n3.Display\n4.Count Nodes\n5.Exit\n");
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
			printf("\nElements in the stack :\n");
			display();
			break;
		case 4:
			printf("Number of Elements in the stack=%d",countElements());
			break;
		case 5:
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
	{
		front=p;
		rear=p;
	}
	else
	{
		p->next=front;
		front=p;
	} 
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
		printf("%d\n",p->info);
		p=p->next;
	}
	printf("!!!bottom\n");
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

void delete_negative()
{
	struct node *p;
	p=front;
	while(p!=NULL)
	{
		if(p->next->info<0)
		{
			struct node* q;
			q=p->next;
			p->next=q->next;
			delete q;
		}
		p=p->next;
	}
	return;
}
