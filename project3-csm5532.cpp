/*
Author:		Cole Meyers - csm5532
Class:		CMPSC 121
Project:	3
File:		project3-csm5532.cpp
Purpose:	inventory report with vectors of structs

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
#include <algorithm>
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

// fills vectors
bool get_data(vector <Parts> & parts)
{
	Parts temp;
	ifstream doc;
	doc.open("C:\\Users\\Cole Meyers\\Documents\\School\\Penn State\\CMPSC 121\\projects\\project3-csm5532\\parts.txt");
	if (!doc)
		cout << "Error opening file.\n";
	else
	{
		while (doc >> temp.number >> temp.cls >> temp.ohb >> temp.cost)
			parts.push_back(temp);
		return true;
	}
}

// Does a binary search  
int bin_search(string key, const vector<string>& part_number)
{
	
}

// Asks user for a part number to search for
string get_target()
{
	string entry;
	cout << "Enter a part number.\n";
	cin >> entry;
	return entry;
}

// gets remaining info to add a part number
void get_more_data(char& class_in, int& part_ohb_in, double& part_cost_in)
{
	cout << "Enter part class, on hand balance, and unit cost.\n";
	cin >> class_in >> part_ohb_in >> part_cost_in;
}

// Inserts part number data into vectors into the proper location
// See book for information on how to write this
void insert_data(vector <Parts> &parts,	string part_in, char class_in, 
	int part_ohb_in, double part_cost_in)
{

}

// Displays info on part number
void display(const vector <Parts> &parts, int finder)
{
	double value;
	value = static_cast<double>(parts[finder].ohb) * parts[finder].cost;
	cout << "There are " << parts[finder].ohb << " of Part Number " << parts[finder].number <<
		" in\ninventory. It is a class " << parts[finder].cls << " part. The cost\n" <<
		"is $" << fixed << setprecision(2) << parts[finder].cost << ". The value of that inventory is\n" <<
		"$" << value << ".\n";
}

// sorts vectors (Calls swapper) 
void sort(vector <Parts> &parts)
{

}

// prints search stats
void print_stats(int searches, int good, int bad)
{

}

// writes out file when program ends, so additions are saved to file
void put_data(const vector <Parts> &parts)
{
	ofstream out;
	out.open("C:\\Users\\Cole Meyers\\Documents\\School\\Penn State\\CMPSC 121\\projects\\project3 - csm5532\\report.txt");

	out.close();
}

// templated swap function – Swaps two items in a vector of any type
// Put this BEFORE main()  Called from sort function
template <class CType>
void swapper(CType& a, CType & b)
{
	CType temp;
	temp = a;
	a = b;
	b = temp;
}

int main()
{
	vector <Parts> parts;
	string query = get_target();

	return 0;
}