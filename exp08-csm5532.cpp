/*
Author:		Cole Meyers - csm5532
Class:		CMPSC 121
Lab:		8
File:		lab8-csm5532.cpp
Purpose:	random numbers

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
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

double pOut = .580, pBB = 0.097, p1B = .220, p2B = .061, p3B = .025, pHR = .017;

int main()
{
	stringstream ssAVG;
	string sAVG;
	char cont;
	int AB, nOut = 0, n1B = 0, n2B = 0, n3B = 0, nHR = 0;
	double AVG, nHits = 0, nAB = 0, nBB = 0;
	
	srand(time(NULL));
	
	do
	{
		cout << "Simulating 1000 ABs...\n";
		
		for (nAB; nAB < 1000; nAB++)
		{
			AB = rand() % 1000;

			if (AB >= 0 && AB <= 579)
				nOut++;
			else if (AB >= 580 && AB <= 676)
				nBB++;
			else if (AB >= 677 && AB <= 896)
			{
				n1B++;
				nHits++;
			}
			else if (AB >= 897 && AB <= 957)
			{
				n2B++;
				nHits++;
			}
			else if (AB >= 958 && AB <= 982)
			{
				n3B++;
				nHits++;
			}
			else
			{
				nHR++;
				nHits++;
			}
		}
		
		AVG = nHits / (nAB - nBB);
		AVG = round(1000 * AVG);
		ssAVG << AVG;
		sAVG = ssAVG.str();
		ssAVG.str("");
		
		cout << "Casey's batting statistics:\n" <<
			"AB:\t" << nAB << endl <<
			"AVG:\t" << "." << sAVG << endl <<
			"OUT:\t" << nOut << endl <<
			"BB:\t" << setprecision(0) << nBB << endl <<
			"1B:\t" << n1B << endl <<
			"2B:\t" << n2B << endl <<
			"3B:\t" << n3B << endl <<
			"HR:\t" << nHR << endl <<
			"Do you wish to continue? (Y / N)\n";
		cin >> cont;
	} while (cont == 'Y' || cont == 'y');

	return 0;
}

/* Sample Execution:
Simulating 1000 ABs...
Casey's batting statistics:
AB:     1000
AVG:    .344
OUT:    594
BB:     94
1B:     203
2B:     56
3B:     32
HR:     21
Do you wish to continue? (Y / N)

Simulating 1000 ABs...
Casey's batting statistics:
AB:     1000
AVG:    .334
OUT:    603
BB:     95
1B:     200
2B:     59
3B:     27
HR:     16
Do you wish to continue? (Y / N)
*/