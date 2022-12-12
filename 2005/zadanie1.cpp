#include <iostream>
#include <vector>
#include <algorithm>

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


int main(void)
{
	vector<int>numbers = { 1, -2, 2, 2, 2, -5, 3, 3, 1, -3 };
	cout << "Best Sum: " << kadane_stuff(numbers);

}
