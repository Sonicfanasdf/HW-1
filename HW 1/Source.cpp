#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include "input.h"
using namespace std;

void menu();
void chooseOption();
void asciiMenu();
void writeFile(string textString);
void readFile();

int main()
{
	menu();
	chooseOption();
	return 0;
}
void menu()
{
	cout << "CMPR131 - Chapter 1 Software Development by Joe B\n";
	cout <<
		"==========================================================\n";
	cout << "\t1> ASCII Text To ASCII Numbers\n";
	cout << "\t2> Base Converter\n";
	cout << "\t3> Descriptive Statistics\n";
	cout << "----------------------------------------------------------\n";
		cout << "\t0> exit\n";
	cout <<
		"==========================================================\n";
}
void chooseOption()
{
	int option = inputInteger("Option: ", true);
	switch (option)
	{
	case 1: asciiMenu();
		break;
	}
}
void asciiMenu()
{
	char option;

	string textString = "";

	system("cls");

	do
	{
		cout << endl;
		cout << "1> ASCII Text To ASCII Numbers\n";
		cout <<
			"==========================================================\n";
		cout << "\tA> Enter a text string\n";
		cout << "\tB> Convert the text string to ASCII numbers\n";
		cout << "\tC> Save the converted ASCII numbers into a binary file\n";
		cout << "\tD> Read the binary file\n";
		cout << "----------------------------------------------------------\n";
		cout << "\t0> return\n";
		cout <<
			"==========================================================\n";

		option = toupper(inputChar("\tOption: ", true));

		switch (option)
		{
		case 'A': textString = inputString("\n\tEnter a text line: \n\t", true);
			break;
		case 'B': 
			if (textString == "")
		{
			cout << "\n\tERROR: empty input text.\n";

		}
			else
		{
				cout << endl << "\tConverted to ASCII numbers: \n\t";

				for (int i = 0; i < textString.length(); i++)
				{
					cout << int(textString[i]) << " ";
				}

				cout << endl;
		}
			break;
		case 'C': writeFile(textString);
			break;
		case 'D': readFile();

		}
	} while (true);
}
void writeFile(string textString)
{
	ofstream binaryFile;

	binaryFile.open("text.bin", ios::binary);

	if (!binaryFile)
	{
		cout << "File did not open\n";

		exit(1);
	}

	for (int i = 0; i < textString.length(); i++)
	{
		binaryFile << int(textString[i]) << " ";
	}

	binaryFile.close();

	cout << endl << "File, test.bin, has been written and saved.\n";
}
void readFile()
{
	string textLine;
	ifstream readFile;

	readFile.open("text.bin", ios::binary);

	if (!readFile)
	{
		cout << "File did not open\n";

		exit(1);
	}

	getline(readFile, textLine);

	readFile.close();

	cout << endl  << "\t" << textLine << endl;
}