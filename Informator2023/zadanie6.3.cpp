#include <iostream>
#include <fstream>


using namespace std;

inline bool anty_palindrom(string linia)
{
	for (int i = 0; i < linia.length() / 2; i++)
	{
		if (linia[i] == linia[linia.length() - i - 1])
		{
			return false;
		}
	}
	return true;
}

int main(void)
{
	fstream base_file;
	base_file.open("dane6.txt", ios::in);

	string actual_line;

	int ilosc = 0;

	while (!base_file.eof())
	{
		base_file >> actual_line;
		//cout << actual_line << endl;

		if (anty_palindrom(actual_line))
		{
			cout << actual_line << endl;
			ilosc++;
		}

	}

	cout << endl << ilosc;


}
