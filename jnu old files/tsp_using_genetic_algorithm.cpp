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
	int population[50][6],total_distance[50],sum=0;
	float probabilities[50],fitness[50];
	srand(time(0));
	
	
	int distance_matrix[6][6]={ 0 , 95 , 74 , 80 , 40 , 6 ,				//DISTANCE MATRIX
					  			20 ,  0 , 67 , 53 , 60 , 43,
					  			31 ,  1 ,  0 , 87 , 83 , 19,
					  			24 , 19 , 42 ,  0 ,  2 , 10,
					  			50 , 79 , 28 , 74 ,  0 , 31,
					  			60 , 22 , 72 , 24 , 75 ,  0,
							  } ;
	
	printf("Distance matrix:\n");				
	for(int i=0;i<6;i++)											//PRINTING DISTANCE MATRIX
		{
			for(int j=0;j<6;j++)
			printf("%d\t",distance_matrix[i][j]);
				printf("\n");
		}
	
	int temp,randomIndex;						//GENERATION OF POPULATION
    for (int i=1;i<50;i++)
    {
    	for(int j=0;j<6;j++)
    	{
    		population[i][j]=population[0][j];
		}
    	for(int j=0;j<6;j++)
    	{
    		temp=population[i][j];
    		randomIndex=rand()%6;
    		
    		population[i][j]=population[i][randomIndex];
    		population[i][randomIndex]=temp;
		}
	}
	
	
	printf("\n\n***********************************\n\nIn each generation every chromosome crossovers and some have mutations\nAfter 20 generations\n\n");
	for(int k=0;k<20;k++)
	{
		
		
		for (int i=0;i<50;i++)
	{
		total_distance[i]=0;
		for(int j=0;j<5;j++)
		{
			total_distance[i]=total_distance[i]+distance_matrix[population[i][j]-1][population[i][j+1]-1];
		}
		fitness[i]=(float)(1/total_distance[i]);
		sum=sum+total_distance[i];
	}
	
	//CALCULATION TO FIND PROBABILITY OF EACH CHROMOSOME
	probabilities[0]=0;
	probabilities[49]=1;
	for(int i=1;i<50;i++)
	{
		//probabilities[i]=probabilities[i-1]+(float)fitness[i]/sum;
		probabilities[i]=probabilities[i-1]+(float)total_distance[i]/sum;
	}
	for(int q=0;q<50;q++)
	{
			//TO PICK RANDOM PARENT, RANDOM NUMBER IS GENERATED BETWEEN 0 AND 1
	//////////////////////////////////////////////CROSSOVER////////////////////////////////////////////
	 for(int i=0;i<3;i++)
	 {
	 	float p1=rand() / ((double) RAND_MAX);
	 	float p2=rand() / ((double) RAND_MAX);
	 	int j;
		for( j=0;p1>probabilities[j];j++);
	 	for(q=0;p2>probabilities[q];q++);
	 	crossover(population[j],population[q],6);
	 }
	}
	
	 
	
	///////////////////////////////////MUTATION///////////////////////////////////////////////////
		for(int q=0;q<5;q++)
		{
			for(int i=0;i<50;i++)
		{	int max=5,min=0;
			int r=rand() % ( max - min )  + min;
			int s=rand() % ( max - min )  + min;
			int temp=population[i][r];
			population[i][r]=population[i][s];
			population[i][s]=temp;
		}
		}
		
	}
	
	printf("The fittest chromosome is:");
	int min=fitness[0],pos;
	for(int i=1;i<50;i++)
	{
		if (min>fitness[i])
		{
			min=fitness[i];
			pos=i;
		}
		
	}
	printf("%d\nThe route taken is :",min);
	for(int j=0;j<6;j++)
	{
		printf("%d\t",population[pos][j]);
	}
	return 0;
}


