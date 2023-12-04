#include <iostream>
#include <cmath>
using namespace std;
int sor(int arr[], int n);

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++)    // Ввод чисел
	{
		cin >> arr[i];
	}

	for (int j = 0; j < n; j++)  //Сортировка
	{
		int num_min = j;

		for (int i = j; i < n; i++)
		{
			if (arr[i] < arr[num_min])
			{
				num_min = i;
			}
		}

		int temp;
		temp = arr[j];
		arr[j] = arr[num_min];
		arr[num_min] = temp;
	}

	cout << sor(arr, n);
}

int sor(int arr[], int n)
{
	int minDiff = pow(10, 8);

	if (n == 2 or n % 2 != 0)
	{
		int* pref = new int[n]; 		//Создание перфикс. и суфикс. массивов
		int* suf = new int[n];
		pref[0] = arr[0];

		for (int i = 1; i < n; i++) 		//Заполнение преф.
		{
			pref[i] = pref[i - 1] + arr[i];
		}

		suf[n - 1] = arr[n - 1];

		for (int i = n - 2; i >= 0; i--) 	//Заполнение суф.
		{
			suf[i] = suf[i + 1] + arr[i];
		}

		for (int i = 0; i < n - 1; i++) 	//Поиск наименьшей разницы между элементами суф. и преф. массивов
		{
			int diff = abs(pref[i] - suf[i + 1]);

			if (diff < minDiff)
			{
				minDiff = diff;
			}
		}
		return minDiff;
	}

	else
	{
		int* Arr = new int[n];
		Arr = arr;
		int a = 0;
		int b = 0;
		for (int i = 0; i < n; i++)
		{
			if (i % 4 == 0 || i % 4 == 3)
			{
				 a += Arr[i];
			}

			else
			{
				b += Arr[i];
			}
		}

		minDiff = abs(a - b);
		return minDiff;
	}

}
