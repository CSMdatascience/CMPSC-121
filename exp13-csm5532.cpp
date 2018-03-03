/*
Author:		Cole Meyers - csm5532
Class:		CMPSC 121
Lab:		13
File:		lab13-csm5532.cpp
Purpose:	arrays and files

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
#include <cstdlib>
#include <array>
#include <string>
using namespace std;

bool readFile(string candidates[], int & size)
{
	ifstream cand;
	cand.open("C:\\Users\\Cole Meyers\\Documents\\School\\Penn State\\CMPSC 121\\labs\\lab13-csm5532\\candidates.txt");
	if (cand)
	{
		int i = 0;
		for (i; i < size; i++)
		{
			cand >> candidates[i];
			if (candidates[i] == "")
				size = i - 1;
		}
		return true;
	}
	else
	{
		cout << "'candidates.txt' failed to open.\n";
		return false;
	}
}

void getVotes(int votes[], int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		votes[i] = { rand() % 25000 + 1500 };
	}
}

void calculatePercents(int votes[], double percents[], int size)
{
	int total = 0;
	for (int i = 0; i < size; i++)
		total += votes[i];
	for (int j = 0; j < size; j++)
		percents[j] = { static_cast<double>(votes[j]) / total * 100 };
	
}

void displayResults(string candidates[], int votes[], double percents[], int size)
{
	cout << fixed;
	cout << "Candidate    Votes    Percent\n";
	for (int i = 0; i < size; i++)
		cout << setw(9) << candidates[i] << "    " << 
		setw(5) << right << votes[i] << "          " << 
		setw(3) << setprecision(1)<< percents[i] << "%\n";

	int i_winner = 0, most_votes = 0;
	for (int j = 0; j < size; j++)
	{
		if (votes[j] > most_votes)
		{
			most_votes = votes[j];
			i_winner = j;
		}
	}

	cout << "\nThe winner is " << candidates[i_winner] << " with " << votes[i_winner] << " votes!\n";
}

int main()
{
	const int CAPACITY = 25;
	int size = CAPACITY;
	string candidates[CAPACITY];
	int votes[CAPACITY];
	double percents[CAPACITY];
	
	readFile(candidates, size);
	getVotes(votes, size);
	calculatePercents(votes, percents, size);
	displayResults(candidates, votes, percents, size);
	return 0;
}

/* Sample execution:

Candidate    Votes    Percent
Rubio    10495          6.1%
Bush     8333          4.9%
Christie     1634          1.0%
Paul    25116          14.7%
O'Malley     3890          2.3%
Cruz    20305          11.9%
Clinton    24636          14.4%
Trump     8622          5.0%
Kasich     6589          3.9%
Sanders     1620          0.9%
Carson     1700          1.0%
Gilmore     4455          2.6%
Fiorina    13228          7.7%
Santorum    13925          8.1%
Huckabee     7673          4.5%
Graham     8114          4.7%
Jindal     6680          3.9%
Walker     4032          2.4%

The winner is Paul with 25116 votes!
Press any key to continue . . .*/