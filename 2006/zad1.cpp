#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(void)
{
	fstream base_file;
	base_file.open("dane.txt", ios::in);

	string strings_base[1000] = {};
	int base_len = sizeof(strings_base) / sizeof(strings_base[0]);

	for (int i = 0; i < base_len; i++)
	{
		base_file >> strings_base[i];
	}

	sort(strings_base, strings_base + base_len);

	int over_one = 0;

	int most_times = 0;
	string most_string = "";

	int local = 1;

	for (int i = 0; i < base_len-1; i++)
	{
		if (strings_base[i] == strings_base[i + 1])
		{
			local++;
		}
		else
		{
			if (local > most_times)
			{
				most_times = local;
				most_string = strings_base[i];
			}
			if (local != 1)
			{
				over_one++;
			}
			local = 1;
		}
	}

	cout << "Jest: " << over_one << " slow wystepujacych wiecej niz 1 raz\n";
	cout << "Najczestrzym slowem jest: '" << most_string << "'\n";
	cout << "Liczba jego wystapien: " << most_times << endl;

}
