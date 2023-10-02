#include <iostream>
#include <cmath>
using namespace std;
double t(double x); double fact(double x); double div(double y);

double t(double x) {
	int k1, k2;
	double a1, a2;
	a1 = 0; a2 = 0;
	k1 = k2 = 0;
	while (k1 != 11) {
		a1 += pow(x, 2 * k1 + 1) / fact(2 * k1 + 1); k1 += 1;
	}
	while (k2 != 11) {
		a2 += pow(x, 2 * k2) / fact(2 * k2); k2 += 1;
	}
	return (a1 / a2);
}

double fact(double x) {
	if (x <= 0) {
		return 1;
	}
	else {
		return x * fact(x - 2);
	}
}


double div(double y) {
	return  (7 * t(0.25) + 2 * t(1 + y)) / (6 - t(y * y - 1));
}


int main()
{
	double y;
	cin >> y;
	cout << div(y);

}