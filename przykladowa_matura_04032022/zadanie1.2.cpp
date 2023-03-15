#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

//male literki - czarne
//WIELKIE LITERKI - BIALE

using namespace std;

string rownowaga(string raw)
{
	vector<char>pionki_biale; //tworzenie tablicy wektorowej dla bialych i czarnych bierek, pozwala to dynamicznie dodawac rozne wartosci bez okreslania ich ilosci wpierw
	vector<char>pionki_czarne;
	
	string return_code = ""; 


	int bierek_counter = 0;


	for (int i = 0; i < 64; i++)
	{
		if (islower(raw[i]))
		{
			pionki_czarne.push_back(raw[i]);
			bierek_counter++;
		}
		if(isupper(raw[i]))
		{
			pionki_biale.push_back(tolower(raw[i]));
			bierek_counter++;
		}
	}

	sort(pionki_biale.begin(), pionki_biale.end());
	sort(pionki_czarne.begin(), pionki_czarne.end());

	if (pionki_biale == pionki_czarne)
	{
		return_code = "1" + to_string(bierek_counter);
	}
	else
	{
		return_code = "0" + to_string(bierek_counter);
	}


	return return_code;


}

int main(void)
{
	fstream base_file;
	base_file.open("szachy_przyklad.txt", ios::in);

	//global variables
	int num_of_boards = 1;

	//question variables
	int min_bierki = INT_MAX;
	int ile_rownowag = 0;
	string ilosc_bierek = "";
	int local_bierki = 0;

	//loop variables
	int board_limiter = 1;
	string line;
	string board_raw = "";
	string return_code;



	while (!base_file.eof())
	{
		base_file >> line;

		//printf("%s \n", line.c_str());

		board_raw += line;

		if (board_limiter == 8) //if next board
		{
			//printf("\n%i In raw: %s \n\n", num_of_boards, board_raw.c_str());


			return_code = rownowaga(board_raw); 

			if (return_code[0] == '1')
			{
				ile_rownowag++;
				
			}

			for (int i = 1; i < return_code.length(); i++) //zczytywanie wszystkich cyferek po za 1 z return code
			{
				ilosc_bierek += return_code[i];
			}

			local_bierki = stoi(ilosc_bierek.c_str()); //konwersja na int

			if (min_bierki > local_bierki)
			{
				min_bierki = local_bierki;
			}

			//question settings
			ilosc_bierek = "";
			local_bierki = 0;

			//general settings
			num_of_boards++;
			board_limiter = 1;
			board_raw = "";
		}
		else
		{
			board_limiter++;
		}

	}

	cout << "W " << ile_rownowag << " planszach byla rownowaga, najmniejsza ilosc bierek wynosi: " << min_bierki;

	base_file.close();
}
