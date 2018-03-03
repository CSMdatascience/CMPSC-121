/*
Author:		Cole Meyers - csm5532
Class:		CMPSC 121
Lab:		11
File:		lab11-csm5532.cpp
Purpose:	string functions

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

using namespace std;

/*string fixName(string n);
string fixSSN(string ss);
string fixPhone(string ph);
string fixAddress(string addr);
string fixcity(string cty);
string fixState(string st);
string extractField(string &s);
void buildLine(string &s, string field);*/
int main()
{
	int SIZE = 100;
	int nums[SIZE];
	for (int i = 0; i<SIZE; i++)
		nums[i] = i*SIZE;
	return 0;
}