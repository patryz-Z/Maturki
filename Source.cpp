#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(void)
{
	fstream plik_z_danymi;
	plik_z_danymi.open("dane.txt", ios::in);

	string slowa[1000] = { };


	int dlugosc = sizeof(slowa) / sizeof(slowa[0]);

	for (int i = 0; i < dlugosc; i++)
	{
		plik_z_danymi >> slowa[i];

	}
	
	sort(slowa, slowa + dlugosc);

	bool wiecej_niz_raz = false;
	int ile_takich = 0;
	int strike = 1;
	int najwiecej_razy = 0;
	string slowo_najwiecej_razy = "";

	for (int i = 0; i < dlugosc-1; i++)
	{
		if (slowa[i] == slowa[i + 1])
		{
			wiecej_niz_raz = true;
			strike++;
		}
		else
		{
			if (wiecej_niz_raz)
			{
				ile_takich++;
				wiecej_niz_raz = false;

				if (strike > najwiecej_razy)
				{
					najwiecej_razy = strike;
					slowo_najwiecej_razy = slowa[i];
					
				}
			}

			strike = 1;
		}
	}

	cout << ile_takich << " wystapilo wiecej niz raz\n";
	cout << "Najwiecej wystapilo slowo: " << slowo_najwiecej_razy << " wystapilo: " << najwiecej_razy << " razy\n";

}