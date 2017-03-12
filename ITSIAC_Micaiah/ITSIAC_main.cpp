//************************************  PROGRAM IDENTIFICATION  ***************************************
//*                                                                                                   *
//*   PROGRAM FILE NAME:  Project1.cpp          ASSIGNMENT #:  1            Grade: _________          *
//*                                                                                                   *
//*   PROGRAM AUTHOR:     __________________________________________                                  *
//*                                     Micaiah Skolnick                                              *
//*                                                                                                   *
//*   COURSE #:  CSC 40600 11                            DUE DATE:  March 20, 2017                    *
//*                                                                                                   *
//*****************************************************************************************************
//***********************************  PROGRAM DESCRIPTION  *******************************************
//*                                                                                                   *
//*   PROCESS:   NEED TO WRITE THE PROCESS **********************




//*                                                                                                   *
//*   USER DEFINED                                                                                    *
//*    MODULES     : Footer - Prints a footer to signify end of program output                        *
//*                  Header - Prints a header to signify start of program output                      *
//*                  processData - Data from the input file is read into the program and processed    *
//*                  main - Variables are declared, functions are called, and headers are printed     *
//*                  printResults - Read each Op code character and perform the subsequent action.    *
//*                                                                                                   *
//*****************************************************************************************************
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctype.h>
#include <string>
#include <sstream>

using namespace std;

	// Initialize global variables of microcode and machine language counters
int microCounter = 0, machineCounter = 0;

//*************************************  FUNCTION HEADER  *********************************************
void Header(ofstream &Outfile)
{       // Receives – the output fil
		// Task - Prints the output preamble
		// Returns - Nothing
	Outfile << setw(30) << "Micaiah Skolnick ";
	Outfile << setw(17) << "CSC 40600";
	Outfile << setw(15) << "Section 11" << endl;
	Outfile << setw(27) << "Spring 2017";
	Outfile << setw(30) << "Assignment #1" << endl;
	Outfile << setw(35) << "---------------------------------- - ";
	Outfile << setw(35) << "---------------------------------- - " << endl << endl;
	return;
}
//************************************* END OF FUNCTION HEADER  ***************************************
//*************************************  FUNCTION FOOTER  *********************************************
void Footer(ofstream &Outfile)
{
	// Receives – the output file
	// Task - Prints the output salutation
	// Returns - Nothing
	Outfile << endl;
	Outfile << setw(35) << "-------------------------------- - " << endl;
	Outfile << setw(35) << " | END OF PROGRAM OUTPUT | " << endl;
	Outfile << setw(35) << "-------------------------------- - " << endl;
	return;
}
//************************************* END OF FUNCTION FOOTER  ***************************************
void printDataLabel(ofstream&dataOUT, string label) {
	dataOUT << "-----------------------------------------------------------------------" << endl;

	dataOUT << endl << label << endl;
	dataOUT << "-----------------------------------------------------------------------" << endl;
}
//*****************************************************************************************************

