/*
Author:		Cole Meyers - csm5532
Class:		CMPSC 121
Lab:		12
File:		lab12-csm5532.cpp
Purpose:	structs

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

struct SalesRecord
{
	string invoice;
	char code;
	double cost;
};

void accumulate(const SalesRecord &s, 
	double & capSales, double & eqpSales, double & prtSales)
{
	if (s.code == 'A')
		capSales += s.cost;
	else if (s.code == 'B')
		eqpSales += s.cost;
	else if (s.code == 'C')
		prtSales += s.cost;
}
void writeReport(double capSales, double eqpSales, double prtSales)
{
	double totalSales, pctCap, pctEqp, pctPrt;
	totalSales = capSales + eqpSales + prtSales;
	pctCap = capSales / totalSales * 100;
	pctEqp = eqpSales / totalSales * 100;
	pctPrt = prtSales / totalSales * 100;
	ofstream report;
	report.open("C:\\Users\\Cole Meyers\\Documents\\School\\Penn State\\CMPSC 121\\labs\\lab12-csm5532\\inventoryReport.txt");

	report << fixed << setprecision(2);
	report << "\tS A L E S   R E P O R T\n" <<
		"Capital Equipment\t$" << capSales << "\t" << pctCap << "%\n" <<
		"Expensed Equipment\t$" << eqpSales << "\t" << pctEqp << "%\n" <<
		"Small Parts\t\t$" << prtSales << "\t" << pctPrt << "%\n" <<
		"\t\t\t---------\n" <<
		"Total Sales\t\t$" << totalSales << endl;

	report.close();
}

int main()
{
	SalesRecord Line;
	double capSales = 0, eqpSales = 0, prtSales = 0;
	ifstream sales;
	sales.open("C:\\Users\\Cole Meyers\\Documents\\School\\Penn State\\CMPSC 121\\labs\\lab12-csm5532\\sales.txt");
	
	if (sales)
	{
		while (sales >> Line.invoice >> Line.code >> Line.cost)
			accumulate(Line, capSales, eqpSales, prtSales);
	}
	else
		cout << "Error opening file.\n";
	sales.close();
	
	writeReport(capSales, eqpSales, prtSales);
	return 0;
}