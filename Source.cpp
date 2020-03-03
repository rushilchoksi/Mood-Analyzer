#include "iostream"
#include "fstream"
#include "string.h"
#define TRUE 1
using namespace std;
int splitString(char *base, char target[10][20])
{
	int n=0,i,j=0;
	for(i=0;TRUE;i++)
	{
		if(base[i]!=' ')
			target[n][j++]=base[i];
		else
		{
			target[n][j++]=' ';
			j++;
			target[n][j++]='\0';
			n++;
			j=0;
		}
		if(base[i]=='\0')
			break;
	}
	return n;
}
int main()
{
	int n, i, l, flag = 0;
	int sum=0;
	float div;
	char str[80], arr[10][20];
	char tempConfidence[80], tempAnalytical[80];
	char tempSadness[80], tempJoy[80], tempFear[80], tempAnger[80];
	int varAnger=0, varFear=0, varJoy=0, varSadness=0, varAnalytical=0, varConfident=0;
	fstream Confidence, Analytical, Sadness, Joy, Fear, Anger;
	cout << "Enter a string: ";
	cin.get(str,80);	
	n=splitString(str,arr);
	l=strlen(arr[n]);
	for (i=l; i<l+1; i++)
	{
		arr[n][i]=' ';
		arr[n][i+1]='\0';
	}
	for(i=0;i<=n;i++)
	{
		Confidence.open("Confident.txt", ios::in);
		while (Confidence.eof() == 0)
		{
			Confidence >> tempConfidence;
			if(strstr(arr[i],tempConfidence) != 0)
			{
				varConfident = 1;
				flag = 1;
			}
		}
		Confidence.close();
		Analytical.open("Analytical.txt", ios::in);
		while (Analytical.eof() == 0)
		{
			Analytical >> tempAnalytical;
			if (strstr(arr[i],tempAnalytical) != 0)
			{
				varAnalytical = 1;
				flag = 1;
			}
		}
		Analytical.close();
		Sadness.open("Sadness.txt", ios::in);
		while (Sadness.eof() == 0)
		{
			Sadness >> tempSadness;
			if (strstr(arr[i],tempSadness) != 0)
			{
				varSadness = 1;
				flag = 1;
			}
		}
		Sadness.close();
		Joy.open("Joy.txt", ios::in);
		while (Joy.eof() == 0)
		{
			Joy >> tempJoy;
			if (strstr(arr[i],tempJoy) != 0)
			{
				varJoy = 1;
				flag = 1;
			}
		}
		Joy.close();
		Fear.open("Fear.txt", ios::in);
		while (Fear.eof() == 0)
		{
			Fear >> tempFear;
			if (strstr(arr[i],tempFear) != 0)
			{
				varFear = 1;
				flag = 1;
			}
		}
		Fear.close();
		Anger.open("Anger.txt", ios::in);
		while (Anger.eof() == 0)
		{	
			Anger >> tempAnger;
			if (strstr(arr[i],tempAnger) != 0)
			{
				varAnger = 1;
				flag = 1;
			}
		}
		Anger.close();
	}
	if (flag == 0)
		cout << "\nI'm not sure I understand.\n";
	sum+=varAnger+varFear+varJoy+varSadness+varAnalytical+varConfident;
	div=(100/sum);
	if(varAnger==1)
		varAnger=div;
	if(varFear==1)
		varFear=div;
	if(varJoy==1)
		varJoy=div;
	if(varSadness==1)
		varSadness=div;
	if(varAnalytical==1)
		varAnalytical=div;
	if(varConfident==1)
		varConfident=div;
	cout << "\n*Based on my analysis, I've detected this*";
	cout << "\nAnger: \t\t\t"<< varAnger << "%" << endl;
	cout << "Fear: \t\t\t" << varFear << "%" << endl;
	cout << "Joy: \t\t\t" << varJoy << "%" << endl;
	cout << "Sadness: \t\t" << varSadness << "%" << endl;
	cout << "Analytical: \t\t" << varAnalytical << "%" << endl;
	cout << "Confident: \t\t" << varConfident << "%" << endl;
}
