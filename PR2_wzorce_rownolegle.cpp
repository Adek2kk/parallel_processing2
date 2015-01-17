// PR2_wzorce.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include <time.h>
#include <string>
#include <iostream>
#include <omp.h>


using namespace std;

string text="123adek321mescam123adek321mescam321";

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
string pattern[2];
int result[2];
pattern[0]= "mescam";
pattern[1]= "adek";
#pragma omp parallel for 
for(int i=0; i<2;i++)
{
	result[i]=find_pattern(pattern[i]);
	cout<<"Watek"<<omp_get_thread_num()<<" Wynik: "<<result[i]<<endl;
}

cout<<result[0]<<" "<<result[1]<<endl;
}