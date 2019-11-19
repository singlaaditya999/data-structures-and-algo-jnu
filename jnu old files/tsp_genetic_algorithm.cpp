#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void crossover(int *a,int *b,int n)
{
	int i,p,j;
	int k[6];
	for(i=0;i<6;i++)
	k[i]=a[i];
	for(i=n/2;i<n;i++)
		{	p=0;
			for(j=0;j<i;j++)
			{
				if(b[i]==a[j])
				{
					p=1;
					break;
				}
			}
			if(p==0)
			{
				a[i]=b[i];
			}
			else
			continue;
		}

	for(i=0;i<n/2;i++)
		{	p=0;
			for(j=n/2;j<n;j++)
			{
				if(k[i]==b[j])
				{
					p=1;
					break;
				}
			}
			if(p==0)
			{
				b[i]=k[i];
			}
		}
}
int main()
{
	int population[6][6],i,j,fitness[6],sum=0,q;
	float probabilities[6];
	srand(time(0)); 
	for(i=0;i<6;i++)		//GENERATION OF POPULATION
	{	fitness[i]=0;
		for(j=0;j<6;j++)
		{
			population[i][j]=rand()%100+1;
			fitness[i]+=population[i][j]; //CALCULATING FITNESS OF EACH TRAVERSAL
		}
		sum+=fitness[i];
	}
		for(i=0;i<6;i++)
		{
			for(j=0;j<6;j++)
			printf("%d\t",population[i][j]);
				printf("\n");
		}
//CALCULATION TO FIND PROBABILITY OF EACH CHROMOSOME
	probabilities[0]=0;
	probabilities[5]=1;
	for(i=1;i<5;i++)
	{
		probabilities[i]=probabilities[i-1]+(float)fitness[i]/sum;
	}
	
	//TO PICK RANDOM PARENT, RANDOM NUMBER IS GENERATED BETWEEN 0 AND 1
	//////////////////////////////////////////////CROSSOVER////////////////////////////////////////////
	 for(i=0;i<3;i++)
	 {
	 	float p1=rand() / ((double) RAND_MAX);
	 	float p2=rand() / ((double) RAND_MAX);
	 	for(j=0;p1>probabilities[j];j++);
	 	for(q=0;p2>probabilities[q];q++);
	 	
	 	crossover(population[j],population[q],6);
	 }
	 
	
	printf("\n/////////AFTER CROSSOVER///////////\n");
		for(i=0;i<6;i++)
		{
			for(j=0;j<6;j++)
			printf("%d\t",population[i][j]);
			printf("\n");
		}
	///////////////////////////////////MUTATION///////////////////////////////////////////////////
		for(i=0;i<6;i++)
		{	int max=5,min=0;
			int r=rand() % ( max - min )  + min;
			int s=rand() % ( max - min )  + min;
			int temp=population[i][r];
			population[i][r]=population[i][s];
			population[i][s]=temp;
		}
			printf("\n/////////AFTER MUTATION///////////\n");
		for(i=0;i<6;i++)
		{
			for(j=0;j<6;j++)
			printf("%d\t",population[i][j]);
			printf("\n");
		}
	}


