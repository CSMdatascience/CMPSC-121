//Author:			Cole Meyers, csm5532, online
//Class:			CMPSC 121
//Experiment:		02
//File:				C:\Users\Cole Meyers\Documents\School\Penn State\CMPSC 121\experiments\lab experiment 2\experiment02\experiment02\exp02-csm5532.cpp
//Purpose:			Division modulo division.
/*
Academic Integrity Affidavit:

I certify that this program code is my work. Others may have 
assisted me with planning and concepts, but the code was written
solely by me.

I understand that submitting code which is totally or partially
the product of other individuals is a violation of the Acadmic
Integrity Policy and accepted ethical precepts. Falsified 
execution results are also results of improper activities. Such 
violations may result in zero credit for the assignment, reduced
credit for the assignment, or course failure.
*/

#include <iostream>

using namespace std;

int main() 
{
	double tendered, cost;
	int change,
		Fifties, Twenties, Tens, Fives, Ones,
		Quarters, Dimes, Nickels, Pennies;
	cout << "Enter amount of purchase and amount tendered: ";
	cin >> cost >> tendered;
	change = (tendered - cost) * 100;
	Fifties = change / 5000;
	change = change % 5000;
	Twenties = change / 2000;
	change = change % 2000;
	Tens = change / 1000;
	change = change % 1000;
	Fives = change / 500;
	change = change % 500;
	Ones = change / 100;
	change = change % 100;
	Quarters = change / 25;
	change = change % 25;
	Dimes = change / 10;
	change = change % 10;
	Nickels = change / 5;
	change = change % 5;
	Pennies = change / 1;
	cout << "For your purchase of " << cost << " you tendered " << tendered << endl;
	cout << "Your change is " << tendered - cost << endl;
	cout << "\tFifties:\t" << Fifties << endl;
	cout << "\tTwenties:\t" << Twenties << endl;
	cout << "\tTens:\t\t" << Tens << endl;
	cout << "\tFives:\t\t" << Fives << endl;
	cout << "\tOnes:\t\t" << Ones << endl;
	cout << "\tQuarters:\t" << Quarters << endl;
	cout << "\tDimes:\t\t" << Dimes << endl;
	cout << "\tNickels:\t" << Nickels << endl;
	cout << "\tPennies:\t" << Pennies << endl;
	return 0;
}