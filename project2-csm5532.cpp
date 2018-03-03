/*
Author:		Cole Meyers - csm5532
Class:		CMPSC 121
Project:	2
File:		project2-csm5532.cpp
Purpose:	read invoices

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
#include <fstream>
#include <string>

using namespace std;

ofstream fout;

double calcCost(int quantity, double unitCost)
{
	double totalCost = static_cast<double>(quantity) * unitCost;
	return totalCost;
}

double accTotal(double totalCost, double itemCost)
{
	double newTotalCost = totalCost + itemCost;
	return newTotalCost;
}

void printLine(string itemNo, string name, int quantity, 
	double unitCost, double totalCost)
{
	fout << itemNo << "\t" << setw(10) << left << name << "  " << 
		setw(3) << fixed << right << quantity << "    " << 
		setw(6) << setprecision(2) << right << unitCost << "    " << 
		setw(7) << totalCost << endl;
}

void printInvoiceHeader(string date)
{
	fout << "Invoice date: " << date << "\n\n";
}

void printReportHeader()
{
	fout << "\tErie Industrial Supply Corporation\n";
}

void printTotal(double invoiceTotal)
{
	fout << "Total ......................................" << invoiceTotal << "\n\n";
}




int items, quantity;
double unitCost;
string date, name, itemNo;

int main()
{
	double totalCost, invoiceCost, unitCost;
	ifstream fin;
	fin.open("C:\\Users\\Cole Meyers\\Documents\\School\\Penn State\\CMPSC 121\\projects\\project2-csm5532\\input.txt");
	
	if (fin)
	{
		fout.open("C:\\Users\\Cole Meyers\\Documents\\School\\Penn State\\CMPSC 121\\projects\\project2-csm5532\\output.txt"); 
		
		if (fout)
		{
			printReportHeader();

			while (fin >> items >> date)
			{				
				totalCost = 0;
				invoiceCost = 0;
				printInvoiceHeader(date);
				
				for (int i = 0; i < items; i++)
				{
					fin >> itemNo >> name >> quantity >> unitCost;
					totalCost = calcCost(quantity, unitCost);
					invoiceCost = accTotal(invoiceCost, totalCost);
					printLine(itemNo, name, quantity, unitCost, totalCost);
				}
				printTotal(invoiceCost);
			}
			fin.close();
			fout.close();
		}
		else
			cout << "Error opening output file.\n";		
	}
	else
		cout << "Error opening input file.\n";

	
	return 0;
}