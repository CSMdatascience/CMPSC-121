/*
Author:		Cole Meyers - csm5532
Class:		CMPSC 121
Lab:		10
File:		lab10-csm5532.cpp
Purpose:	lumber cost

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
#include <string>
using namespace std;
const double INCHESINLINEARFOOT = 12.0;
const double INCHESINONESQUAREFOOT = 144.0;
const double PINECOST = 0.89;
const double FIRCOST = 1.09;
const double CEDARCOST = 2.26;
const double MAPLECOST = 4.40;
const double OAKCOST = 3.10;

bool validateType(char t);

double calcBoardFeet(double th, double wid, double len);
// calculate board feet where th = thickness in inches, 
// wid = width in inches and len = length in feet

double calcCost(char type, int numP, double bf);
// calculate cost based on type, number of pieces and board feet

string getTypeName(char type);
// return name of wood type based on char representing type, eg P = Pine

void getData(char & woodType, int & numPieces, double & thickness,
	double & width, double & length);
// Get data on sale

int main()
{
	char woodType, reply;
	int numPieces;
	double thickness, width, length;
	double cost, totalCost, boardFeet;
	string woodTypeName;
	cout << fixed << setprecision(2);
	do
	{
		totalCost = 0;
		do
		{
			getData(woodType, numPieces, thickness, width, length);
			if (woodType != 'T')
			{
				boardFeet = calcBoardFeet(thickness, width, length);
				cost = calcCost(woodType, numPieces, boardFeet);
				woodTypeName = getTypeName(woodType) + ", cost: $";
				cout << setw(3) << numPieces << setw(6) << thickness
					<< " X " << setw(6) << width << " X " << setw(6)
					<< length << " " << setw(14)
					<< woodTypeName << cost << endl;
				totalCost += cost;
			}
		} while (toupper(woodType) != 'T');
		cout << "Total cost: $" << totalCost << endl;
		cout << "More purchases?" << endl;
		cin >> reply;
	} while (toupper(reply) == 'Y');

}
//Function definitions here:
bool validateType(char t)
{
	if (t == 'P' ||	t == 'F' ||	t == 'C' ||	t == 'M' || t == 'O' ||	t == 'T')
		return true;
	else
		return false;
}

void getData(char & woodType, int & numPieces, double & thickness,
	double & width, double & length)
{
	cout << "Enter item: ";
	cin >> woodType;
	woodType = toupper(woodType);
	while (validateType(woodType) == false)
	{
		cout << woodType << " is not a valid type! Reenter.\n";
		cin >> woodType;
	}
	if (woodType != 'T')
	{
		cout << "Enter number of pieces, thickness , width, and length:\n";
		cin >> numPieces >> thickness >> width >> length;
		while (numPieces <= 0 || thickness <= 0 || width <= 0 || length <= 0)
		{
			cout << "Invalid input. Please enter numbers greater than 0:\n";
			cin >> numPieces >> thickness >> width >> length;
		}
	}	
}

double calcBoardFeet(double th, double wid, double len)
{
	len = len * INCHESINLINEARFOOT;
	double boardFeet = th * ((len * wid) / INCHESINONESQUAREFOOT);
	return boardFeet;
}

double calcCost(char type, int numP, double bf)
{
	double cost = 0;
	numP = static_cast<double>(numP);
	if (type == 'P')
		cost += PINECOST * bf * numP;
	else if (type == 'F')
		cost += FIRCOST * bf * numP;
	else if (type == 'C')
		cost += CEDARCOST * bf * numP;
	else if (type == 'M')
		cost += MAPLECOST * bf * numP;
	else if (type == 'O')
		cost += OAKCOST * bf * numP;

	return cost;
}

string getTypeName(char type)
{
	string typeName;
	if (type == 'P')
		typeName = "Pine";
	else if (type == 'F')
		typeName = "Fir";
	else if (type == 'C')
		typeName = "Cedar";
	else if (type == 'M')
		typeName = "Maple";
	else if (type == 'O')
		typeName = "Oak";

	return typeName;
}

/* Sample Execution:
Enter item: o
Enter number of pieces, thickness , width, and length:
100 2.5 3 20
100  2.50 X   3.00 X  20.00   Oak, cost: $3875.00
Enter item: p
Enter number of pieces, thickness , width, and length:
150 3 3.5 22
150  3.00 X   3.50 X  22.00  Pine, cost: $2569.88
Enter item: t
Total cost: $6444.88
More purchases?
n

Enter item: p
Enter number of pieces, thickness , width, and length:
10 2 2 2
10  2.00 X   2.00 X   2.00  Pine, cost: $5.93
Enter item: F
Enter number of pieces, thickness , width, and length:
10 2 2 2
10  2.00 X   2.00 X   2.00   Fir, cost: $7.27
Enter item: c
Enter number of pieces, thickness , width, and length:
10 2 4 6
10  2.00 X   4.00 X   6.00 Cedar, cost: $90.40
Enter item: m
Enter number of pieces, thickness , width, and length:
10 20 30 40
10 20.00 X  30.00 X  40.00 Maple, cost: $88000.00
Enter item: O
Enter number of pieces, thickness , width, and length:
9 9 9 9
9  9.00 X   9.00 X   9.00   Oak, cost: $1694.93
Enter item: t
Total cost: $89798.53
More purchases?
y
Enter item: P
Enter number of pieces, thickness , width, and length:
20 10 5 2.5
20 10.00 X   5.00 X   2.50  Pine, cost: $185.42
Enter item: z
Z is not a valid type! Reenter.
F
Enter number of pieces, thickness , width, and length:
100 2 3 4
100  2.00 X   3.00 X   4.00   Fir, cost: $218.00
Enter item: p
Enter number of pieces, thickness , width, and length:
10 2 4 1
10  2.00 X   4.00 X   1.00  Pine, cost: $5.93
Enter item: t
Total cost: $409.35
More purchases?
n
Press any key to continue . . .
Press any key to continue . . .
*/