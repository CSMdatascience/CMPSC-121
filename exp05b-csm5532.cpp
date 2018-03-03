/*
Author:		Cole Meyers - csm5532
Class:		CMPSC 121
Lab:		05
File:		lab05-csm5532.cpp
Purpose:	Selection logic and debugging - Zippy Cell Phone Co.

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
#include <stdio.h>
#include <ctype.h>

using namespace std;

const double	standardFee = 12, premierFee = 25,
standardRate = 0.20, premierRateD = 0.10, premierRateN = 0.050;
double amountDue = 0, dayAmount, nightAmount;

int main()
{
	string account, serviceType;
	char code;
	int mins, dayMins, nightMins;
	cout << "Enter account number and service code (S or P)." << endl;
	cin >> account >> code;
	code = tolower(code);
	cout << fixed << setprecision(2);
	
	while (code != 's' && code != 'p')
	{
		cout << "Invalid service code. Please enter S or P." << endl;
		cin >> code;
		code = tolower(code);
	}

	if (code == 's')
	{
		serviceType = "STANDARD";
		cout << "Enter minutes." << endl;
		cin >> mins;

		if (mins <= 60)
			amountDue += standardFee;
		else
			amountDue += standardFee + (mins - 60) * standardRate;

		cout << "---------Zippy Cell Phone Company---------" << endl <<
			"Service type:\t" << serviceType << endl <<
			"Minutes:\t" << mins << endl <<
			"Amount due:\t" << amountDue << endl;

		return 0;
	}
	else
	{
		serviceType = "PREMIER";
		cout << "Enter daytime minutes and nighttime minutes" << endl;
		cin >> dayMins >> nightMins;

		if (dayMins <= 75)
			dayAmount = 0;
		else
			dayAmount = premierRateD * (dayMins - 75);

		if (nightMins <= 100)
			nightAmount = 0;
		else
			nightAmount = premierRateN * (nightMins - 100);

		amountDue = premierFee + dayAmount + nightAmount;

		cout << "---------Zippy Cell Phone Company---------" << endl <<
			"Service type:\t\t" << serviceType << endl <<
			"Daytime minutes:\t" << dayMins << endl <<
			"Nighttime minutes:\t" << nightMins << endl <<
			"Amount due:\t\t$" << amountDue << endl;
		
		return 0;
	}
}

/* Sample executoin:
Enter account number and service code (S or P).
dfa f
Invalid service code. Please enter S or P.
p
Enter daytime minutes and nighttime minutes
85 110
---------Zippy Cell Phone Company---------
Service type:           PREMIER
Daytime minutes:        85
Nighttime minutes:      110
Amount due:             $26.50
Press any key to continue . . .

Enter account number and service code (S or P).
dfa s
Enter minutes.
65
---------Zippy Cell Phone Company---------
Service type:   STANDARD
Minutes:        65
Amount due:     13.00
Press any key to continue . . .

Enter account number and service code (S or P).
dfa P
Enter daytime minutes and nighttime minutes
85 110
---------Zippy Cell Phone Company---------
Service type:           PREMIER
Daytime minutes:        85
Nighttime minutes:      110
Amount due:             $26.50
Press any key to continue . . .

Enter account number and service code (S or P).
dfa S
Enter minutes.
65
---------Zippy Cell Phone Company---------
Service type:   STANDARD
Minutes:        65
Amount due:     13.00
Press any key to continue . . .
*/