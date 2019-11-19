#include<stdio.h>
#include<limits.h>
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
    int c[20];
    for (int i=0;i<10;i++)
    {
    	c[i]=a[i];
	}
	int flag=0;int j=0;int i=10;
	for(;i<20;i++)
	{
		flag=0;
		for(;j<10;j++)
		{
			if(a[i-10]==b[j])
			flag=-1;
		}
		if(flag==0) c[i]=b[j];
		if(j==9) break;
	}

	printf("\nUnion\n");
	for(int k=0;k<i;k++)
	{
		printf("%d",a[i]);
	}
	printf("\nIntersection\n");
	
}
