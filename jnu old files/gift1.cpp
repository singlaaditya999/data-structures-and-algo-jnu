/*
ID: aditya.59
LANG: C++
TASK: gift1
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ofstream fout("gift1.out");
	ifstream fin("gift1.in");
	int NP;
	fin>>NP;
	string names[10];
	int amt[10];
	for (int i=0;i<NP;i++)
	{
		fin>>names[i];
		amt[i]=0;
	}
	for(int i=0;i<NP;i++)
	{
		string giver;
		int amount,ppl;
		fin>>giver>>amount>>ppl;
		if(ppl>0)
		{
			for(int j=0;j<NP;j++)
			{
				if(names[j]==giver)
				amt[j]=amt[j]-amount+amount%ppl;
				break;
			}
			string receiver;
			for(int j=0;j<ppl;j++)
			{
				fin>>ppl;
				for(int k=0;k<NP;k++)
				{
					if(names[k]==receiver)
					amt[k]=amt[k]+amount%ppl;
				}
			}
		}
	}
	for(int i=0;i<NP;i++)
	{
		fout<<names[i]<<" "<<amt[i]<<"\n";
	}
	fin.close();
	fout.close();
	return 0;
}
