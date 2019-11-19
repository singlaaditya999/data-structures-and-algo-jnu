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
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");
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
		string name;
		fin>>name;
		int amount,ppl;
		fin>>amount>>ppl;
		if(ppl>0)
		{
			int each=amount/ppl;
			int remain=amount%ppl;
			for(int j=0;j<NP;j++)
			{
				if(names[j]==name)
				{
					amt[j]-=amount;
					amt[j]+=remain;
					break;
				}
			}
			for(int j=0;j<ppl;j++)
			{
				string recipient;
				fin>>recipient;
				for(int k=0;k<NP;k++)
				{
					if(names[k]==recipient)
					{
						amt[k]+=each;
					}
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
