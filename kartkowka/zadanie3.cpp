#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

/*
	Calosc opiera sie na rozbiciu podnoszenia potegi i robienia modulo na dwie funkcje
	mozna by bylo zapisac calosc w jednej funkcji korzystajac z gotowych funkcji ale 
	taki program jest mniej optymalny, wiec rozbicie przyspieszy calosc.

	funkcja 'metoda' wykonuje to o co nas prosza w zadaniu, podnosimy 'a' do 'x' jednoczesnie
	liczac modulo z 'M' 

	funkcja 'czy_mozliwe' jedynie sprawdza czy wartosc z 'metoda' jest rowna naszemu 'b'
*/


inline int metoda(int num1, int num2, int num3) 
{
	//num 1 - to jest a
	//num 2 - to jest i z drugiej funkcji
	//num 3 - to jest M

	int w = num1; //zrobienie kopii 'a' na ktorej bedzie mozna bazowac

	for (int i = 1; i < num2; i++) //petla ma sie obrocic tyle razy do ktorej ma byc podniesiona liczba w poprzedniej funkcji
	{
		w = (w * num1) % num3; //liczba sie podnosi do potegi zarazem robiac mod z 'M'
	}
	return w;
}

inline bool czy_mozliwe(int M, int a, int b)
{
	unsigned long long potega;
	
	for (int i = 1; i < M; i++)
	{
		if (metoda(a, i, M) == b) //jesli potega do 'i' liczby 'a' przez modulo 'M' wynosi 'b'
		{
			return true;
		}
	}
	return false;
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

		if (czy_mozliwe(M, a,b))
		{
			counter++;
		}
	}

	printf("%i", counter);

}
