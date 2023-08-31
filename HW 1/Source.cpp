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
void readFile(string fileText);

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
	do
	{
		int option = inputInteger("\tOption: ");

		switch (option)
		{
		case 0: exit(0);
			break;
		case 1: asciiMenu();
			break;
		default: cout << "ERROR-3A: Invalid input. Must be from 0..3.\n";
		}
	} while (true);
}
void asciiMenu()
{
	char option;

	string textString = "";
	string fileText = "";

	system("cls");
	remove("text.bin");

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
			case 'A': fileText = "";
				textString = inputString("\n\tEnter a text line: \n\t", true);
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
			case 'D': readFile(fileText);
				break;
			case '0': cout << endl;
				system("pause");
				system("cls");
				menu();
				chooseOption();
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

	}

	for (int i = 0; i < textString.length(); i++)
	{
		binaryFile << int(textString[i]) << " ";
	}

	binaryFile.close();

	cout << endl << "File, test.bin, has been written and saved.\n";
}
void readFile(string fileText)
{
	string textLine;
	ifstream readFile;

	readFile.open("text.bin", ios::binary);

	if (!readFile)
	{
		cout << "\tFile did not open\n";

	}
	else if (fileText == "")
	{
		cout << "\tFile did not open\n";
	}
	else
	{
		getline(readFile, textLine);

		readFile.close();

		cout << endl << "\tReading file, test.bin...\n" << "\t" << textLine << endl;
	}
} 