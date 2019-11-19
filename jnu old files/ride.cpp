/*
ID: aditya.59
LANG: C++
TASK: ride
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ofstream fout("ride.out");
	ifstream fin("ride.in");
	string comet;
	string group;
	fin>>comet>>group;
	int a,pCom=1,pGrp=1;
	for(int i=0;comet[i]!='\0';i++)
	{
		a=comet[i];
		a=a-64;
		pCom=a*pCom;
	}
	for(int i=0;group[i]!='\0';i++)
	{
		a=group[i];
		a=a-64;
		pGrp=a*pGrp;
	}
	if(pCom%47==pGrp%47)
	{
		fout<<"GO"<<"\n";
	}
	else
	{
		fout<<"STAY"<<"\n";
	}
	fin.close();
	fout.close();
	return 0;
}
