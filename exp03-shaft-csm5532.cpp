#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
	double P, n, s, T, D;
	cout << "Enter values for horsepower (P), rpm (n), and shear strength (s) \n";
	cin >> P >> n >> s;
	T = 63000 * (P / n);
	D = pow((16 * T) / s, 0.333);
	cout << fixed << setprecision(3);
	cout << "\tP(HP)\tN(rpm)\t   S(psi)\tT(torque  D(diameter)\n"
		<< "\t" << P << "\t" << n << "   " << s << "\t" << T << "\t  " << D << "\n";
	return 0;
}

/* Sample output:
Enter values for horsepower (P), rpm (n), and shear strength (s)
20 1500 5000
P(HP)   N(rpm)     S(psi)       T(torque  D(diameter)
20.000  1500.000   5000.000     840.000   1.390
Press any key to continue . . .

Enter values for horsepower (P), rpm (n), and shear strength (s)
20 50 5000
P(HP)   N(rpm)     S(psi)       T(torque  D(diameter)
20.000  50.000   5000.000       25200.000         4.314
Press any key to continue . . .

Enter values for horsepower (P), rpm (n), and shear strength (s)
270 40 6500
P(HP)   N(rpm)     S(psi)       T(torque  D(diameter)
270.000 40.000   6500.000       425250.000        10.130
Press any key to continue . . .
*/