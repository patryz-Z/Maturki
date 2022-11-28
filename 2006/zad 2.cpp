#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

	fstream plik_z_danymi;
	plik_z_danymi.open("dane.txt", ios::in);

	string slowa;
	int ile = 0;
	int character = 0;

	int dlugosc = sizeof(slowa) / sizeof(slowa[0]);

	for (int i = 0; i < dlugosc; i++)
	{
		plik_z_danymi >> slowa;
		cout << slowa << endl;
		for (int j = 0; j < slowa.length(); j++)
		{
			character = int(slowa[i]);
			cout << hex << character;
			if (character % 2 == 0)
			{
				
				ile++;
			}
		}

	}

	




	cout << " jest ich : " << ile;
	return 0;
}