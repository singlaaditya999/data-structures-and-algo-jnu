#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int main () {
   int i, n,d=10;
   int x;
   time_t t;
   
   n = 10;
   
   /* Intializes random number generator */
   srand((unsigned) time(&t));
do{
	n=n+100;
	printf("\n");
   /* Print 5 random numbers from 0 to 49 */
   int head=0,tail=0;
   for( i = 0 ; i < n ; i++ ) {
   		x= rand() % 2;
      //printf("%d\n",x);
      if(x==0) tail++;
      if(x==1) head++;
   }
   
   printf("no. of tails=%d",tail);
   printf("\nno. of heads=%d",head);
   printf("\nTotal no. of trials=%d",n);
   float probability_heads=(float)head/(float)n;
   float probability_tails=(float)tail/(float)n;
   printf("\nprobabilty of heads in this trial=%f\nprobability of tails in this trial=%f",probability_heads,probability_tails);
   printf("\n\n\t\t**********************");
}while(d-->0);
   return(0);
}

