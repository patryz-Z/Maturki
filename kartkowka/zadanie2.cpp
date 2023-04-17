#include <iostream>
#include <fstream>

using namespace std;

inline bool wzgledne_nwd(int num1, int num2)
{
	while (num1 != num2) //dopoki liczby sa inne od sb
	{
		if (num1 > num2) //poki jedna z nich jest wieksza
		{
			num1 -= num2;
		}
		else
		{
			num2 -= num1;
		}

	}
	if (num1 == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main(void)
{
	fstream base_file;
	base_file.open("liczby.txt", ios::in);

	int M, a, b;

	int counter = 0;

	while (!base_file.eof())
	{
		base_file >> M;
		base_file >> a;
		base_file >> b;

		if (wzgledne_nwd(M, a))
		{
			counter++;
		}
	}

	printf("%i", counter);

}
