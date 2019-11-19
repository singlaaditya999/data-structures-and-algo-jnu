/*
ID: aditya.59
LANG: C++
TASK: friday
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct time                                //0=monday
{                                          //1=tuesday
	int day;                               //2=wednesday
	int date;                              //3=thursday
	string month;                          //4=friday
	int yr;                                //5=saturday
};                                         //6=sunday
int main()
{
	int mon13=0,tue13=0,wed13=0,thur13=0,fri13=0,sat13=0,sun13=0;
	ifstream fin("friday.in.txt");
	ofstream fout("friday.out");
	int N;
	fin>>N;
	int t=N*365.25;
	int y=1900;
	time d[t];
	for(int i=0,j=1;i<t;i++,j++)
	{
		d[t].day=j%7;
		int x=t;
		int inyr=1900;
		while(x)
		{
			x-=31;if(x<=0){d[t].date=x+31;d[t].month=1;break;}
			if(inyr%4!=0){x-=28;if(x<=0){d[t].date=x+28;d[t].month=2;break;}}
			else{x-=29;if(x<=0){d[t].date=x+29;d[t].month=2;break;}}
			x-=31;if(x<=0){d[t].date=x+31;d[t].month=3;break;}
			x-=30;if(x<=0){d[t].date=x+30;d[t].month=4;break;}
			x-=31;if(x<=0){d[t].date=x+31;d[t].month=5;break;}
			x-=30;if(x<=0){d[t].date=x+30;d[t].month=6;break;}
			x-=31;if(x<=0){d[t].date=x+31;d[t].month=7;break;}
			x-=31;if(x<=0){d[t].date=x+31;d[t].month=8;break;}
			x-=30;if(x<=0){d[t].date=x+30;d[t].month=9;break;}
			x-=31;if(x<=0){d[t].date=x+31;d[t].month=10;break;}
			x-=30;if(x<=0){d[t].date=x+30;d[t].month=11;break;}
			x-=31;if(x<=0){d[t].date=x+31;d[t].month=12;break;}
			inyr++;
		}
	}
	
	for(int i=0;i<t;i++)
	{
		if(d[i].date==13)
		{
			switch(d[t].day)
			{
				case 0:mon13++;break;
				case 1:tue13++;break;
				case 2:wed13++;break;
				case 3:thur13++;break;
				case 4:fri13++;break;
				case 5:sat13++;break;
				case 6:sun13++;break;
			}
		}
	}
	cout<<sat13<<" "<<sun13<<" "<<mon13<<" "<<tue13<<" "<<wed13<<" "<<thur13<<" "<<fri13;
	fout<<sat13<<" "<<sun13<<" "<<mon13<<" "<<tue13<<" "<<wed13<<" "<<thur13<<" "<<fri13;
	fin.close();
	fout.close();
	return 0;
}
