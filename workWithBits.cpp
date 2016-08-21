#include <iostream>
#include <string>

using namespace std;

//Variables are defined in main.cpp
extern unsigned long long Dec;
extern int iBinN;

//Functions are defined in conversionBetweenSystems.h
extern int decToBin(unsigned long long decNumber);
extern unsigned long long convertingToDec(int arrayToBin[], int iBase, int iInputN);
extern int decToOct(unsigned long long dec_number);
extern int decToHex(unsigned long long dec_number);

int recognition(char cSymbol);	//Conversion symbols of string(char) to numbers(int)
int* indexInput();				//Inputting indices in the string type and conversion them into the array of indices(int)
int bitsInversion();			//Bits inversion
int bitsSet();					//Setting the bit value
int bitsDefinition();			//Definition of the bit value
int bitsParity(unsigned long long inputNumber, int lenght);//Calculating bit of parity
int bitsRevers(unsigned long long inputNumber, int lenght);//Reversing bits relatively the center of number



int operationsWithBits()
{
	int choice;
	cout << endl << "Operations with bits" << endl;
	cout << "Your number contains " << iBinN << " bits" << endl;

again:
	cout << "Chose operation:\n1 - Calculating bit of parity\n2 - Definition of the bit value\n3 - Inversion of bits\n4 - Setting the value of bits\n5 - Reversing bits relatively the center\n6 - Exit" << endl;
	cin >> choice;
	switch (choice)		//Menu
	{
	case 1: bitsParity(Dec, iBinN);		break;
	case 2: bitsDefinition();			break;
	case 3: bitsInversion();			break;
	case 4: bitsSet();					break;
	case 5: bitsRevers(Dec, iBinN);		break;
	case 6:	return 0;
	default:
		{
			cout << "Wrong digit input. Please, try again.\n";
			goto again;
		}

	}
	operationsWithBits();	//Recursion
	return 0;
}

//BITS INVERSION
int bitsInversion()
{
	int max = 0, choice, choice1;
	int *indexArray;
	unsigned long long invertedNumber;

	unsigned long long maskNumber;
again:
	cout << "What indices do you want to invert?\n1 - All\n2 - Certain\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		int *mask = new int[iBinN];
		for (int i = 0; i < iBinN; i++)
		{
			mask[i] = 1;
		}
		cout << "Input number: \t\t\t";
		decToBin(Dec);
		cout << endl;
		cout << "Mask: \t\t\t\t";
		maskNumber = convertingToDec(mask, 2, iBinN);
		decToBin(maskNumber);
		delete[]mask;
		break;
	}
	case 2:
	{
		indexArray = indexInput(); //Array containing indices(int) of bits that have to be inverted

		for (int i = 0; i < iBinN; i++) //Calculating the greatest index
		{
			if (max < indexArray[i])
				max = indexArray[i];
		}

		int *mask = new int[max + 1];		//Creating mask array

		for (int i = 0; i < max + 1; i++)	//Fill mask array with "0"
		{
			mask[i] = 0;
		}

		for (int i = 0; i < iBinN; i++)		//Fill mask array with "1" in chosen indeces
		{
			if (indexArray[i] >= 0)
				mask[max + 1 - indexArray[i] - 1] = 1;
		}

		maskNumber = convertingToDec(mask, 2, max + 1);
		cout << "Input number: \t\t\t";
		decToBin(Dec);
		cout << endl;
		cout << "Mask: \t\t\t\t";
		decToBin(maskNumber);
		delete[]mask;
		delete[iBinN]indexArray;
		break;
	}
	default:
	{
		cout << "Wrong digit input. Please, try again.\n";
		goto again;
	}
	}

	invertedNumber = Dec ^ maskNumber;
	cout << endl;
	cout << "Inverted number:\t\t";
	decToBin(invertedNumber);
	cout << endl << "Hexadecimal system: \t\t";
	decToHex(invertedNumber);
	cout << endl << "Octal system: \t\t\t";
	decToOct(invertedNumber);
	cout << endl << "Decimal system: \t\t" << invertedNumber;
again1:
	cout << endl << "Save result?\n1 - Yes\n2 - No" << endl;
	cin >> choice1;
	switch (choice1)
	{
	case 1: Dec = invertedNumber; break;
	case 2: break;
	default:
		{
			cout << "Wrong digit input. Please, try again.\n";
			goto again1;
		}

	}
	cout << endl;

	return 0;
}
//INPUTTING INDICES IN THE STRING TYPE AND CONVERSION THEM INTO THE ARRAY OF INDICES(INT)
int *indexInput()
{
	int *index = new int[iBinN];
	for (int i = 0; i < iBinN; i++)
	{
		index[i] = -1;
	}
	string sIndices;
	cout << "Enter through the gap indices (from 0 to " << iBinN - 1 << ") of bits: ";

	cin.ignore();
	getline(cin, sIndices);

	int ch = 0;
	int a = 0;
	while (sIndices[a] != '\0')
	{
		a++;
	}
	int j = 0;
	for (int i = 0; i < a; i++)
	{
		if (sIndices[i] == ' ')
		{
			ch = 0;
		}
		else
		{
			if (ch > 0)
			{
				index[j - 1] = index[j - 1] * 10 + recognition(sIndices[i]);
				ch++;
			}
			else
			{
				index[j] = recognition(sIndices[i]);
				j++;
				ch++;
			}
		}
	}

	return index;
}

