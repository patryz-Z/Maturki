#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(void)
{
	fstream base_file;
	base_file.open("dane.txt", ios::in);
	
	int palindrome = 0;
	
	string stringer;
	string reversed;

	while (!base_file.eof())
	{
		base_file >> stringer;
		reversed = stringer;
		reverse(reversed.begin(), reversed.end());

		if (reversed == stringer)
		{
			palindrome++;
		}
	}

	cout << "Jest: " << palindrome << " palindromow" ;
}
