

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include<time.h>


int main()
{
	time_t t;
   int niter=50;
   srand((unsigned) time(&t));
   double x,y;
   int i,count=0; 
   double z;
   double pi;
   int j=10;
do
{

   printf("The number of iterations used to estimate pi: ");
   niter=niter+50;

   count=0;
   for ( i=0; i<niter; i++) {
      x = (double)rand()/RAND_MAX;
      y = (double)rand()/RAND_MAX;
      z = x*x+y*y;
      if (z<=1) count++;
      }
   pi=(double)count/niter*4;
   printf("# of trials= %d , estimate of pi is %g \n\n*****************************\n\n",niter,pi);
}while(j--);
}

