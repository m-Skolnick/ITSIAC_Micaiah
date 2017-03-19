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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
	// Initialize global variables of microcode and machine language counters
int microCounter = 0, machineCounter = 0;
//*************************************  FUNCTION HEADER  *********************************************
void Header(ofstream &Outfile){      
		// Receives – the output file
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
void Footer(ofstream &Outfile){
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
		// Receives - The input file, and the desired label to be printed
		// Task - Print the data label passed in
		// Returns - Nothing
	dataOUT << "-----------------------------------------------------------------------" << endl;
	dataOUT << endl << label << endl;
	dataOUT << "-----------------------------------------------------------------------" << endl;
}
//*****************************************************************************************************
int GetOpCode(int MIR){
		// Receives - The contents of the MIR as an integer
		// Task - Find the corresponding op code to the MIR integer
		// Returns - The op code which corresponded to the MIR integer
	int opCode;  //Initialize opCode to return as answer
	switch (MIR){ // Find op code which corresponds to MIR
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
	return opCode; // Return the op code which corresponded to the MIR
}
//*****************************************************************************************************
string DecToHex(int decimal, int digits) {
	// Receives - A decimal number and the number of digits
	// Task - Convert the number from decimal to hexadecimal
	// Returns - The converted number in hexadecimal format as a string

	string hex;
	char buffer[33];
	_itoa_s(decimal, buffer, 16);

	hex = string(buffer);

	if (digits = 2) {
		if (hex == "0") {
			hex = "FF";
		}
	}
	else {
		if (hex == "0") {
			hex = "FFFF";
		}
	}
	

	return hex;
}
string DecToHex2(int decimal, int digits){
		// Receives - A decimal number and the number of digits
		// Task - Convert the number from decimal to hexadecimal
		// Returns - The converted number in hexadecimal format as a string
	bool positive = true;
	if (decimal < 0){  // If the number is negative, switch it to positive
		positive = false;
		decimal = -decimal;
	}
	if (digits == 2){  // If the number is 2 digits long
		int temp[2] = { 0,0 }; //Initialize temporary array
		char converted[3];  //Initialize converted number character string
		if (decimal == 0 || decimal == -1){  //If the number is zero or -1, set array to 15 (FF)
			temp[0] = 15;
			temp[1] = 15;
		}
		else if (decimal > 16){  //If number is bigger than 16, convert to hexadecimal
			temp[0] = (decimal / 16);
			decimal = decimal % 16;
			temp[1] = decimal;
		}
		else if (decimal < 16){ //If number is smaller than 16, hexadecimal is the same as decimal
			temp[1] = decimal;
		}
		if (!positive){  //If the decimal was negative, get the compliment
			temp[0] = abs((temp[0] - 15));
			temp[1] = abs((temp[1] - 16));
		}
		for (int j = 0; j < 2; j++){  //Store the converted number in its hexadecimal character form
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
		return hex; //Return the converted number as a string in hexadecimal format
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

		if (!positive)  //If the number is negative, get compliment
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
		return hex; //Return the number in hexadecimal format
	}
}
//*****************************************************************************************************
string findCompliment(string binary,int bits) {
		// Receives - A binary number in string format
		// Task - Find the compliment of the binary number
		// Returns - The compliment of the binary number
	int count = 0;
	for (int i = bits-1; i >= 0; i--) { //Cycle through each bit of the binary number
		if (count > 0) {
			if (binary[i] == '1') { //Switch from '1' to '0'
				binary[i] = '0';
			}
			else //Switch from '0' to '1'
				binary[i] = '1';
		}
		if (binary[i] == '1')
			count++;
	}
	return binary;
}
//*****************************************************************************************************
int BinToDec(string binary, int bits){
		// Receives - A binary number in string format, the number of bits in the number
		// Task - Convert the string from binary to decimal format
		// Returns - The number in decimal format as an integer
	int power, decNum = 0;  //Initialize integers to hold the power and converted number
	bool positive; //Intialize bool to hold whether the number is positive or negative
	if (binary[0] == '0'){  //If leftmost bit is 0, indicate number is positive
			positive = true;
		}
	else{  //Otherwise indicate number is negative and find compliment
		positive = false;
		binary = findCompliment(binary,bits); //Find the compliment of the negative number		
	}
	power = bits - 1;
	for (int i = 0; i < bits; i++){ //Cycle through the number converting from bin to decimal
		if (binary[i] == '1') {  //If a '1' is encountered, calculate and add to number
			decNum += (int)pow(2, power);
		}
		power--;  //Decrement power
	}
	if (!positive) {//If number was negative, multiply by "-1" to return back to negative
		decNum *= -1;
	}
	return decNum;  //return the converted number in decimal format
}
//*****************************************************************************************************
void getData(ifstream&dataIN, ofstream&dataOUT, int pStorage[256][2]) {
		// Receives - The input file, the output file, and the primary storage
		// Task - Read in each line from the input file to primary storage
		// Returns - Primary storage full of data from input file
	string data, opBin, operandBin; //Initialize bin numbers and data strings
	int opLocation = 0;  //Initialize control variable for the opLocation in memory
	dataIN >> ws >> data;  //Read white space and first line
	while (data[0] != 'X'){  //Process machine code until an 'X' is encountered
		opBin = data.substr(0, 8);  //Get binary information for deCode
		operandBin = data.substr(8, 15);  //Get binary information for operand
		pStorage[opLocation][0] = BinToDec(opBin, 8);  //Convert deCode from binary to decimal
		pStorage[opLocation][1] = BinToDec(operandBin, 8);  //Convert operand from binary to decimal
		dataOUT << data << endl; //Print binary number
		opLocation++;  //Increment location
		dataIN >> ws >> data;  //Read white space and next line
	}
	dataOUT << data << endl;  //Print the last line of machine language code
	  //Read all 50 lines of numerical data
	for (int i = 50; i < 100; i++){  
		dataIN >> ws >> data;  //Get the next line
		dataOUT << data << endl; //Print the binary number just read in
		pStorage[i][0] = BinToDec(data, 16);  //Convert number and store it to primary storage
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
	for (int i = 0; i < 256; i++){  //Print contents of primary memory
		if (i < 50) {  //Print machine language codes in hexadecimal format
			dataOUT << DecToHex(pStorage[i][0], 2) << DecToHex(pStorage[i][1], 2);
		}
		else {  //Print numerical data in hexadecimal format
			dataOUT << DecToHex(pStorage[i][0], 4);
		}			
		dataOUT << " "; // Print a space between each hexidecimal number
		if ((i + 1) % 8 == 0)  //End the line after every 8, so 8 blocks are on each line
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
	while (!halt){  //Process data from primary storage until "halt" is encountered
			//When a new instruction is started, increment the machine counter
		if (MIR % 10 == 0 && MIR != 0) {
			machineCounter++;
		}
		MIR = CSIAR; //Set the CSIAR to the address of the microcode instruction
		opCode = GetOpCode(MIR);  //Get the opCode corresponding to the microcode
			//Perform operations based on the opcode
		switch (opCode)	{
		case 1:	//Set SDR to ACC
			SDR1 = ACC1;
			SDR2 = ACC2;
			CSIAR++;
			microCounter++; //Increment microcode counter if 3 instructions are performed
							//At bottom of switch statment increment microcounter by 2 more
			break;
		case 2:	//Set last 8 bits of SDR to PSIAR
			SDR2 = PSIAR;
			CSIAR++;
			break;
		case 3:	//Set SDR to TMPR
			SDR1 = TMPR1;
			SDR2 = TMPR2;
			CSIAR++;
			microCounter++;
			break;
		case 4:	//Set ACC to SDR
			ACC1 = SDR1;
			ACC2 = SDR2;
			CSIAR++;
			microCounter++;
			break;
		case 5:	//Set PSIAR to last eight bits of SDR
			PSIAR = SDR2;
			CSIAR++;
			break;
		case 6:	//Set TEMP to SDR
			TMPR1 = SDR1;
			TMPR2 = SDR2;
			CSIAR++;
			microCounter++;
			break;
		case 7:	//Set SAR to ACC
			SAR = ACC2;
			CSIAR++;
			break;
		case 8:	//Set SAR to PSIAR
			SAR = PSIAR;
			CSIAR++;
			break;
		case 9:	//Set SAR to last eight bits of TMPR
			SAR = TMPR2;
			CSIAR++;
			break;
		case 12: //Increment ACC by TEMP
			ACC1 += TMPR1;
			ACC2 += TMPR2;
			CSIAR++;
			microCounter++;
			break;
		case 15://Decrement ACC by TEMP
			ACC1 -= TMPR1;
			ACC2 -= TMPR2;
			CSIAR++;
			microCounter++;
			break;
		case 18://Set ACC values to TEMP values
			ACC1 = TMPR1;
			ACC2 = TMPR2;
			CSIAR++;
			microCounter++;
			break;
		case 20: //Set PSIAR to last eight bits of ACC
			PSIAR = ACC2;
			CSIAR++;
			break;
		case 21://Set TMPR values to ACC values
			TMPR1 = ACC1;
			TMPR2 = ACC2;
			CSIAR++;
			microCounter++;
			break;
		case 22://Set last eight bits of ACC to ACC plus 1
			ACC2 = ACC2 + 1;
			CSIAR++;
			break;
		case 23://Set last eight bits of ACC to PSIAR plus 1
			ACC2 = PSIAR + 1;
			CSIAR++;
			break;
		case 25://Set SDR to primary memory location SAR
			SDR1 = pStorage[SAR][0];
			SDR2 = pStorage[SAR][1];
			CSIAR++;
			microCounter++;
			break;
		case 26://Set values at primary memory location SAR to SDR
			pStorage[SAR][0] = SDR1;
			pStorage[SAR][1] = SDR2;
			CSIAR++;
			microCounter++;
			break;
		case 28://Set decoded SDR to CSIAR
			CSIAR = SDR1 * 10; 
			break;
		case 29://Set CSIAR to 0
			CSIAR = 0;
			break;
		case 30://If ACC = 0, increment CSIAR and halt execution
			if (ACC1 == 0 && ACC2 == 0)	{
				CSIAR++;
				halt = true;
			}
			else { //If ACC is not 0, just increment CSIAR
				CSIAR++;
			}
			break;
		case 31://Halt execution
			halt = true;			
			break;
		case 32://Set MIR to CSIAR
			MIR = CSIAR;
			break;
		}			
		microCounter += 2; //Increment microcode counter by 2
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
	ifstream dataIN("Data_its.txt"); //Open the file containing data.
	ofstream dataOUT("dataOUT.doc"); //Create and open the file to write data to.	
	Header(dataOUT); // Print data header.
		//Print data label for input data read
	printDataLabel(dataOUT, "ECHO Print Input Data");
		//Read all data in from input file
		//Set all contents of primary storage to NULL
	for (int first = 0; first < 256; first++) {
		for (int second = 0; second < 2; second++) {
			pStorage[first][second] = NULL;
		}
	}
		//Read data from input file into primary storage
	getData(dataIN, dataOUT, pStorage);	
		//Print data label for primary memory before any processing has taken place
	printDataLabel(dataOUT, "Primary Memory (Before Processing)");
	printPrimaryMemory(dataOUT,pStorage); // Print the primary memory	
		//Print data label for contents of each register before execution
	printDataLabel(dataOUT, "Contents of Registers (Before Processing)");
		//Print the contents of each register
	printRegisters(dataOUT, MIR, TMPR1, TMPR2, SDR1, SDR2, CSIAR, ACC1, ACC2, PSIAR, SAR);
		//Process all of the data from the primary storage using registers
	processData(MIR, TMPR1, TMPR2, SDR1, SDR2, CSIAR, ACC1, ACC2, PSIAR, SAR, pStorage);	
		//Print data label for primary storage after processing
	printDataLabel(dataOUT, "Primary Memory (After Processing)");
	printPrimaryMemory(dataOUT, pStorage); // Print the primary storage	
		//Print data label for contents of each register after processing
	printDataLabel(dataOUT, "Contents of Registers (After Processing)");
		//Print the contents of each register
	printRegisters(dataOUT, MIR, TMPR1, TMPR2, SDR1, SDR2, CSIAR, ACC1, ACC2, PSIAR, SAR);
		//Print data label for instruction counts
	printDataLabel(dataOUT, "Counts of Instructions Performed");
		//Print each instruction count
	dataOUT << "Microcode instruction count: " << microCounter << endl;
	dataOUT << "Machine language instruction count: " << machineCounter << endl;
	Footer(dataOUT); //Print footer. 
	dataIN.close(); //Close input data file. 
	dataOUT.close(); //Close output data file.
	return 0;
}