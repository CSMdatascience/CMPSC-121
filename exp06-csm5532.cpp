/*
Author:		Cole Meyers - csm5532
Class:		CMPSC 121
Lab:		6
File:		lab6-csm5532.cpp
Purpose:	sales of a commodity

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
using namespace std;

int units = 0, t = 0;
double price = -1, tTotal, 
unitsAvg, unitsTotal = 0, 
rev, revTotal = 0, revAvg, 
largest = 0, smallest = 2147483647;

int main()
{
	cout << "Enter transactions -99 0 to stop\n";
	while (units != -99 && price != 0)
	{
		t++;
		cout << "Transaction # " << t << ": ";
		cin >> units >> price;
		unitsTotal += units;
		revTotal += units * price;
		rev = units * price;
		if (rev > largest)
			largest = rev;
		if (rev < smallest && rev != -0)
			smallest = rev;
	}

	tTotal = t - 1;
	unitsTotal = unitsTotal + 99;
	unitsAvg = unitsTotal / tTotal;
	revAvg = revTotal / tTotal;
	
	cout << "TRANSACTION PROCESSING REPORT\n" <<
		"Transactions processed:\t\t" << tTotal << endl <<
		"Units sold:\t\t\t" << unitsTotal << endl;
	cout << fixed << setprecision(2);
	cout <<	"Average units per order:\t" << unitsAvg << endl <<
		"Largest transaction:\t\t" << largest << endl <<	
		"Smallest transaction:\t\t" << smallest << endl <<
		"Total revenue:\t\t$\t" << revTotal << endl <<
		"Average revenue:\t$\t" << revAvg << endl;

	return 0;
}

/* Sample execution:
Enter transactions -99 0 to stop
Transaction # 1: 30 9.75
Transaction # 2: 22 8.50
Transaction # 3: 15 7.95
Transaction # 4: 12 9.00
Transaction # 5: 16 8.55
Transaction # 6: 36 7.99
Transaction # 7: 100 10.75
Transaction # 8: 43 9.99
Transaction # 9: 14 6.95
Transaction # 10: 13 8.98
Transaction # 11: -99 0
TRANSACTION PROCESSING REPORT
Transactions processed:         10
Units sold:                     301
Average units per order:        30.10
Largest transaction:            1075.00
Smallest transaction:           97.30
Total revenue:          $       2849.80
Average revenue:        $       284.98
Press any key to continue . . .
*/