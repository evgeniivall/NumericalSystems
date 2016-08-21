#pragma once	//Make sure that this header file is included only once
#include "math.h"
#include <iostream>

extern unsigned long long Dec;
extern int iBinN;

//CONVERTING FROM DIFFERENT NUMERICAL SYSTEMS TO THE DECIMAL
unsigned long long convertingToDec(int arrayToBin[], int iBase, int iInputN)
{
	unsigned long long convertedDec = 0;
	for (int i = 0; i < iInputN; i++)
	{
		convertedDec += (pow(iBase, i)*arrayToBin[iInputN - 1 - i]);
	}
	return convertedDec;
}


//CONVERTING FROM DECIMAL NUMERICAL SYSTEM TO THE BINARY
int decToBin(unsigned long long decNumber)
{
	int *binArray = new int[iBinN];

	for (int i = iBinN - 1; i >= 0; i--)
	{
		binArray[i] = decNumber % 2;
		decNumber = decNumber / 2;
	}

	int iAddition;
	iAddition = 4 - (iBinN % 4); //Calculating the number of addtional zero`s

	if (iAddition != 4)
	{
		for (int i = 0; i < iAddition; i++)
		{
			std::cout << 0;		//Outputting additional zero`s
		}
	}
	for (int i = 0; i < iBinN; i++)	
	{
		std::cout << binArray[i];

		if ((i + 1 + iAddition) % 4 == 0)
			std::cout << " ";	//Outputting space after every 4 digits
	}
	delete[]binArray;
	return 0;
}

//CONVERTING FROM DECIMAL NUMERICAL SYSTEM TO THE OCTAL
int decToOct(unsigned long long dec_number)
{
	int n, iAddition;
	//Calculating the length of number in the octal system
	n = iBinN / 3;
	if ((iBinN % 3) > 0)
	{
		n++;
	}
	int *octArray = new int[n];
	for (int i = n - 1; i >= 0; i--)
	{
		octArray[i] = dec_number % 8;
		dec_number = dec_number / 8;
	}

	iAddition = 3 - (n % 3);
	std::cout << 0;
	for (int i = 0; i < n; i++)
	{
		std::cout << octArray[i];
		if ((i + 1 + iAddition) % 3 == 0)
			std::cout << " ";	//Outputting space after every 3 digits
	}
	delete[]octArray;
	return 0;
}

//CONVERTING FROM DECIMAL NUMERICAL SYSTEM TO THE HEXADECIMAL
int decToHex(unsigned long long dec_number)
{
	int n, iAddition;
	//Calculating the length of number in the hexadecimal system
	n = iBinN / 4;
	if ((iBinN % 4) > 0)
	{
		n++;
	}
	int *hexArray = new int[n];
	for (int i = n - 1; i >= 0; i--)
	{
		hexArray[i] = dec_number % 16;
		dec_number = dec_number / 16;
	}

	iAddition = 4 - (n % 4);
	std::cout << "0x";
	for (int i = 0; i < n; i++)
	{
		switch (hexArray[i])
		{
		case 10: std::cout << "A"; break;
		case 11: std::cout << "B"; break;
		case 12: std::cout << "C"; break;
		case 13: std::cout << "D"; break;
		case 14: std::cout << "E"; break;
		case 15: std::cout << "F"; break;
		default: std::cout << hexArray[i];
		}
		if ((i + 1 + iAddition) % 4 == 0)
			std::cout << " ";	//Outputting space after every 4 digits
	}

	delete[]hexArray;
	return 0;
}