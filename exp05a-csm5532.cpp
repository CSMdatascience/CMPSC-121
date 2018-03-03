/*
Author:		Cole Meyers - csm5532
Class:		CMPSC 121
Lab:		05
File:		lab05-csm5532.cpp
Purpose:	Selection logic and debugging

I certify that this program code is my work. Others may have assisted me with
planning and concepts, but the code was written solely by me.

I understand that submitting code which is totally or partially the product of
other individuals is a violation of the Academic Integrity Policy and accepted
ethical precepts. Falsified execution results are also results of improper
activities. Such violations may results in zero credit for the assignment,
reduced credit for the assignment, or course failure.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int LT20 = 20;
const double LT20Charge = 0.10;
const int LT40 = 20;
const double LT40Charge = 0.08;
const int LT60 = 60;
const double LT60Charge = 0.06;
const double GTE60Charge = 0.04;
const double BALANCELIMIT = 400.00;
const double LOWBALANCECHARGE = 15.00;
int main()
{
	int numberOfChecks;
	bool isUnder = false;
	double balance, serviceFee = 0, checkCharge;
	cout << fixed << setprecision(2);
	cout << "Please enter beginning balance and number of checks written" << endl;
	cin >> balance >> numberOfChecks;
	if (balance < BALANCELIMIT)
	{
		serviceFee += LOWBALANCECHARGE;
		isUnder = true;
	}

	if (numberOfChecks < LT20)
		serviceFee += (LT20Charge * numberOfChecks);
	else if (numberOfChecks < LT40)
		serviceFee += (LT40Charge * numberOfChecks);
	else if (numberOfChecks < LT60)
		serviceFee += (LT60Charge * numberOfChecks);
	else
		serviceFee += (GTE60Charge * numberOfChecks);

	cout << "MEGABUX Bancorp" << endl;
	cout << "Your balance was " << balance << endl;
	if (isUnder)
	{
		cout << "You did not maintain the minimum balance!" << endl;
			cout << "You incurred a fee of $" << LOWBALANCECHARGE
			<< endl;
	}
	cout << "Total service Charge = $" << serviceFee << endl;

	return 0;
}
