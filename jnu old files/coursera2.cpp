#include<stdio.h>
#include<math.h>
int main()
{
	float s4=1,dt=0.05;
	for(float i=0;i<4;i=i+dt)
	{
		s4=s4*(1-10*dt);
	}
	printf("%f",s4);
	
	
}
