#include<stdio.h>
#include<time.h>
#include<stdlib.h>



int main() 
{
	time_t t;
	int k=100;
	int count[10];
	for(int q=0;q<10;q++)
	{
		count[q]=0;
	}
	srand((unsigned) time(&t));
	int min_num=1, max_num=10,result=0;
	printf("\nRange fromm 1 to 10\n");
 	printf("\nNo. of iterations=%d\n",k);
    do{
    	result = (rand()%10)+min_num;
    printf("Landed on pocket %d\n",result);
    count[result-1]++;
	}while(--k);
	for(int q=0;q<10;q++)
	{
		printf("probability of getting %d is %d",q,count[q]/k);
	}
	return 0;
    }

    
