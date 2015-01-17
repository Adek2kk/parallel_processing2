// PR2_wzorce.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include <time.h>
#include <string>
#include <iostream>

using namespace std;

string text="123adek321mescam123adek321mescam321mescam123adek321mescam123adek321mescam321mescam123adek321mescam123adek321mescam321mescam123adek321mescam123adek321mescam321mescam123adek321mescam123adek321mescam321mescam123adek321mescam123adek321mescam321mescam123adek321mescam123adek321mescam321mescam123adek321mescam123adek321mescam321mescam123adek321mescam123adek321mescam321mescam123adek321mescam123adek321mescam321mescam123adek321mescam123adek321mescam321mescam123adek321mesc";

int find_pattern(string patt)
{
	int sum_patt=0;
	bool check;
	for(int i=0;i<=text.length()-patt.length();i++)
	{
		if(patt[0]==text[i])
		{
			check=true;
			for(int j=1;j<patt.length();j++)
			{
				if(patt[j]!=text[i+j])
				{
					check=false;
					break;
				}
			}
			if(check==true)
			{
				sum_patt++;
				check=false;
			}
		}
	}
return sum_patt;
}


int main(int argc, char* argv[])
{
string pattern[4];
int result[4];
pattern[0]= "mescam";
pattern[1]= "adek";
pattern[2]= "12";
pattern[3]= "21";
clock_t start, stop;
start = clock();
for(int i=0; i<4;i++)
{
	result[i]=find_pattern(pattern[i]);
	printf("Wzorzec:%s Wynik:%d\n",pattern[i].c_str(),result[i]);

}
stop = clock();
printf("Czas przetwarzania wynosi %f sekund\n",((double)(stop - start)/1000.0));
}