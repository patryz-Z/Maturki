#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int rownowaga(string raw)
{
	//biali - wielkie litery
	//czarni - male litery
	vector<char>biali;
	vector<char>czarni;

	for (int i = 0; i < raw.length(); i++)
	{
		if (islower(raw[i]))
		{
			czarni.push_back(raw[i]);
		}
		if (isupper(raw[i]))
		{
			biali.push_back(tolower(raw[i]));
		}
	}
	sort(biali.begin(), biali.end());
	sort(czarni.begin(), czarni.end());



	if (czarni == biali)
	{
		return czarni.size() + biali.size();
	}
	else
	{
		return 0;
	}

	
}

int main(void)
{
	fstream base_file;
	base_file.open("szachy.txt", ios::in);

	//app variables, dont touch it
	string line;
	int limiter = 1;
	string raw_board = "";

	int code = 0;
	int rownowagi = 0;
	int najmniej_bierek = INT_MAX;
	
	while (!base_file.eof())
	{
		base_file >> line;
		raw_board += line;


		if (limiter == 8)
		{
			code = rownowaga(raw_board);

			if (code != 0)
			{
				rownowagi++;
				if (code < najmniej_bierek)
				{
					najmniej_bierek = code;
				}
			}

			code = 0;

			//must have
			raw_board = "";
			limiter = 1;
		}
		else
		{
			limiter++;
		}
	}

	printf("jest %i rownowag, najmniej bierek %i", rownowagi, najmniej_bierek);
	
}
