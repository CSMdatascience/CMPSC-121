/*
Author:		Cole Meyers - csm5532
Class:		CMPSC 121
Experiment:	04
File:		lab04-csm5532.cpp
Purpose:	selection logic

I certify that this program code is my work. Others may have assisted me with
planning and concepts, but the code was written solely by me.

I understand that submitting code which is totally or partially the product of
other individuals is a violation of the Academic Integrity Policy and accepted
ethical precepts. Falsified execution results are also results of improper
activities. Such violations may results in zero credit for the assignment,
reduced credit for the assignment, or course failure.
*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <sstream>
using namespace std;

char v;
int t;
int main()
{
	cout << "Enter type of vehicle (C, T, or B) and time parked in hours.\n";
	cin >> v >> t;
	double rate, due;
	if (v == 'C' || v == 'c' && t <= 2) {
		rate = 1.25;
		due = rate * t;
	}
	else if (v == 'C' || v == 'c' && t > 2) {
		rate = 1.5;
		due = (1.25 * 2) + (rate * (t - 2));
	}
	else if (v == 'T' || v == 't' && t <= 2) {
		rate = 2.75;
		due = rate * t;
	}
	else if (v == 'T' || v == 't' && t > 2) {
		rate = 3.75;
		due = (2.75 * 2) + (rate * (t - 2));
	}
	else if (v == 'B' || v == 'b' && t <= 1) {
		rate = 9.5;
		due = rate * t;
	}
	else if (v == 'B' || v == 'b' && t > 1) {
		rate = 6.75;
		due = (9.5 * 1) + (rate * (t - 2));
	}
	else {
		cout << "Invalid vehicle type.\n";
		return 0;
	}
	string vehicle;
	if (v == 'C' || v == 'c') {
		vehicle = "Car";
	}
	else if (v == 'T' || v == 't') {
		vehicle = "Truck";
	}
	else if (v == 'B' || v == 'b') {
		vehicle = "Bus";
	}
	cout << "Crunchum Parking Lots, Inc.\n"
		<< "\"We usually find your vehicle!\"\n"
		<< "=============================\n"
		<< "Vehicle Type:\t" << vehicle << endl
		<< "Time:\t\t" << t << " Hours\n"
		<< "Amount Due:\t$" << fixed << setprecision(2) << due << endl
		<< "=============================\n";
return		0;
}

/* Sample execution:
Enter type of vehicle (C, T, or B) and time parked in hours.
C 7
Crunchum Parking Lots, Inc.
"We usually find your vehicle!"
=============================
Vehicle Type:   Car
Time:           7 Hours
Amount Due:     $8.75
=============================
Press any key to continue . . .

Enter type of vehicle (C, T, or B) and time parked in hours.
t 10
Crunchum Parking Lots, Inc.
"We usually find your vehicle!"
=============================
Vehicle Type:   Truck
Time:           10 Hours
Amount Due:     $35.50
=============================
Press any key to continue . . .

Enter type of vehicle (C, T, or B) and time parked in hours.
b 8
Crunchum Parking Lots, Inc.
"We usually find your vehicle!"
=============================
Vehicle Type:   Bus
Time:           8 Hours
Amount Due:     $50.00
=============================
Press any key to continue . . .

Enter type of vehicle (C, T, or B) and time parked in hours.
B 72
Crunchum Parking Lots, Inc.
"We usually find your vehicle!"
=============================
Vehicle Type:   Bus
Time:           72 Hours
Amount Due:     $684.00
=============================
Press any key to continue . . .

Enter type of vehicle (C, T, or B) and time parked in hours.
z 5
Invalid vehicle type.
Press any key to continue . . .
*/