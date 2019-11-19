#include<stdio.h>

struct node
{
	int info;
	struct node *next;
};
typedef struct node* NODEPTR;
struct queue
{
	NODEPTR front,rear;
	int count=0;
};


void insert(int x,queue *q)
{
	NODEPTR p;
	p=new node;
	p->info=x;
	p->next=NULL;
	if(q->rear==NULL)
		q->front=p;
	else 
		q->rear->next=p;
	q->rear=p;
	q->rear->next=NULL;
	return;
}

void display(queue *q)
{
	NODEPTR p;
	int t=0;
	p=q->front;
	while(p!=NULL)
	{
		printf("%d *x^%d +",p->info,t++);
		p=p->next;
	}
	printf("!!!");
	return;
}

void print_add(queue * q1,queue * q2)
{
	NODEPTR p,q;
	p=q1->front;
	q=q2->front;
	int t=0;
	int min=(q1->count<q2->count)?q1->count:q2->count;
	int max=(q1->count>q2->count)?q1->count:q2->count;
	for(int i=0;i<min;i++)
	{
		printf("%d*x^%d+",p->info+q->info,t++);
		p=p->next;
		q=q->next;
	}
	if(q1->count>q2->count)
	{
		for(int i=min-1;i<max;i++)
		{	
			printf("%d*x^%d+",p->info,t++);
			p=p->next;
		}
	}
	else
	{
		for(int i=min-1;i<max;i++)
		{	
			printf("%d*x^%d+",q->info,t++);
			q=q->next;
		}
	}
	return;
}
void print_subtract(queue * q1,queue * q2)
{
	NODEPTR p,q;
	p=q1->front;
	q=q2->front;
	int t=0;
	int min=(q1->count<q2->count)?q1->count:q2->count;
	int max=(q1->count>q2->count)?q1->count:q2->count;
	for(int i=0;i<min;i++)
	{
		printf("%d*x^%d+",p->info-q->info,t++);
		p=p->next;
		q=q->next;
	}
	if(q1->count>q2->count)
	{
		for(int i=min-1;i<max;i++)
		{	
			printf("%d*x^%d+",p->info,t++);
			p=p->next;
		}
	}
	else
	{
		for(int i=min-1;i<max;i++)
		{	
			printf("%d*x^%d+",-(q->info),t++);
			q=q->next;
		}
	}
	return;
}
void input(queue *q)
{
	for(;;)
	{
	printf("\nMenu\n1.Insert coefficient of x^%d\n2.Display\n3.Exit\n",q->count);
	int o,add;
	scanf("%d",&o);
	switch (o)
	{
		case 1:
			printf("\n\nEnter the value of node to be added:");
			scanf("%d",&add);
			insert(add,q);
			printf("\nInserted\n");
			q->count++;
			break;
		case 2:
			printf("\Polynomial :\n");
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
	struct queue q1,q2;
	q1.front=NULL;
	q1.rear=NULL;
	q2.front=NULL;
	q2.rear=NULL;
	printf("Enter the first polynomial P1:\n");
	input(&q1);
	printf("\n*******************************\nEnter the second plynomial P2\n");
	input(&q2);
	printf("\nAfter addition of polynomials P1+P2=");
	print_add(&q1,&q2);
	printf("\nAfter subtraction of polynomials P1-P2=\n");
	print_subtract(&q1,&q2);
	return 0;
}
