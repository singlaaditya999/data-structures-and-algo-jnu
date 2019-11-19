#include<stdio.h>
struct node
{
	int info;
	struct node* next;
};
typedef struct node* NODEPTR;
struct queue
{
	NODEPTR front,rear;
	
};
struct queue q1,q2;

void print_common(queue q1,queue q2)
{
	NODEPTR p1,p2;
	int info1,info2;
	p1=q1.front;
	while(p1!=NULL)
	{
		info1=p1->info;
		p2=q2.front;
		while(p2!=NULL)
		{
			p2=p2->next;
			info2=p2->info;
			if(info1==info2)
				printf("%d,",info1);
		}
		p1=p1->next;
	}
	return;
}

void concat(NODEPTR f1,NODEPTR r2)
{
	if(r2==NULL)
		return;
	if(f1==NULL)
		return;
	f1->next=r2;
	NODEPTR p;
	p=f1;
	while(p!=NULL)
	{
		printf("%d -> ",p->info);
		p=p->next;
	}
	printf("!!!\n");
	return;
}
void insert(int x,queue q)
{
	NODEPTR p;
	p=new node;
	p->info=x;
	p->next=NULL;
	if(q.rear==NULL)
		q.front=p;
	else 
		q.rear->next=p;
	q.rear=p;
	q.rear->next=NULL;
	return;
}

void display(queue q)
{
	NODEPTR p;
	p=q.front;
	while(p!=NULL)
	{
		printf("%d -> ",p->info);
		p=p->next;
	}
	printf("!!!\n");
	return;
}


void input(queue q)
{
	for(;;)
	{
	printf("\nMenu\n1.Insert\n2.Display\n3.Exit\n");
	int o,add;
	scanf("%d",&o);
	switch (o)
	{
		case 1:
			printf("\n\nEnter the value of node to be added:");
			scanf("%d",&add);
			insert(add,q);
			printf("\nInserted\n");
			break;
		case 2:
			printf("\nElements in the linked list :\n");
			display(q);
			break;
		case 3:
			return;
		default:
			printf("\nWrong choice entered");
	}
	}
}
int main()
{
	q1.front=NULL;
	q1.rear=NULL;
	q2.front=NULL;
	q2.rear=NULL;
	printf("Enter the first list\n");
	input(q1);
	printf("\n*******************************\nEnter the second list\n");
	input(q2);
	printf("\nList after concatenation");
	concat(q1.front,q2.rear);
	printf("\nCommon elements in the two lists\n");
	print_common(q1,q2);
	return 0;
}
