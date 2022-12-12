#include <iostream>
#include <fstream>
#include <algorithm>

/*
1. 1
2. 2
3. 3
4. 4
5. 5
6. 6
7. 7
8. 8
9. 9
10. 0
11. A
12. B
13. C
14. D
15. E
16. F
*/




using namespace std;

int main(void)
{
	fstream base_file;
	base_file.open("dane.txt", ios::in);
	
	int even_hex = 0;
	
	string stringer;

	while (!base_file.eof())
	{
		base_file >> stringer;
		if (stringer[stringer.length() - 1] == 'A' or stringer[stringer.length() - 1] == 'C' or stringer[stringer.length() - 1] == 'E')
		{
			even_hex++;
		}
	}


	cout << "Jest: " << even_hex << " slow parzystych w systemie hex";

}
