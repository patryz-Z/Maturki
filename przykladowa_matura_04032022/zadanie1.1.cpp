#include <iostream>
#include <fstream>
#include <string>

using namespace std;

inline bool empty_column(string column)
{
	for (int i = 0; i < column.length(); i++) //przejezdza sie po juz przekonwertowanej tablicy na os Y 
	{
		if (column[i] != '.') //jesli cos nie jest kropka to robi false
		{
			return false;
		}
	}
	return true;
}

string to_column(string raw)
{
	//printf("| %s |\n", raw.c_str());

	string y_axis = ""; //zmienna w ktorej zapisana jest cala os Y
	
	//do zadania 1
	bool empty_board = false;
	int num_of_empty = 0;

	string return_code = ""; //funkcja musi zwracac pare infomacji a nie chce korzystac z globalnych zmiennych w tak malym zadaniu, wiec zwraca ustalony przez tworce kod ktory jest interpretowany potem

	for (int x = 0; x < 8; x++) //8 kolumn
	{
		y_axis = ""; //zmienna z osia Y sie zeruje z uwagi na to ze musi zrobic miejsce dla kolejnej przekonwertowanej osi

		for (int i = 0+x; i < raw.length(); i += 8) //przez cala dlugosc rawu tablicy co 8
		{
			//printf("%c \n", raw[i]);

			y_axis += raw[i]; //dodawanie elementow do osi y
		}
		if (empty_column(y_axis)) //po dodaniu wszystkich elementow do zmiennej 'y_axis' funkcja empty_column sprawdza czy ta kolumna jest pusta
		{
			empty_board = true; 
			num_of_empty++; 
		}

	}

	if (empty_board) //jesli tablica ma pusta kolumne
	{
		return_code = "1" + to_string(num_of_empty); //to ma zwrocic 1+[ilosc pustych]
	}
	else
	{
		return_code = "0"; //brak
	}
	return return_code;

}

int main(void)
{
	fstream base_file;
	base_file.open("szachy.txt", ios::in);

	//global variables
	int num_of_boards = 1;

	//rozne zadania
	int empty_columns = 0;
	int empty_boards_num = 0;
	int max_empty = 0;

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

			return_code = to_column(board_raw);

			if (return_code[0] == '1')
			{
				empty_columns = return_code[1] - 48;
				//cout << "Plansza nr. " << num_of_boards << " jest pusta | " << empty_columns << endl;
				empty_boards_num++;
			}
			else
			{
				//cout << "Plansza nr. " << num_of_boards << " nie jest pusta\n";
			}
			
			if (empty_columns > max_empty)
			{
				max_empty = empty_columns;
			}

			num_of_boards++;
			board_limiter = 1;
			board_raw = "";
		}
		else
		{
			board_limiter++;
		}

	}

	cout << empty_boards_num << " " << max_empty;

	base_file.close();
}
