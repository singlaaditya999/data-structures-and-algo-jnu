/*
ID: aditya.59
LANG: C++
TASK: friday
*/
#include<fstream>
#include<stdlib.h>
#include<iostream>

using namespace std;

bool isleap (int year)
{
	if(year%100==0)
		return year %400==0;
	else
		return year%4==0;
}
int main()
{
	ofstream fout("friday.out");
	ifstream fin("friday.in");
	
	int period;
	fin>>period;
	
	int calenderDay=0;
	int freq[7]={0,0,0,0,0,0,0};
	int normDays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int leapDays[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	
	for(int year=1900;year<1900+period;year++)
	{
		for(int month=0;month<12;month++)
		{
			int weekday=(calenderDay+12)%7;
			freq[(weekday+2)%7]++;
			calenderDay+=isleap(year)?leapDays[month]:normDays[month];
		}
	}
	for (int i=0;i<7;i++)
	{
		fout<<freq[i];
		if(i==6)fout<<"\n";
		else fout<<" ";
	}
	return 0;
}
