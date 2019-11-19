// C code to implement Priority Queue 
// using Linked List 
#include <stdio.h> 
#include <stdlib.h> 

// Node 
typedef struct node { 
	int data; 

	// Lower values indicate higher priority 
	int priority; 

	struct node* next; 

} Node; 

// Function to Create A New Node 
Node* newNode(int d, int p) 
{ 
	Node* temp = (Node*)malloc(sizeof(Node)); 
	temp->data = d; 
	temp->priority = p; 
	temp->next = NULL; 

	return temp; 
} 

// Return the value at head 
int peek(Node** head) 
{ 
	return (*head)->data; 
} 

// Removes the element with the 
// highest priority form the list 
void pop(Node** head) 
{ 
	Node* temp = *head; 
	(*head) = (*head)->next; 
	free(temp); 
} 

// Function to push according to priority 
void push(Node** head, int d, int p) 
{ 
	Node* start = (*head); 

	// Create new Node 
	Node* temp = newNode(d, p); 

	// Special Case: The head of list has lesser 
	// priority than new node. So insert new 
	// node before head node and change head node. 
	if ((*head)->priority > p) { 

		// Insert New Node before head 
		temp->next = *head; 
		(*head) = temp; 
	} 
	else { 

		// Traverse the list and find a 
		// position to insert new node 
		while (start->next != NULL && 
			start->next->priority < p) { 
			start = start->next; 
		} 

		// Either at the ends of the list 
		// or at required position 
		temp->next = start->next; 
		start->next = temp; 
	} 
} 

// Function to check is list is empty 
int isEmpty(Node** head) 
{ 
	return (*head) == NULL; 
} 

// Driver code 
int main() 
{ 
	int add;
	Node *pq;
	do
	{
		printf("Menu\n1.Priority Enqueue\n2.Priority Dequeue\n3.Display\n4.Exit\n");
		int o,flag=0;
		scanf("%d",&o);
		switch(o)
		{	
		case 1:
			printf("\n\nEnter the value of node to be added:");
			scanf("%d",&add);
			if (flag==0)
			{
				Node *pq = newNode(add, add);
				flag=1;
			}
			else
			{
				push(&pq, add, add); 
			}
			printf("\nInserted\n");
			break;
		case 2:
			pop(&pq);
			break;
		case 3:
			printf("\nElements in the linked list :\n");
			Node* temp;
			temp=pq;
			while (temp!=NULL) 
			{  
				peek(&temp);
				(temp) = temp->next; 
			}
			free (temp);	 
			break;
		case 4:
			exit(1);
		default:
			printf("Wrong choice Entered");
		};
		printf("\n\n\t\t*********************\n\n");
	}while(!0);*
	return 0; 
} 

