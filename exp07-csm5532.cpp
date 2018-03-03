/*
Author:		Cole Meyers - csm5532
Class:		CMPSC 121
Lab:		7
File:		lab7-csm532.cpp	
Purpose:	fleet input

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
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	ifstream fleet;
	fleet.open("C:\\Users\\Cole Meyers\\Documents\\School\\Penn State\\CMPSC 121\\labs\\lab7-csm5532\\FleetInput.txt");

	string vehicleID, bestMPGVehicle, worstMPGVehicle, mpgS;
	stringstream mpgSS;
	double miles, gallons, mpg = 0, nMiles = 0, nGallons = 0,  
		bestMPG = 0, worstMPG = 2147483647, avgMPG;
	int nVehicles = 0;

	
	if (fleet.fail())		//if file fails to open, display error and kill program
	{
		cout << "Error opening file.\n";
		return 0;
	}
		
	else
	{
		cout << "AMSCO Fleet Report\n" <<		//display header
			"Vehicle ID      Miles   Gallons    MPG\n" <<
			"----------------------------------------------------------------\n";
		while (fleet >> vehicleID >> miles >> gallons)	//read items from a line in file
		{
			nVehicles++;			//"Count:" ; number of lines in file
			nMiles += miles;		//"Total Miles:" ; sum of "Miles" column
			nGallons += gallons;	//total number of gallons used to calculate "Average MPG:"

			mpg = miles / gallons;
			if (mpg > bestMPG)		//find vehicle with best MPG
			{
				bestMPG = mpg;
				bestMPGVehicle = vehicleID;
			}

			if (mpg < worstMPG)		//find vehicle with worst MPG
			{
				worstMPG = mpg;
				worstMPGVehicle = vehicleID;
			}
			
			cout << vehicleID << "   	" << miles << "     " << setw(4) << gallons << "     ";
							
			mpgSS << mpg;			//places mpg in stringstream
			mpgS = mpgSS.str();		//creates string from stringstream
			mpgSS.str("");			//IMPORTANT: empties stringstream fpr next iteration
			
			if (mpgS.length() <= 4)
				cout << mpgS << endl;
			else
			{
				mpgS = mpgS.substr(0, 4);
				cout << mpgS << "...\n";
			}
					
		}
		avgMPG = nMiles / nGallons;

		cout << fixed << setprecision(1);
		cout << "----------------------------------------------------------------\n" <<
			"Count:\t\t" << nVehicles << endl <<
			"Total Miles:\t" << nMiles << endl <<
			"Average MPG:\t" << avgMPG << endl <<
			"Vehicle ID with Best MPG:\t" << bestMPGVehicle << "\t" << bestMPG << endl <<
			"Vehicle ID with Worst MPG:\t" << worstMPGVehicle << "\t" << worstMPG << endl;
	}
	return 0;
}

/* Sample execution:
AMSCO Fleet Report
Vehicle ID      Miles   Gallons    MPG
----------------------------------------------------------------
279BX6KY2Z      582.2     20.5     28.4
802MX8BZ4Q      723.6     25.1     28.8...
671AY6DZ3N      756.9     27.5     27.5...
845DH6AJ3B      660.2     25.4     25.9...
566GJ6KV2U      510.2     30.8     16.5...
109QW2RP2Y      301.2      8.3     36.2...
135TR4YC6H      387.6     12.2     31.7...
122AC6UG7P      228.9     14.7     15.5...
136VW8TD2Z      331.2     19.1     17.3...
448WQ2DX1M      543.9     33.6     16.1...
721GZ1LJ5N      629.8     27.9     22.5...
779FS3MB4Y      651.2     28.4     22.9...
553SB5LK8O      444.4     26.8     16.5...
----------------------------------------------------------------
Count:          13
Total Miles:    6751.3
Average MPG:    22.5
Vehicle ID with Best MPG:       109QW2RP2Y      36.3
Vehicle ID with Worst MPG:      122AC6UG7P      15.6
Press any key to continue . . .
*/