#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <cmath>
#include "input.h"
using namespace std;

void menu();
void chooseOption();
void asciiMenu();
void writeFile(string textString);
void readFile(string fileText);
void statisticsMenu();
int fileSize(ifstream& dataFile, string fileOption);
double getMean(int* array, int size);
void sortArray(int*& dataArray, int size);
void makeArray(int*& tempArray, int& size, ifstream& tempFile, string dataOption);
double getMedian(int* array, int size);
double getMinimum(int* tempArray);
double getMax(int* tempArray, int size);
double getRange(int* tempArray, int size);
double getSize(int tempSize);
double getSum(int* tempArray, int size);
void getFrequency(int* tempArray, int size);

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
		case 3: statisticsMenu();
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
void statisticsMenu()
{
	ifstream dataFile;
	char option = '\0';
	int size = 0;
	string fileOption;
	int* newArray = new int[size];
	

	system("cls");

	do
	{
		cout << "\n3> Descriptive Statistics\n";
		cout << "==========================================================================================\n";
		cout << "\tA> Read data file, store into a sorted dynamic array and display the data set\n";
		cout << "\tB> Minimum                     M> Mid Range\n";
		cout << "\tC> Maximum                     N> Quartiles\n";
		cout << "\tD> Range                       O> Interquartile Range\n";
		cout << "\tE> Size                        P> Outliers\n";
		cout << "\tF> Sum                         Q> Sum of Squares\n";
		cout << "\tG> Mean                        R> Mean Absolute Deviation\n";
		cout << "\tH> Median                      S> Root Mean Square\n";
		cout << "\tI> Frequencies                 T> Standard Error of the Mean\n";
		cout << "\tJ> Mode                        U> Coefficient of Variation\n";
		cout << "\tK> Standard Deviation          V> Relative Standard Deviation\n";
		cout << "\tL> Variance\n";
		cout << "\tW> Display all results and write to an output text file\n";
		cout << "------------------------------------------------------------------------------------------\n";
		cout << "\t0> return\n";
		cout << "==========================================================================================\n";

		option = toupper(inputChar("\tOption: "));

		switch (option)
		{
		case 'A':


			fileOption = inputString("\n\tEnter a data file name: ", true);

			makeArray(newArray, size, dataFile, fileOption);

			cout << endl << "\tData set with " << size << " data: \n";
			cout << "\t{ ";

			for (int m = 0; m < size -1; m++)
			{
				cout << newArray[m] << ", ";
			}

			cout << newArray[size - 1] << " }\n";

			break;
		case 'B': cout << "\n\tMinimum                     = " << getMinimum(newArray) << endl;
			break;
		case 'C': cout << "\n\tMaximum                     = " << getMax(newArray, size) << endl;
			break;
		case 'D': cout << "\n\tRange                       = " << getRange(newArray, size) << endl;
			break;
		case 'E': cout << "\n\tSize                        = " << getSize(size) << endl;
			break;
		case 'F': cout << "\n\tSum                         = " << getSum(newArray, size) << endl;
			break;
		case 'G': cout << "\n\tMean                        = " << getMean(newArray, size) << endl;
			break;
		case 'H': cout << "\n\tMedian                      = " << getMedian(newArray, size) << endl;
			break;
		case 'I': getFrequency(newArray, size);
		}
	} while (true);
}
int fileSize(ifstream &dataFile, string fileOption)
{
	int size = 0;
	int data = 0;

	dataFile.open(fileOption);

	if (!dataFile.is_open())
	{
		cout << "\n\tFile did not open\n";
	}
	else
	{
		while (!dataFile.eof())
		{
			size++;
			dataFile >> data;
		}

	}
	dataFile.close();
	return size;
}
void sortArray(int* &dataArray, int size)
{
	int smallest = 0;
	int placeHolder = 0;

	for (int i = 0; i < size - 1; i++)
	{
		smallest = i;

		for (int j = i + 1; j < size; j++)
		{
			if (dataArray[j] < dataArray[smallest])
			{
				smallest = j;
			}
		}
		placeHolder = dataArray[i];
		dataArray[i] = dataArray[smallest];
		dataArray[smallest] = placeHolder;
	}
}
double getMean(int* array, int size)
{
	double sum = 0;
	double mean = 0;

	for (int i = 0; i < size; i++)
	{
		sum += array[i];
	}

	mean = sum / size;

	return mean;
}
double getMedian(int* array, int size)
{
	double median = 0;
	int middle = 0;

	if (size % 2 == 0)
	{
		middle = size / 2;

		median = (double(array[middle - 1]) + double(array[middle])) / 2;
	}
	else
	{
		middle = size / 2;

		median = array[middle];
	}

	return median;
}
void makeArray(int*& tempArray, int &size, ifstream& tempFile, string dataOption)
{
	int amount = 0;

	amount = fileSize(tempFile, dataOption);

	size = amount;

	int* altArray = new int[amount];

	tempFile.open(dataOption);

	if (amount == 0)
	{

	}
	else if (!tempFile.is_open())
	{
		cout << "\n\tFile did not open\n";
	}
	else
	{
		for (int i = 0; i < amount; i++)
		{
			tempFile >> altArray[i];
		}
		tempFile.close();

		for (int k = 0; k < amount; k++)
		{
			tempArray[k] = altArray[k];
		}


		sortArray(tempArray, size);
	}
	delete[] altArray;
}
double getMinimum(int* tempArray)
{
	double minimum = 0;

	minimum = tempArray[0];

	return minimum;
	
}
double getMax(int* tempArray, int size)
{
	double maximum = 0;

	maximum = tempArray[size - 1];

	return maximum;
}
double getRange(int* tempArray, int size)
{
	double range = 0;

	range = tempArray[size - 1] - tempArray[0];

	return range;
}
double getSize(int tempSize)
{
	double size = 0;

	size = tempSize;

	return size;
}
double getSum(int* tempArray, int size)
{
	double sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += tempArray[i];
	}

	return sum;
}
void getFrequency(int* tempArray, int size)
{
	double counter = 0;
	double percentage = 0;
	double placeHolder = 1;

	cout << "\n\tFrequency Table\n";
	cout << "\t\tValue   Frequency       Frequency %\n";

	for (int i = 0; i < size; i++)
	{
		counter = 0;
		double tracker = 0;

		for (int j = 0; j < size; j++)
		{
			if (tempArray[i] == tempArray[j])
			{
				counter++;
				tracker = tempArray[j];
			}
		}
		percentage = (counter / size) * 100;

		for (int k = 0; k < i; k++)
		{
			if (tempArray[k] == tracker)
			{
				placeHolder = tempArray[k];
			}
		}
		
		if (placeHolder == tracker)
		{
			
		}
		else
		{
			cout << "\t\t" << tempArray[i] << "      " << counter << "               " << percentage << endl;
		}
	}
}

