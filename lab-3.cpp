#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		int num_min = i;
		for (int j = i + 1; j < n; j++) { if (a[j] < a[num_min]) {num_min = j;}}
		int temp;
		temp = a[i];
		a[i] = a[num_min];
		a[num_min] = temp;
	}


	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

}