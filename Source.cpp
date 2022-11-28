#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

inline string longest_(string word)
{
	string longest_palindrom = "";
	string reversed;
	string base;
	for (int i = 0; i < word.length(); i++)
	{
		base = base + word[i];
		reversed = base;
		reverse(reversed.begin(), reversed.end());

		if (base == reversed)
		{
			longest_palindrom = base;
		}
	}

	return longest_palindrom;


}


string encryption(string word)
{
	string generated_pass = "";

	string in_palindrom = longest_(word);
	int palindrom_len = in_palindrom.length();
	
	string rest = "";
	string reversed_rest = "";

	for (int i = palindrom_len; i < word.length(); i++)
	{
		rest += word[i];
	}

	reversed_rest = rest;
	reverse(reversed_rest.begin(), reversed_rest.end());

	generated_pass = reversed_rest + in_palindrom + rest;

	return generated_pass;
}


int main(void)
{
	fstream base_file;
	base_file.open("slowa.txt", ios::in);

	string wrd;

	vector<string>dlugosc_12;

	int longest = 0;
	string longest_wrd = "";

	int shortest = 0;
	string shortest_wrd = "";

	int sum_of_len = 0;

	for (int i = 0; i < 1000; i++)
	{
		if (i == 1)
		{
			shortest = encryption(wrd).length();
			shortest_wrd = encryption(wrd);
		}
		base_file >> wrd;
		//cout << encryption(wrd) << endl;

		if (encryption(wrd).length() == 12)
		{
			dlugosc_12.push_back(encryption(wrd));
		}
		if (encryption(wrd).length() > longest)
		{
			longest = encryption(wrd).length();
			longest_wrd = encryption(wrd);
		}
		if (encryption(wrd).length() < shortest)
		{
			shortest = encryption(wrd).length();
			shortest_wrd = encryption(wrd);
		}
		
		sum_of_len += encryption(wrd).length();
	}

	cout << "Hasla o dlugosci '12':\n";
	for (auto i : dlugosc_12)
	{
		cout << i << endl;
	}
	cout << "\nNajdluzsze haslo:\n" << longest_wrd << endl;
	cout << "\nNajkrotsze haslo:\n" << shortest_wrd << endl;

	cout << "\nLaczna dlugosc: " << sum_of_len;



}