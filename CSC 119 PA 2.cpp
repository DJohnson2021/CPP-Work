#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class romanType
{
	private:
		string romanNum; //string of romannumerals
		int positiveIntegerNum; //positive integer
	public:
		romanType();
		void setRomanNum(string roman);
		int convertToInteger();
		void printInteger(char request);
};

romanType::romanType();
void romanType::setRomanNum(string roman);
int romanType::convertToInteger();
void romanType::printInteger(char request);

int main()
{
	romanType();
	
	string roman;
	char userChoice;
	
	cout << "Enter  a roman numeral: ";
	cin >> roman;
	
	setRomanNum(roman);
	
	convertToInteger();
	
	cout << "Press 'R' for roman numeral or 'P' for positive integer: ";
	cin >> userChoice;
	
	printInteger(userChoice);
	
	system("pause");
	return 0;
}


romanType::romanType()
{
	romanNum = "";
	positiveIntegerNum = 0;
}

void romanType::setRomanNum(string roman)
{
	romanNum = roman;
}

int romanType::convertToInteger()
{
		
	int i = 0;
	int length = 0;
	length = romanNum.length();
	
	for(unsigned i = 0; i < length - 1; i++)
	{
		switch(romanNum[i])
		{
			case 'M':
				positiveIntegerNum += 1000;
				break;
			case 'D':
				positiveIntegerNum += 500;
				break;
			case 'C':
				positiveIntegerNum += 100;
				break;
			case 'L':
				positiveIntegerNum += 50;
				break;
			case 'X':
				positiveIntegerNum += 10;
				break;
			case 'V':
				positiveIntegerNum += 5;
				break;
			case 'I':
				positiveIntegerNum += 1;
				break;
		}
	}
}

void romanType::printInteger(char request)
{
	if(request == 'R')
	{
		cout << "Roman Numeral: " << romanNum << endl;
	}
	else if(request == 'P')
	{
		cout << "Positive Integer: " << positiveIntegerNum << endl;
	}
	else
	{
		cout <<  "Invalid Selection" << endl;
	}
}
