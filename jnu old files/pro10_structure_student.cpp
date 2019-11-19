#include<stdio.h>
#include<string.h>
struct student
{
	char name[20];
	int marks[3];
	int totalMarks;
} stud[100];
void input(int);
void display(int);
void sortDescendingMarks(int);
void sortAlphabetically(int);
int main()
{
	int no;
	printf("Enter the no. of records to be input:");
	scanf("%d",&no);
	input(no);
	display(no);
	sortDescendingMarks(no);
	printf("\n\nRecords after sorting according to total marks:");
	display(no);
	printf("\n\nRecords after sorting alphabetically:");
	display(no);
	return 0;
}
void input(int s)
{
	for (int i=0;i<s;i++)
	{
		printf("\nEnter data of student %d\n\n",i+1);
		printf("\nEnter name of student:");
		scanf("%s",stud[i].name);
		printf("Enter marks of subject1:");
		scanf("%d",stud[i].marks[0]);
		printf("\nEnter marks of subject2:");
		scanf("%d",stud[i].marks[1]);
		printf("\nEnter marks of subject3:");
		scanf("%d",stud[i].marks[2]);
		stud[i].totalMarks=0;
		for (int j=0;j<3;j++)
		{	
			stud[i].totalMarks=stud[i].totalMarks+stud[i].marks[j];
		}	
		printf("\n\n**********************************\n\n");
	}
	
	return;
}
void display(int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\nName of student%d=%s",i+1,stud[i].name);
		for (int j=0;i<3;i++)
		{	
			printf("marks in subject%d:%d",j+1,stud[i].marks[j]);
			printf("\n");
		}
		printf("Total marks=%d",stud[i].totalMarks);
		printf("\n\n**********************************\n\n");
	}
	return;
}
void sortDescendingMarks(int n)
{
	student temp;
	for (int i=0;i<n-1;i++)
	{
		for (int j=0;j<n-1-i;j++)
		{
			if(stud[j].totalMarks<stud[j+1].totalMarks)
			{
				temp=stud[j];
				stud[j]=stud[j+1];
				stud[j+1]=temp;
			}
		}
	}
	return;
}
void sortAlphabetically(student s[],int n)
{
	student temp;
	int n1,n2;
	for (int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			n1=stud[j].name[0];
			n2=stud[j+1].name[0];
			if(n1<n2)
			{
				temp=stud[j];
				stud[j]=stud[j+1];
				stud[j+1]=temp;
			}
		}
	}
	return;
}
