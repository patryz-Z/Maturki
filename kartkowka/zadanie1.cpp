#include <iostream>
#include <fstream>

using namespace std;

inline bool is_prime(int number)
{
    if (number <= 1)
    {
        return false;
    }

    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
            return false;
    }


    return true;
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

        if (is_prime(M))
        {
            counter++;
        }
    }

    printf("%i", counter);

}
