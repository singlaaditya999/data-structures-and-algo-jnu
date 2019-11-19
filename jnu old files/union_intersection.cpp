#include<stdio.h>
#include<string.h>
void find_union(int [],int []);
void find_intersection(int [],int []);
int main()
{
	int a[10],b[10];
	printf("Input first array\n");
	for(int i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nSecond array\n");
	for(int i=0;i<10;i++)
	{
		scanf("%d",&b[i]);
	}
	find_union(a,b);
	find_intersection(a,b);
}
void find_union(int s1[],int s2[])
{
	int str[20],p=0,f=0;
	int len1=10;
	int len2=10;
	for(p=0;p<len1;p++)
	{
		str[p]=s1[p];
	}
	for(int i=0;i<len2;i++)
	{
		f=0;
		for(int j=0;j<len1;j++)
		{
			if(s1[j]==s2[i]) f=-1;
		}
		if (f==0) str[p++]=s2[i];
	}	
	printf("\nUnion\n");
	while(str[p]!='\0')
	printf("%d\n",str[p]);
	return;
}
void find_intersection(int s1[],int s2[])
{
	int str[20],p=0,f=0;
	int len1=10;
	int len2=10;
	
	for(int i=0;i<len2;i++)
	{
		f=0;
		for(int j=0;j<len1;j++)
		{
			if(s1[j]==s2[i]) f=-1;
		}
		if (f==-1) str[p++]=s2[i];
	}	
	printf("\nIntersection\n");
	while(str[p]!='\0')
	printf("%d\n",str[p]);
	return;
}
