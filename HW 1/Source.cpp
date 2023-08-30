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
	string fileText = "";

	system("cls");

	do
	{
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
		do
		{
			option = toupper(inputChar("\tOption: "));

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
					fileText = textString;

					cout << endl << "\tConverted to ASCII numbers: \n\t";

					for (int i = 0; i < textString.length(); i++)
					{
						cout << int(textString[i]) << " ";
					}

					cout << endl;
				}
				break;
			case 'C':
				if (fileText == "")
				{
					cout << "\n\tERROR: empty binary text.\n";
				}
				else
				{
				writeFile(textString);
				}
				break;
			case 'D': readFile();
				break;
			default: cout << "ERROR-1A: Invalid input. Must be '0','A','B','C', or 'D'\n";



			}
		} while (option != '0' && option != 'A' && option != 'B' && option != 'C' && option != 'D');
		cout << endl;
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

	cout << endl << "\tReading file, test.bin...\n" << "\t" << textLine << endl;
} 