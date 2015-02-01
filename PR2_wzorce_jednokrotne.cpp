// PR2_wzorce_jednokrotne.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include <stdio.h>
#include <time.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

string text[1000];
string pattern[50];

int findPattern(string patt,string textCheck)
{
	int sum_patt=0;
	bool check;
	for(unsigned int i=0;i<=textCheck.length()-patt.length();i++)
	{
		if(patt[0]==textCheck[i])
		{
			check=true;
			for(unsigned int j=1;j<patt.length();j++)
			{
				if(patt[j]!=textCheck[i+j])
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
		text[i] = "";
		text[i] = textTemp;
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
cout<<"Start"<<endl;
int result[50];
for(int i=0;i<50;i++) result[i]=0;
readTextFile();
readPatternFile();
cout<<"Dane wczytane"<<endl;
clock_t start, stop;
start = clock();
for(int j=0; j<1000; j++)
{
	for(int i=0; i<50;i++)
	{
		result[i]+=findPattern(pattern[i],text[j]);
	}
}
stop = clock();
/*
for(int i=0; i<50;i++)
{
printf("Wzorzec:%s Wynik:%d\n",pattern[i].c_str(),result[i]);
}
printf("Czas przetwarzania wynosi %f sekund\n",((double)(stop - start)/1000.0));
*/
cout<<((double)(stop - start)/1000.0)<<endl;
}