int GetOpCode(int MIR)
{
		// Receives - an integer (MIR)
		// Task - depending on the MIR value, returns the respective opCode
		// Returns - an integer (opCode)

	int opCode;  //Initialize opCode

	switch (MIR) // Return op code which corresponds to MIR
	{
	case 0:
		opCode = 8;
		break;
	case 1:
		opCode = 25;
		break;
	case 2:
		opCode = 21;
		break;
	case 3:
		opCode = 23;
		break;
	case 4:
		opCode = 20;
		break;
	case 5:
		opCode = 18;
		break;
	case 6:
		opCode = 28;
		break;
	case 10:
		opCode = 6;
		break;
	case 11:
		opCode = 9;
		break;
	case 12:
		opCode = 25;
		break;
	case 13:
		opCode = 6;
		break;
	case 14:
		opCode = 12;
		break;
	case 15:
		opCode = 29;
		break;
	case 20:
		opCode = 6;
		break;
	case 21:
		opCode = 9;
		break;
	case 22:
		opCode = 25;
		break;
	case 23:
		opCode = 6;
		break;
	case 24:
		opCode = 15;
		break;
	case 25:
		opCode = 29;
		break;
	case 30:
		opCode = 6;
		break;
	case 31:
		opCode = 9;
		break;
	case 32:
		opCode = 25;
		break;
	case 33:
		opCode = 6;
		break;
	case 34:
		opCode = 18;
		break;
	case 35:
		opCode = 29;
		break;
	case 40:
		opCode = 6;
		break;
	case 41:
		opCode = 9;
		break;
	case 42:
		opCode = 1;
		break;
	case 43:
		opCode = 26;
		break;
	case 44:
		opCode = 29;
		break;
	case 50:
		opCode = 5;
		break;
	case 51:
		opCode = 29;
		break;
	case 60:
		opCode = 30;
		break;
	case 61:
		opCode = 29;
		break;
	case 62:
		opCode = 5;
		break;
	case 63:
		opCode = 29;
		break;
	}

	return opCode;
}
//*****************************************************************************************************
string DecToHex(int decimal, int key)
{
		// Receives - A decimal number and an integer which represents the key of conversion
		// Task - Converts the number from decimal to hexadecimal
		// Returns - The converted number

	bool negative = false;

	if (decimal < 0)  // If the number is negative, switch it to positive
	{
		negative = true;
		decimal = -decimal;
	}

	if (key == 2)  // If the number is 2 digits long
	{
		int temp[2] = { 0,0 }; //Initialize temporary array
		char converted[3];  //Initialize converted number character string

		if (decimal == 0 || decimal == -1)  //If the number is zero or -1, set array to 15 (FF)
		{
			temp[0] = 15;
			temp[1] = 15;
		}

		else if (decimal > 16)  //Convert number if bigger tha 16 to its hex equivalent
		{
			temp[0] = (decimal / 16);
			decimal = decimal % 16;
			temp[1] = decimal;
		}
		else if (decimal < 16)
		{
			temp[1] = decimal;
		}

		if (negative)  //If its negative, get compliment
		{
			temp[0] = abs((temp[0] - 15));
			temp[1] = abs((temp[1] - 16));
		}

		for (int j = 0; j < 2; j++)  //Store converted number in hexa notation in 'converted'
		{
			if (temp[j] == 15)
				converted[j] = 'F';
			else if (temp[j] == 14)
				converted[j] = 'E';
			else if (temp[j] == 13)
				converted[j] = 'D';
			else if (temp[j] == 12)
				converted[j] = 'C';
			else if (temp[j] == 11)
				converted[j] = 'B';
			else if (temp[j] == 10)
				converted[j] = 'A';
			else if (temp[j] == 9)
				converted[j] = '9';
			else if (temp[j] == 8)
				converted[j] = '8';
			else if (temp[j] == 7)
				converted[j] = '7';
			else if (temp[j] == 6)
				converted[j] = '6';
			else if (temp[j] == 5)
				converted[j] = '5';
			else if (temp[j] == 4)
				converted[j] = '4';
			else if (temp[j] == 3)
				converted[j] = '3';
			else if (temp[j] == 2)
				converted[j] = '2';
			else if (temp[j] == 1)
				converted[j] = '1';
			else
				converted[j] = '0';
		}

		converted[2] = NULL;

		string hex(converted);  //Store new string with the new converted number

		return hex;
	}
	else  //If the nuber is 4 digits long
	{
		int temp[5] = { 0,0,0,0 };  //Initialize temporary array
		char converted[5];  //Initialize converted number

		if (decimal == 0)  //If the number is zero, set array to 15 (FFFF)
		{
			temp[0] = 15;
			temp[1] = 15;
			temp[2] = 15;
			temp[3] = 15;
		}

		else  //Convert number
		{
			temp[0] = decimal / 4096;
			decimal = decimal % 4096;
			temp[1] = decimal / 256;
			decimal = decimal % 256;
			temp[2] = decimal / 16;
			decimal = decimal % 16;
			temp[3] = decimal;
		}

		if (negative)  //If the number is negative, get compliment
		{
			temp[0] = abs((temp[0] - 15));
			temp[1] = abs((temp[1] - 15));
			temp[2] = abs((temp[2] - 15));
			temp[3] = abs((temp[3] - 16));
		}

		for (int j = 0; j < 4; j++)  //Store converted number in hexa notation in 'converted'
		{
			if (temp[j] == 15)
				converted[j] = 'F';
			else if (temp[j] == 14)
				converted[j] = 'E';
			else if (temp[j] == 13)
				converted[j] = 'D';
			else if (temp[j] == 12)
				converted[j] = 'C';
			else if (temp[j] == 11)
				converted[j] = 'B';
			else if (temp[j] == 10)
				converted[j] = 'A';
			else if (temp[j] == 9)
				converted[j] = '9';
			else if (temp[j] == 8)
				converted[j] = '8';
			else if (temp[j] == 7)
				converted[j] = '7';
			else if (temp[j] == 6)
				converted[j] = '6';
			else if (temp[j] == 5)
				converted[j] = '5';
			else if (temp[j] == 4)
				converted[j] = '4';
			else if (temp[j] == 3)
				converted[j] = '3';
			else if (temp[j] == 2)
				converted[j] = '2';
			else if (temp[j] == 1)
				converted[j] = '1';
			else
				converted[j] = '0';
		}

		converted[4] = NULL;

		string hex(converted);  //Store new string with the new converted number

		return hex;
	}
}
//*****************************************************************************************************
int BinToDec(string binary, int key)
{
		// Receives - A string of 8 or 16 characters and an integer
		//				which represents the key of conversion
		// Task - Converts the string from binary to decimal
		// Returns - The converted number

	int times;  //Initialize number to which power is going to be
				//applied for conversion

	int number = 0;  //Initialize number which represents the converted number

	if (key == 8)  //If the number is 8 bits
	{
		times = 7;  //Set times to 7

		for (int i = 0; i < 8; i++)  //Go through the 8 bit number
		{
			if (binary[i] == '1')  //If a '1' is encountered, calculate and add to number
				number += (int)pow(2, times);

			times--;  //Decrease power for next operation
		}
	}
	else
	{
		times = 15;  //Set times to 15

		if (binary[0] == '0')  //If leftmost bit is 0, then number is positive
		{
			for (int i = 0; i < 16; i++) //Go through the positive 16 bit number
			{
				if (binary[i] == '1')  //If a '1' is encountered, calculate and add to number
					number += (int)pow(2, times);

				times--;  //Decrease power for next operation
			}
		}
		else  //If leftmost bit is 1, then the number is negative
		{
			int count = 0;  //Initialize variable

			for (int i = 15; i >= 0; i--)
			{
				if (count > 0)
				{
					if (binary[i] == '1')  //Since it is a Two's compliment calculate
						binary[i] = '0';   //positive value
					else
						binary[i] = '1';
				}
				if (binary[i] == '1')
					count++;
			}


			for (int i = 0; i < 16; i++)
			{
				if (binary[i] == '1')  //If a '1' is encountered, calculate and add to number
					number += (int)pow(2, times);

				times--;  //Decrease power for next operation
			}

			number *= -1;  //Multiply by -1 to get negative result
		}
	}

	return number;  //return the converted number
}
//*****************************************************************************************************
void getData(ifstream&dataIN, ofstream&dataOUT, int pStorage[256][2]) {

	string data, opBin, operandBin; //Initialize bin numbers and data strings
	int opLocation = 0;  //Initialize control variable for the opLocation in memory
	dataIN >> ws >> data;  //Read white space and first line
	while (data[0] != 'X')  //Process machine code until an 'X' is encountered
	{
		opBin = data.substr(0, 8);  //Get binary information for deCode
		operandBin = data.substr(8, 15);  //Get binary information for operand

		pStorage[opLocation][0] = BinToDec(opBin, 8);  //Convert deCode from binary to decimal
		pStorage[opLocation][1] = BinToDec(operandBin, 8);  //Convert operand from binary to decimal

		dataOUT << data << endl; //Print binary number
		opLocation++;  //Increment location
		dataIN >> ws >> data;  //Read white space and next line
	}
	dataOUT << data << endl;  //Print end of Machine Language code data

	for (int i = 0; i < 50; i++)  //Read numerical data
	{
		dataIN >> ws;  //Read white space
		dataIN >> data;  //Read more data

		pStorage[50 + i][0] = BinToDec(data, 16);  //Convert number and store it to primary storage

		dataOUT << data; //Print binary number
		dataOUT << endl;
	}
}
//*****************************************************************************************************
void printRegisters(ofstream&dataOUT, int MIR, int TMPR1, int TMPR2, int SDR1,
	int SDR2, int CSIAR, int ACC1, int ACC2, int PSIAR, int SAR) {
		// Receives – The output file and each of the registers
		// Task - Print contents of each register
		// Returns - Nothing
		//Print content of each register
	dataOUT << "MIR: " << DecToHex(MIR, 2) << "  |  TMPR1: " << DecToHex(TMPR1, 2)
		<< "  |  TMPR2: " << DecToHex(TMPR2, 2) << "  |  SDR1: " << DecToHex(SDR1, 2)
	    << "  |  SDR2: " << DecToHex(SDR2, 2) << endl << endl;


	dataOUT << "CSIAR: " << DecToHex(CSIAR, 2) <<"  |  ACC1: "<< DecToHex(ACC1, 2)
		<< "  |  ACC2: " << DecToHex(ACC2, 2) <<"  |  PSIAR: " << DecToHex(PSIAR, 2)
		<<"  |  SAR: " << DecToHex(SAR, 2) << endl;
	
}
//*****************************************************************************************************
void printPrimaryMemory(ofstream&dataOUT, int pStorage[256][2]) {
		// Receives – The output file and primary storage
		// Task - Print contents of each register
		// Returns - Nothing
	for (int i = 0; i < 256; i++)  //Print contents of primary memory
	{
		if (i < 50) {  //Convert machine language codes to hex
			dataOUT << DecToHex(pStorage[i][0], 2) << DecToHex(pStorage[i][1], 2);
		}
		else {  //Convert numerical data to hex
			dataOUT << DecToHex(pStorage[i][0], 4);
		}			
		dataOUT << " "; // Print a space between each hexidecimal number
		if ((i + 1) % 8 == 0)  //Print 8 blocks on each line
			dataOUT << endl;		
	}
}
//*****************************************************************************************************
void processData(int& MIR, int& TMPR1, int& TMPR2, int&  SDR1, int& SDR2, int&  CSIAR,
	int& ACC1, int& ACC2, int&  PSIAR, int&  SAR, int pStorage[256][2]) {
		// Receives – Each of the registers and the primary storage
		// Task - Process all of the data from Primary Storage
		// Returns - Nothing
	int opCode = 0;  //Initialize opCode to 0
	bool halt = false;  //Initialize halt to false

	while (!halt)  //Process instructions until microcode for 'halt' is encountered
	{
		if (MIR % 10 == 0 && MIR != 0)
			machineCounter++; //Add one to machine operation counter if new instruction
		MIR = CSIAR;

		opCode = GetOpCode(MIR);  //Get the opCode

								  //Use list of all microcode instructions according to the opcode
								  //Increment CSIAR after each operation
		switch (opCode)
		{
		case 1:
			//Set SDR to ACC
			SDR1 = ACC1;
			SDR2 = ACC2;
			CSIAR++;
			break;
		case 5:
			//Set PSIAR to last eight bits of SDR
			PSIAR = SDR2;
			CSIAR++;
			break;
		case 6:
			//Set TEMP to SDR
			TMPR1 = SDR1;
			TMPR2 = SDR2;
			CSIAR++;
			break;
		case 8:
			//Set SAR to PSIAR
			SAR = PSIAR;
			CSIAR++;
			break;
		case 9:
			//Set SAR to last eight bits of TMPR
			SAR = TMPR2;
			CSIAR++;
			break;
		case 12:
			//Increment ACC by TEMP
			ACC1 += TMPR1;
			ACC2 += TMPR2;
			CSIAR++;
			break;
		case 15:
			//Decrement ACC by TEMP
			ACC1 -= TMPR1;
			ACC2 -= TMPR2;
			CSIAR++;
			break;
		case 18:
			//Set ACC values to TEMP values
			ACC1 = TMPR1;
			ACC2 = TMPR2;
			CSIAR++;
			break;
		case 20:
			//Set PSIAR to last eight bits of ACC
			PSIAR = ACC2;
			CSIAR++;
			break;
		case 21:
			//Set TMPR values to ACC values
			TMPR1 = ACC1;
			TMPR2 = ACC2;
			CSIAR++;
			break;
		case 23:
			//Set last eight bits of ACC to PSIAR plus 1
			ACC2 = PSIAR + 1;
			CSIAR++;
			break;
		case 25:
			//Set SDR values to values at primary memory location SAR
			SDR1 = pStorage[SAR][0];
			SDR2 = pStorage[SAR][1];
			CSIAR++;
			break;
		case 26:
			//Set values at primary memory location SAR to SDR
			pStorage[SAR][0] = SDR1;
			pStorage[SAR][1] = SDR2;
			CSIAR++;
			break;
		case 28:			
			CSIAR = SDR1 * 10; //Set decoded SDR into CSIAR
			break;
		case 29:
			//Set CSIAR to 0
			CSIAR = 0;
			break;
		case 30:
			//If both ACC values are 0, increment CSIAR and stop execution
			if (ACC1 == 0 && ACC2 == 0)
			{
				CSIAR++;
				halt = true;
			}
			else
				CSIAR++; //increment CSIAR
			break;
		}
			
		microCounter += 3; //Increment microcode counter
	}
}
//*****************************************************************************************************
int main() {
		// Receives – Nothing
		// Task - Call each necessary function of the program in order
		// Returns - Nothing
		// Declare and initialize variables for each register.	 
	int MIR = NULL, CSIAR = 0, PSIAR = 0, SAR = NULL, SDR1 = NULL, SDR2 = NULL;
	int TMPR1 = 0, TMPR2 = 0, ACC1 = 0, ACC2 = 0;

	int pStorage[256][2];  //Initialize primary storage as two dimmensional array of integers

	for (int first = 0; first < 256; first++) {  //Set all contents of primary storage to NULL
		for (int second = 0; second < 2; second++) {
			pStorage[first][second] = NULL;
		}
	}	
	int nullNumber = 255; //Initialize nullNumber (all "ones" converted to decimal)
	int decoded = 0;  //Initialize decoded instruction
	
	ifstream dataIN;
	ofstream dataOUT;
	dataIN.open("Data_its.txt"); // Open the file containing data.
	dataOUT.open("dataOUT.doc"); // Create and open the file to write data to.		
	Header(dataOUT); // Print data header.

		// Print data label for input data read
	printDataLabel(dataOUT, "ECHO Print Input Data");
		// Read all data in from input file
	getData(dataIN, dataOUT, pStorage);	
		// Print data label for primary memory before any processing has taken place
	printDataLabel(dataOUT, "Primary Memory (Before Processing)");
	printPrimaryMemory(dataOUT,pStorage); // Print the primary memory	
		// Print data label for contents of each register before execution
	printDataLabel(dataOUT, "Contents of Registers (Before Processing)");
		// Print the contents of each register
	printRegisters(dataOUT, MIR, TMPR1, TMPR2, SDR1, SDR2, CSIAR, ACC1, ACC2, PSIAR, SAR);
		// Process all of the data from the primary storage using each register
	processData(MIR, TMPR1, TMPR2, SDR1, SDR2, CSIAR, ACC1, ACC2, PSIAR, SAR, pStorage);	
		// Print data label for primary memory after processing
	printDataLabel(dataOUT, "Primary Memory (After Processing)");
	printPrimaryMemory(dataOUT, pStorage); // Print the primary memory	
		// Print data label for contents of each register after processing
	printDataLabel(dataOUT, "Contents of Registers (After Processing)");
		//Print the contents of each register
	printRegisters(dataOUT, MIR, TMPR1, TMPR2, SDR1, SDR2, CSIAR, ACC1, ACC2, PSIAR, SAR);
		// Print data label for instruction counts
	printDataLabel(dataOUT, "Counts of Instructions Performed");
	dataOUT << "Microcode instruction count: " << microCounter << endl;
	dataOUT << "Machine language instruction count: " << machineCounter << endl;

	Footer(dataOUT); // Print footer. 
	dataIN.close(); // Close input data file. 
	dataOUT.close(); // Close output data file.
	return 0;
}