/*
Author:		Cole Meyers - csm5532
Class:		CMPSC 121
Project:	1
File:		project1-csm5532.cpp
Purpose:	calculate temp with windchill and display in table

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
#include <locale>
#include <math.h>
using namespace std;


double tempA, t0, t5, t10, t15, t20, t25, t30, t35, t40, t45;
const double w5 = pow(5, 0.16), w10 = pow(10, 0.16), w15 = pow(15, 0.16),
w20 = pow(20, 0.16), w25 = pow(25, 0.16), w30 = pow(30, 0.16),
w35 = pow(35, 0.16), w40 = pow(40, 0.16), w45 = pow(45, 0.16);

int main()
{
	cout << " Temp : ------------ Wind Speed ---------------------------------------------\n" <<
		"\t    5\t   10\t   15\t   20\t   25\t   30\t   35\t   40\t   45\n";

	for (tempA = -5; tempA < 51; tempA += 5)
	{
		t0 = tempA;
		t5 = 35.74 + 0.6215*tempA - 35.75*w5 + 0.4275*tempA*w5;
		t10 = 35.74 + 0.6215*tempA - 35.75*w10 + 0.4275*tempA*w10;
		t15 = 35.74 + 0.6215*tempA - 35.75*w15 + 0.4275*tempA*w15;
		t20 = 35.74 + 0.6215*tempA - 35.75*w20 + 0.4275*tempA*w20;
		t25 = 35.74 + 0.6215*tempA - 35.75*w25 + 0.4275*tempA*w25;
		t30 = 35.74 + 0.6215*tempA - 35.75*w30 + 0.4275*tempA*w30;
		t35 = 35.74 + 0.6215*tempA - 35.75*w35 + 0.4275*tempA*w35;
		t40 = 35.74 + 0.6215*tempA - 35.75*w40 + 0.4275*tempA*w40;
		t45 = 35.74 + 0.6215*tempA - 35.75*w45 + 0.4275*tempA*w45;
		cout << setw(5) << fixed << setprecision(1);
		cout << t0 << "\t" << t5 << "\t" << t10 << "\t" << t15 << "\t" <<
			t20 << "\t" << t25 << "\t" << t30 << "\t" << t35 << "\t" <<
			t40 << "\t" << t45 << endl;
	}
	return 0;
}

/* Sample execution:
Temp : ------------ Wind Speed ---------------------------------------------
5      10      15      20      25      30      35      40      45
-5.0   -16.4   -22.1   -25.8   -28.6   -30.8   -32.7   -34.3   -35.7   -37.0
0.0   -10.5   -15.9   -19.4   -22.0   -24.1   -25.9   -27.4   -28.8   -30.0
5.0   -4.6    -9.7    -13.0   -15.4   -17.4   -19.1   -20.5   -21.8   -23.0
10.0   1.2     -3.5    -6.6    -8.9    -10.7   -12.3   -13.6   -14.8   -15.9
15.0   7.1     2.7     -0.2    -2.3    -4.0    -5.5    -6.8    -7.9    -8.9
20.0   13.0    8.9     6.2     4.2     2.6     1.3     0.1     -0.9    -1.8
25.0   18.9    15.1    12.6    10.8    9.3     8.1     7.0     6.1     5.2
30.0   24.7    21.2    19.0    17.4    16.0    14.9    13.9    13.0    12.2
35.0   30.6    27.4    25.4    23.9    22.7    21.7    20.8    20.0    19.3
40.0   36.5    33.6    31.8    30.5    29.4    28.5    27.7    26.9    26.3
45.0   42.3    39.8    38.2    37.0    36.1    35.3    34.5    33.9    33.3
50.0   48.2    46.0    44.6    43.6    42.8    42.0    41.4    40.9    40.4
Press any key to continue . . .

NOTE 1
I used the cmd prompt "mark" tool to copy the above sample output, and for 
some reason when I pasted the output here in VS, the second line is missing 
a few tab characters. These tab characters are present when the code is executed.

NOTE 2
I was not able to "right-justify" the shorter values which appear diagonally
in this table. For line 47, I tried using:
"cout << setw(5) << fixed << setprecision(1);"
but I get the same output, and I'm not quite sure why...

*/