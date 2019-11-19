#include<stdio.h>
#include<math.h>
int main()
{
	float i,min=1,max=3,dx,n=200,integral;
	dx=(max-min)/(n-1);
	for(i=min;i<max;i=i+dx)
	{
		integral=(((float) pow(i,2) )*((float) exp(-i) )*((float)sin(i) ) )*((float)dx)+integral;
	}
	printf("%f",integral);
}
