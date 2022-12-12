#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

inline int the_most_freq_ele(int array_[], int len)
{
	int freq_times = 0, freq_element = 0;
	int local = 1;

	for (int i = 0; i < len; i++)
	{
		if (array_[i] == array_[i + 1])
		{
			local++;

		}
		else
		{
			if (local > freq_times)
			{
				freq_times = local;
				freq_element = array_[i];
			}

			local = 1;
		}
	}

	return freq_element;
}


int main()
{
	int numbers[200] = {};
	
	int len_array = sizeof(numbers) / sizeof(numbers[0]);

	fstream base_file;
	base_file.open("dane5-2.txt", ios::in);
	

	for (int i = 0; i < len_array; i++)
	{
		base_file >> numbers[i];
	}
	

	sort(numbers, numbers + len_array);

	cout << "Most Frequent: " << the_most_freq_ele(numbers, len_array);
}
