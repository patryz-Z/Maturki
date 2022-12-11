#include <iostream>
#include <algorithm>

using namespace std;

inline int suma_binarna(int liczba)
{
	int suma_binarnych = 0;

	while (liczba > 0)
	{
		if (liczba % 2 == 1)
		{
			suma_binarnych++;
		}

		liczba /= 2;

	}

	return suma_binarnych;
}


inline bool czy_jest_pierwsza(int liczba)
{
	if (liczba < 2)
	{
		return false;
	}

	for (int i = 2; i <= liczba/2; i++)
	{
		if (liczba % i == 0)
		{
			return false;
		}

	}

	return true;
}

inline int suma(int numb)
{
	int sum = 0;

	while (numb > 0)
	{
		sum += numb % 10;
		numb /= 10;
	}

	return sum;
}

int main(void)
{
	int ile[3] = {};


	for (int i = 0; i <= 100000; i++)
	{
		if (czy_jest_pierwsza(i) and czy_jest_pierwsza(suma(i)) and czy_jest_pierwsza(suma_binarna(i)))
		{
			if (i <= 1000 and i >= 2)
			{
				ile[0]++;
			}
			if (i <= 10000 and i >= 100)
			{
				ile[1]++;
			}
			if (i <= 100000 and i >= 1000)
			{
				ile[2]++;
			}
			
		}
	}

	cout << "W przedziale 1 jest: " << ile[0];
	cout << "\nW przedziale 2 jest: " << ile[1];
	cout << "\nW przedziale 3 jest: " << ile[2];

}
