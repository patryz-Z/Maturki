#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

void zad_1_2()
{
	int obecna_suma = 0, najwieksza_suma = 0, liczba;

	int tablica[] = { 1, -2, 6, -5, 7, -3 };
	int dlugosc = sizeof(tablica) / 4;

	for (int i = 0; i < dlugosc; i++)
	{

		obecna_suma += tablica[i];
		if (obecna_suma < 0)
		{
			obecna_suma = 0;
		}

		if (obecna_suma > najwieksza_suma)
		{
			najwieksza_suma = obecna_suma;
		}

	}

	cout << najwieksza_suma;
}


void zadanie_3()
{

	fstream plik;
	plik.open("dane5-1.txt", ios::in);

	int najdluzszy_ciag = 0;
	int strike = 0;
	int najdluzsza_liczba = 0;

	int liczby[20] = { };

	cout << "Tablica: ";
	for (int i = 0; i < 20; i++)
	{
		plik >> liczby[i];
		cout << liczby[i] << " ";
	}

	sort(liczby, liczby + 20);

	cout << "\nTablica Po sorcie: ";
	for (int i = 0; i < 20; i++)
	{
		cout << liczby[i] << " ";
	}

	for (int i = 0; i < 19; i++)
	{
		if (liczby[i] == liczby[i + 1])
		{
			strike++;

			if (strike > najdluzszy_ciag)
			{
				najdluzszy_ciag = strike;
				najdluzsza_liczba = liczby[i];
			}
		}
		else
		{

			strike = 1;

		}
	}

	cout << "\nNajwiecej wystapila liczba: " << najdluzsza_liczba << " bo wystapila: " << najdluzszy_ciag << " razy";
}

int main() {



	return 0;
}
