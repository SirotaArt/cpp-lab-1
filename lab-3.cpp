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
	int pref[sizeof(arr)]; 		//Создание перфикс. и суфикс. массивов
	int suf[sizeof(arr)];
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

	int minDiff = pow(10, 8);

	for (int i = 0; i < n - 1; i++) 	//Поиск наименьшей разницы между элементами суф. и преф. массивов
	{
		int diff = abs(pref[i] - suf[i+1]);

		if (diff < minDiff) 
		{ 
			minDiff = diff; 
		}
	}

	return minDiff;
}