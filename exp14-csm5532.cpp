/*
Author:		Cole Meyers - csm5532
Class:		CMPSC 121
Lab:		14
File:		lab14-csm5532.cpp
Purpose:	vector inventory report

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
#include <vector>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

struct Parts
{
	string number;
	char cls;
	int ohb;
	double cost;
};

bool readFile(vector <Parts> &pVector)
{
	Parts temp;
	ifstream doc;
	doc.open("C:\\Users\\Cole Meyers\\Documents\\School\\Penn State\\CMPSC 121\\labs\\lab14-csm5532\\parts.txt");
	if (doc.fail())
		return false;
	else
	{
		while (doc >> temp.number >> temp.cls >> temp.ohb >> temp.cost)
			pVector.push_back(temp);
		doc.close();
		return true;
	}
	
}
int displayMenu()
{
	cout << "\tR E P O R T S   M E N U\n" <<
		"1. Total cost of intentory.\n" <<
		"2. A count of parts of each class.\n" <<
		"3. Cost of inventory for a class.\n" <<
		"4. Part with highest cost of inventory.\n" <<
		"5. Part with lowest cost of inventory.\n" <<
		"6. Exit.\n";
	int entry;
	cin >> entry;
	system("cls");
	cout << "Your choice was " << entry << endl;
	if (entry == 1)
		return 1;
	else if (entry == 2)
		return 2;
	else if (entry == 3)
		return 3;
	else if (entry == 4)
		return 4;
	else if (entry == 5)
		return 5;
	else if (entry == 6)
		return 6;
	else
	{
		cout << "Invalid entry. Enter a number between 1 and 6.\n";
		cin >> entry;
	}
		
}

double totalCost(const vector <Parts> &pVector)
{
	double total = 0;
	for (size_t i = 0; i < pVector.size(); i++)
		total += static_cast<double>(pVector[i].ohb) * pVector[i].cost;
	return total;
}

double costForClass(char classIn, const vector <Parts> & pVector)
{
	classIn = toupper(classIn);
	double costCls = 0;
	for (size_t i = 0; i < pVector.size(); i++)
		if (pVector[i].cls == classIn)
			costCls += static_cast<double>(pVector[i].ohb) * pVector[i].cost;
	return costCls;
}

string highestCost(const vector <Parts> &pVector)
{
	double comparitor = 0;
	string highest;
	for (size_t i = 0; i < pVector.size(); i++)
		if (pVector[i].cost > comparitor)
		{
			comparitor = pVector[i].cost;
			highest = pVector[i].number;
		}
	return highest;
}

string lowestCost(const vector <Parts> &pVector)
{
	double comparitor = 999999999999999;
	string lowest;
	for (size_t i = 0; i < pVector.size(); i++)
		if (pVector[i].cost < comparitor)
		{
			comparitor = pVector[i].cost;
			lowest = pVector[i].number;
		}
	return lowest;
}

void countByClass(const vector <Parts> & pVector,
	vector <int> &classCounts)
{
	for (size_t i = 0; i < pVector.size(); i++)
	{
		if (pVector[i].cls == 'A')
			classCounts[0]++;
		else if (pVector[i].cls == 'B')
			classCounts[1]++;
		else if (pVector[i].cls == 'C')
			classCounts[2]++;
		else if (pVector[i].cls == 'D')
			classCounts[3]++;
		else if (pVector[i].cls == 'E')
			classCounts[4]++;
		else if (pVector[i].cls == 'F')
			classCounts[5]++;
	}
}

void displayCounts(const vector <int> & classCounts)
{
	cout << "A\t" << classCounts[0] << endl <<
		"B\t" << classCounts[1] << endl <<
		"C\t" << classCounts[2] << endl <<
		"D\t" << classCounts[3] << endl <<
		"E\t" << classCounts[4] << endl <<
		"F\t" << classCounts[5] << "\n\n";
}

int main()
{
	vector <Parts> parts;
	vector <int> classCounts = { 0, 0, 0, 0, 0, 0 };
	readFile(parts);
	countByClass(parts, classCounts);
	int choice = displayMenu();
	while (choice != 6)
	{
		if (choice == 1)
		{
			cout << "Total cost of inventory is $" << fixed << setprecision(2) << totalCost(parts) << "\n\n";
			choice = displayMenu();
		}
		else if (choice == 2)
		{
			cout << "Count of parts by class:\n";
			displayCounts(classCounts);
			choice = displayMenu();
		}
		else if (choice == 3)
		{
			cout << "Which class?\n";
			char cls;
			cin >> cls;
			cls = toupper(cls);
			cout << "Cost of inventory for class " << cls << " is $" << fixed << setprecision(2) << costForClass(cls, parts) << "\n\n";
			choice = displayMenu();
		}
		else if (choice == 4)
		{
			cout << "The part with the highest cost of inventory is " << highestCost(parts) << "\n\n";
			choice = displayMenu();
		}
		else if (choice == 5)
		{
			cout << "The part with the lowest cost of inventory is " << lowestCost(parts) << "\n\n";
			choice = displayMenu();
		}
		else if (choice == 6)
		{
			break;
		}
	}
	return 0;
}

/* Sample execution:
R E P O R T S   M E N U
1. Total cost of intentory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with highest cost of inventory.
5. Part with lowest cost of inventory.
6. Exit.

Your choice was 1
Total cost of inventory is $342965.70

R E P O R T S   M E N U
1. Total cost of intentory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with highest cost of inventory.
5. Part with lowest cost of inventory.
6. Exit.

Your choice was 3
Which class?
a
Cost of inventory for class A is $191180.07

R E P O R T S   M E N U
1. Total cost of intentory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with highest cost of inventory.
5. Part with lowest cost of inventory.
6. Exit.

Your choice was 3
Which class?
b
Cost of inventory for class B is $74764.16

R E P O R T S   M E N U
1. Total cost of intentory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with highest cost of inventory.
5. Part with lowest cost of inventory.
6. Exit.

Your choice was 3
Which class?
c
Cost of inventory for class C is $50322.30

R E P O R T S   M E N U
1. Total cost of intentory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with highest cost of inventory.
5. Part with lowest cost of inventory.
6. Exit.

Your choice was 3
Which class?
d
Cost of inventory for class D is $22416.49

R E P O R T S   M E N U
1. Total cost of intentory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with highest cost of inventory.
5. Part with lowest cost of inventory.
6. Exit.

Your choice was 3
Which class?
e
Cost of inventory for class E is $3338.97

R E P O R T S   M E N U
1. Total cost of intentory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with highest cost of inventory.
5. Part with lowest cost of inventory.
6. Exit.

Your choice was 3
Which class?
f
Cost of inventory for class F is $943.71

R E P O R T S   M E N U
1. Total cost of intentory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with highest cost of inventory.
5. Part with lowest cost of inventory.
6. Exit.

Your choice was 4
The part with the highest cost of inventory is P-27345

R E P O R T S   M E N U
1. Total cost of intentory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with highest cost of inventory.
5. Part with lowest cost of inventory.
6. Exit.

Your choice was 5
The part with the lowest cost of inventory is P-31071

R E P O R T S   M E N U
1. Total cost of intentory.
2. A count of parts of each class.
3. Cost of inventory for a class.
4. Part with highest cost of inventory.
5. Part with lowest cost of inventory.
6. Exit.

Your choice was 6
Press any key to continue . . .



*/

