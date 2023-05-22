#include <iostream>
#include <fstream>


using namespace std;

int suma(string linia)
{
	int suma = 0;

	for (int i = 0; i < linia.length(); i++)
	{
		suma += linia[i] - 48;
	}
	return suma;
}

//podstawe znajduje za pomoca znalezienia najwiekszej liczby w lini

int main(void)
{
	fstream base_file;
	base_file.open("przykladowe.txt", ios::in);

	
	int podstawy[10] = {}; //tablica ktora bedzie przechowywac ilosc wystepowania danych podstaw
	string wskazane[10] = {};
	int sumy[10] = {};

	string actual_line;

	int podstawa = 0;//zmienna pomocniczna ktora bedzie przechowywac informacje o podstawie w danej lini

	while (!base_file.eof())
	{
		base_file >> actual_line;
		cout << actual_line << endl;

		for (int i = 0; i < actual_line.length(); i++)
		{
			if (actual_line[i] - 48 > podstawa) 
			{
				podstawa = actual_line[i] - 48;
			}
		}
		//szukanie ktora to jesd podstawa

		if (sumy[podstawa] < suma(actual_line))
		{
			sumy[podstawa] = suma(actual_line);
			wskazane[podstawa] = actual_line;
		}


		podstawa = 0;
	}

	for (int i = 1; i < 10; i++)
	{
		if (wskazane[i] != "")
		{
			cout << i + 1 << " " << wskazane[i] << endl;

		}
	}

}
