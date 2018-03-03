/*
Author:		Cole Meyers - csm5532
Class:		CMPSC 121
Lab:		9
File:		lab9-csm5532.cpp
Purpose:	calendar days

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
using namespace std;

bool isLeapYear(int year)
{
	if (((year % 400) == 0) ||
		(year % 4) == 0 && (year % 100) != 0)
		return true;
	else
		return false;
	
}

int getCenturyValue(int year)
{
	int century1 = year / 100;
	int century2 = century1 % 4;
	int century3 = (3 - century2) * 2;
	return century3;
}

int getYearValue(int year)
{
	int value1 = year % 100;
	int value2 = (value1 / 4) + value1;
	return value2;
}

int getMonthValue(int month, int year)
{
	bool leap = isLeapYear(year);

	if ((month == 1 || month == 10 && leap == false) ||
		(month == 10 && leap == true))
		return 0;
	else if (month == 5)
		return 1;
	else if ((month == 8 && leap == false) ||
		(month == 2 || month == 8 && leap == true))
		return 2;
	else if ((month == 2 || month == 3 || month == 11 && leap == false) ||
		(month == 3 || month == 11 && leap == true))
		return 3;
	else if (month == 6)
		return 4;
	else if (month == 9 || month == 12)
		return 5;
	else if ((month == 4 || month == 7) ||
		(month == 1 && leap == true))
		return 6;
}

int month, day, year;

int main()
{
	int dowInt;
	string dowStr;
	char ans = 'y';
	bool invalid, leapError;

	cout << "Enter a date in the form month day year, eg 12 23 1992\n";
	cin >> month >> day >> year;

	do
	{
		if ((month > 12) ||
			(month == 2 && day > 29) ||
			(month == 4 || month == 6 || month == 9 || month == 11 && day > 30) ||
			(day > 31))
		{
			invalid = true;
			leapError = false;
			cout << "Invalid input. Please enter a different date.\n";
			cin >> month >> day >> year;
		}
		else if (month == 2 && day == 29 && isLeapYear(year) == false)
		{
			invalid = false;
			leapError = true;
			cout << year << " is not a leap year. Please enter a different date.\n";
			cin >> month >> day >> year;
		}
		else
		{
			invalid = false;
			leapError = false;
			break;
		}
	} while (invalid == true || leapError == true);

	do
	{
		dowInt = (day + getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year)) % 7;

		if (dowInt == 0)
			dowStr = "Sunday";
		else if (dowInt == 1)
			dowStr = "Monday";
		else if (dowInt == 2)
			dowStr = "Tuesday";
		else if (dowInt == 3)
			dowStr = "Wednesday";
		else if (dowInt == 4)
			dowStr = "Thursday";
		else if (dowInt == 5)
			dowStr = "Friday";
		else
			dowStr = "Saturday";

		cout << month << "/" << day << "/" << year << " is a " << dowStr << endl << endl <<
			"Do you wish to enter another date? (Y / N)\n";
		cin >> ans;

		if (ans == 'Y' || ans == 'y')
		{
			cout << "Enter a date in the form month day year, eg 12 23 1992\n";
			cin >> month >> day >> year;
		}
		else
			break;
	} while (ans == 'Y' || ans == 'y');
	
	return 0;
}

/* Sample execution:
ERROR CHECKING:
Enter a date in the form month day year, eg 12 23 1992
2 29 2017
2017 is not a leap year. Please enter a different date.
13 1 2017
Invalid input. Please enter a different date.
2 30 2017
Invalid input. Please enter a different date.
4 31 2017
Invalid input. Please enter a different date.
12 32 2017
Invalid input. Please enter a different date.

SAMPLE EACH DAY OF WEEK:
Enter a date in the form month day year, eg 12 23 1992
10 29 2017
10/29/2017 is a Sunday

Do you wish to enter another date? (Y / N)
y
Enter a date in the form month day year, eg 12 23 1992
10 30 2017
10/30/2017 is a Monday

Do you wish to enter another date? (Y / N)
y
Enter a date in the form month day year, eg 12 23 1992
10 31 2017
10/31/2017 is a Tuesday

Do you wish to enter another date? (Y / N)
y
Enter a date in the form month day year, eg 12 23 1992
11 1 2017
11/1/2017 is a Wednesday

Do you wish to enter another date? (Y / N)
y
Enter a date in the form month day year, eg 12 23 1992
11 2 2017
11/2/2017 is a Thursday

Do you wish to enter another date? (Y / N)
y
Enter a date in the form month day year, eg 12 23 1992
11 3 2017
11/3/2017 is a Friday

Do you wish to enter another date? (Y / N)
y
Enter a date in the form month day year, eg 12 23 1992
11 4 2017
11/4/2017 is a Saturday

Do you wish to enter another date? (Y / N)
n
Press any key to continue . . .

*/