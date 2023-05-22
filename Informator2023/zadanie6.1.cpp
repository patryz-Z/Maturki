#include <iostream>
#include <fstream>


using namespace std;

//podstawe znajduje za pomoca znalezienia najwiekszej liczby w lini

int main(void)
{
	fstream base_file;
	base_file.open("przykladowe.txt", ios::in);

	
	int podstawy[10] = {}; //tablica ktora bedzie przechowywac ilosc wystepowania danych podstaw

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

		podstawy[podstawa]++;

		podstawa = 0;
	}

	for (int i = 1; i < 10; i++)
	{
		cout << i+1 << " " << podstawy[i] << endl;
	}

}
