#include <iostream>
#include <string>
#include "conversionBetweenSystems.h"

using namespace std;
unsigned long long Dec;
int iBinN;

extern int operationsWithBits();	//Function is defined in workWithBits.cpp

//Inputting the number in string type and conversion it into the array of digits(int)
unsigned long long inputAndRecognition(int base);

int main()
{
	int inputBase = 0;

	unsigned long long worker;

	while ((inputBase != 10) && (inputBase != 2) && (inputBase != 16) && (inputBase != 8))
	{
		cout << "Choose input system: dec - 10, hex - 16, oct - 8, bin - 2" << endl;
		cin.clear();
		cin >> inputBase;
	}
	inputAndRecognition(inputBase); //Converting from different numerical systems to the decimal
	int counter = 1;
	worker = Dec;
	while (worker>1)			//Calculating the lenght of number in the binary system
	{
		worker = worker >> 1;
		counter++;
	}
	iBinN = counter;
	
	cout << endl << "Hexadecimal system: \t\t";
	decToHex(Dec);
	cout << endl << "Octal system: \t\t\t";
	decToOct(Dec);
	cout << endl << "Decimal system: \t\t" << Dec;
	cout << endl << "Binary system: \t\t\t";
	decToBin(Dec);
	cout << endl;

	operationsWithBits();

	return 0;
}


//INPUTTING THE NUMBER IN STRING TYPE AND CONVERSION IT INTO THE ARRAY OF DIGITS(INT)
unsigned long long inputAndRecognition(int base)
{
	string sNumber;
	int iStringLenght = 0;
	cout << "Input your number: ";
again:								//The label in the case of recognition failure

	cin >> sNumber;

	while (sNumber[iStringLenght] != '\0')	//Calculating the lenght of string
	{
		iStringLenght++;
	}

	int *arrayAfterRecognation = new int[iStringLenght];
	for (int i = 0; i < iStringLenght; i++)
	{
		switch (sNumber[i])
		{
		case '0': arrayAfterRecognation[i] = 0; break;
		case '1': arrayAfterRecognation[i] = 1; break;
		case '2': arrayAfterRecognation[i] = 2; break;
		case '3': arrayAfterRecognation[i] = 3; break;
		case '4': arrayAfterRecognation[i] = 4; break;
		case '5': arrayAfterRecognation[i] = 5; break;
		case '6': arrayAfterRecognation[i] = 6; break;
		case '7': arrayAfterRecognation[i] = 7; break;
		case '8': arrayAfterRecognation[i] = 8; break;
		case '9': arrayAfterRecognation[i] = 9; break;
		case 'A': arrayAfterRecognation[i] = 10; break;
		case 'a': arrayAfterRecognation[i] = 10; break;
		case 'B': arrayAfterRecognation[i] = 11; break;
		case 'b': arrayAfterRecognation[i] = 11; break;
		case 'C': arrayAfterRecognation[i] = 12; break;
		case 'c': arrayAfterRecognation[i] = 12; break;
		case 'D': arrayAfterRecognation[i] = 13; break;
		case 'd': arrayAfterRecognation[i] = 13; break;
		case 'E': arrayAfterRecognation[i] = 14; break;
		case 'e': arrayAfterRecognation[i] = 14; break;
		case 'F': arrayAfterRecognation[i] = 15; break;
		case 'f': arrayAfterRecognation[i] = 15; break;
		default:
		{
			cout << "Wrong digit input. Please, try again.\n";
			goto again;
		}

		}
	}
	Dec = convertingToDec(arrayAfterRecognation, base, iStringLenght); 
	delete[]arrayAfterRecognation;
	return Dec;
}
