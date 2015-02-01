// PR2_wzorce.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include <time.h>
#include <string>
#include <iostream>
#include <omp.h>
#include <fstream>

using namespace std;

string text="";
string pattern[50];

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

void readTextFile()
{
	ifstream textFile("text.txt");
	string textLine="", textTemp="";
	while (!textFile.eof()) 
	{ 
	  textFile >> textLine;
	  textTemp = textTemp + " " + textLine;
	}
	textTemp.erase(0,4);
	for(int i=0;i<1000;i++)
	{
		text = text + " " + textTemp;
	}

}
void readPatternFile()
{
	ifstream textFile("pattern.txt");
	string textLine="";
	for(int i=0;i<50;i++)
	{
	  textFile >> textLine;
	  pattern[i] = textLine;
	}
	pattern[0].erase(0,3);
}

int main(int argc, char* argv[])
{
int result[50];
readTextFile();
readPatternFile();

clock_t start, stop;
start = clock();
#pragma omp parallel for 
for(int i=0; i<50;i++)
{
	result[i]=find_pattern(pattern[i]);
	printf("Wzorzec:%s Watek:%d Wynik:%d\n",pattern[i].c_str(),omp_get_thread_num(),result[i]);
}
stop = clock();
printf("Czas przetwarzania wynosi %f sekund\n",((double)(stop - start)/1000.0));
	
}