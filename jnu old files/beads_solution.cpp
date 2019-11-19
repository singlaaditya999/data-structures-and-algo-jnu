//this program uses dynamic programming
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
int N;
string chars;
int max(int a,int b);
{
	return (a>b?a:b);
}
int main()
{
	std::ios::sync_with_stdio(false);
	ofstream fout("beads.out");
	ifstream fin("beads.in");
	fin>>N;
	fin>>chars;
	chars=chars+chars;
	int size=chars.size();
	int left[size+1][2];
	int right[size+1][2];
	left[0][0]=0;
	left[0][1]=0;
	right[size][0]=0;
	right[size][1]=0;
	for(int i=1;i<size;++i)
	{
		if (chars[i-1]=='r')
		{
			left[i][0]=left[i-1][0]+1;
			left[i][1]=0;
		}
		else if(char[i-1]=='b')
		{
			left[i][1]=left[i-1][1]+1;
			left[i][0]=0;
		}
		
	}

}
