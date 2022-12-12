#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

inline int kadane_stuff(vector<int>array_lol)
{
	int local_sum = 0;
	int max_sum = 0;

	for (auto i : array_lol)
	{
		local_sum += i;

		if (local_sum < 0)
		{
			local_sum = 0;
		}
		if (local_sum > max_sum)
		{
			max_sum = local_sum;
		}
	}

	return max_sum;
}


int main()
{
	vector<int>numbers;
	
	fstream base_file;
	base_file.open("dane5-2.txt", ios::in);

	int numb;

	while(!base_file.eof())
	{
		base_file >> numb;
		numbers.push_back(numb);
	}

	cout << "Best Sum: " << kadane_stuff(numbers);
}
