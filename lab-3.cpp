#include <iostream>
#include <cmath>
using namespace std;
int sor(int arr[], int n);

int main()
{
	int n;
	cin >> n;

	const int p = 32;
	int arr[p];
	for (int i = 0; i < n; i++) 
	{
		cin >> arr[i];
	}

	cout << sor(arr, n);
}

int sor(int arr[], int n)
{
	int prefix_sum[sizeof(arr)]; 
	int suffix_sum[sizeof(arr)];
	prefix_sum[0] = arr[0];

	for (int i = 1; i < n; i++) {prefix_sum[i] = prefix_sum[i - 1] + arr[i];}

	suffix_sum[n - 1] = arr[n - 1];

	for (int i = n - 2; i >= 0; i--){suffix_sum[i] = suffix_sum[i + 1] + arr[i];}

	int minDiff = pow(10,8);

	for (int i = 0; i < n - 1; i++)
	{
		int diff = abs(prefix_sum[i] - suffix_sum[i + 1]);

		if (diff < minDiff) { minDiff = diff;}
	}
	return minDiff;
}