//CONVERSION SYMBOLS OF STRING(CHAR) TO NUMBERS(INT)
int recognition(char cSymbol)
{
	int iDigit;
	switch (cSymbol)
	{
	case '0': iDigit = 0; break;
	case '1': iDigit = 1; break;
	case '2': iDigit = 2; break;
	case '3': iDigit = 3; break;
	case '4': iDigit = 4; break;
	case '5': iDigit = 5; break;
	case '6': iDigit = 6; break;
	case '7': iDigit = 7; break;
	case '8': iDigit = 8; break;
	case '9': iDigit = 9; break;
	}
	return iDigit;
}

//SETTING THE BIT VALUE
int bitsSet()
{
	int max = 0, choice, choice1;
	int *indexArray;
	unsigned long long setNumber;
	unsigned long long maskNumber;

	indexArray = indexInput(); //Array, containing indices of bits to be set

	for (int i = 0; i < iBinN; i++)			//Calculating the greatest index
	{
		if (max < indexArray[i])
			max = indexArray[i];
	}

	int *mask = new int[max + 1];			//Creating mask array

	for (int i = 0; i < max + 1; i++)		//Fill mask array with "0"
	{
		mask[i] = 0;
	}

	for (int i = 0; i < iBinN; i++)			//Fill mask array with "1" in chosen indeces
	{
		if (indexArray[i] >= 0)
			mask[max + 1 - indexArray[i] - 1] = 1;
	}
	maskNumber = convertingToDec(mask, 2, max + 1);
	setNumber = Dec | maskNumber;
again:
	cout << "Select the value you want to set bits with: ";
	cin >> choice;
	cout << "Input number: \t\t\t";
	decToBin(Dec);
	cout << endl;
	cout << "Mask: \t\t\t\t";
	decToBin(maskNumber);
	cout << endl;
	switch (choice)
	{
		case 0:
		{
			cout << "Transformed number:\t\t";
			setNumber = setNumber ^ maskNumber;
			decToBin(setNumber);
			break;
		}
		case 1:
		{
			cout << "Transformed number:\t\t";
			decToBin(setNumber);
			break;

		}
	default:
	{
		cout << "Wrong digit input. Please, try again.\n";
		goto again;
	}
	}
	cout << endl << "Hexadecimal system: \t\t";
	decToHex(setNumber);
	cout << endl << "Octal system: \t\t\t";
	decToOct(setNumber);
	cout << endl << "Decimal system: \t\t" << setNumber;
again1:
	cout << endl << "Save result ? \n1 - Yes\n2 - No" << endl;
	cin >> choice1;
	switch (choice1)
	{
	case 1: Dec = setNumber; break;
	case 2: break;
	default:
	{
		cout << "Wrong digit input. Please, try again.\n";
		goto again1;
	}

	}
	cout << endl;
	delete[]mask;
	delete[iBinN]indexArray;
	return 0;
}

//CALCULATING BIT OF PARITY
int bitsParity(unsigned long long inputNumber, int lenght)
{
	int counter = 0;
	unsigned long long mask = 1;
	for (int i = 0; i < lenght; i++)
	{
		if (inputNumber & mask)
			counter++;
		mask = mask << 1;
	}
	cout << "Quantity of \"1\" in binary number: " << counter << endl;
	if (counter % 2 == 0)
		cout << "Bit of parity = 0, the number of \"1\" is even" << endl;
	else
	{
		cout << "Bit of parity = 1, the number of \"1\" is odd" << endl;
	}
	return 0;
}
//REVERSING BITS RELATIVELY THE CENTER OF NUMBER
int bitsRevers(unsigned long long inputNumber, int lenght)
{
	int choice1;
	unsigned long long mask = 1, revers = 0;
	for (int i = 0; i < lenght; i++)
	{
		revers = revers << 1;
		if (inputNumber & mask)
			revers = revers ^ 1;
		mask = mask << 1;
	}
	cout << "Input number: \t\t\t";
	decToBin(Dec);
	cout << endl;
	cout << "Transformed number:\t\t";
	decToBin(revers);
	cout << endl << "Hexadecimal system: \t\t";
	decToHex(revers);
	cout << endl << "Octal system: \t\t\t";
	decToOct(revers);
	cout << endl << "Decimal system: \t\t" << revers;
again:
	cout << endl << "Save result?\n1 - Yes\n2 - No" << endl;

	cin >> choice1;
	switch (choice1)
	{
	case 1: Dec = revers; break;
	case 2: break;
	default:
		{
			cout << "Wrong digit input. Please, try again.\n";
			goto again;
		}

	}
	cout << endl;
	return 0;
}
//DEFINITION OF THE BIT VALUE
int bitsDefinition()
{
	int index;
	unsigned long long maskNumber;

	cout << "Input the index of bit(from 0 to "<< iBinN - 1 << "), you want to define:";
	cin >> index;
	int *mask = new int[iBinN];			//Creating mask array

	for (int i = 0; i < iBinN; i++)		//Fill mask array with "0"
	{
		mask[i] = 0;
	}
	mask[iBinN - 1 - index] = 1;
	maskNumber = convertingToDec(mask, 2, iBinN);
	if (Dec & maskNumber)
	{
		cout << "Bit #" << index << " = " << 1;
	}
	else
	{
		cout << "Bit #" << index << " = " << 0;
	}
	delete[]mask;
	cout << endl;

	return 0;
}
