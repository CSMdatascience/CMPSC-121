#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
const double PI = 3.14159;
int main()
{
	double R, r, V, S;
	cout << "Enter the radius of ring and radius of cross section." << endl;
	cin >> R >> r;
	V = 2 * pow(PI, 2)*R*pow(r, 2);
	S = 4 * pow(PI, 2)*R*r;
	cout << fixed << setprecision(3);
	cout << "For a ring with radius of " << R << endl <<
		"and cross section radius of " << r << endl <<
		"The volume is:\t\t" << V << endl <<
		"The surface area is:\t" << S << endl;
	return 0;
}

/* Sample output:
Enter the radius of ring and radius of cross section.
25.75 3
For a ring with radius of 25.750
and cross section radius of 3.000
The volume is:          4574.554
The surface area is:    3049.703
Press any key to continue . . .
*/