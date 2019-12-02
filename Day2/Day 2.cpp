#include <iostream>
#include <vector>

int calculate(int first, int second, int third, std::vector<int> arr);

int main()
{
	int all, a, b;
	std::vector<int> nums = { 1,0,0,3,1,1,2,3,1,3,4,3,1,5,0,3,2,6,1,19,1,5,19,23,2,6,23,27,1,27,5,31,2,9,31,35,1,5,35,39,2,6,39,43,2,6,43,47,1,5,47,51,2,9,51,55,1,5,55,59,1,10,59,63,1,63,6,67,1,9,67,71,1,71,6,75,1,75,13,79,2,79,13,83,2,9,83,87,1,87,5,91,1,9,91,95,2,10,95,99,1,5,99,103,1,103,9,107,1,13,107,111,2,111,10,115,1,115,5,119,2,13,119,123,1,9,123,127,1,5,127,131,2,131,6,135,1,135,5,139,1,139,6,143,1,143,6,147,1,2,147,151,1,151,5,0,99,2,14,0,0 };
	std::vector<int> copy = nums;
	all = nums.size();
	copy[1] = 12;
	copy[2] = 2;

	for (int i = 0; i < all; i += 4)
	{
		if (copy[i] == 99)
		{
				goto exit1;//break;
		}
		else
		{
			copy[copy[i + 3]] = calculate(copy[i], i + 1, i + 2, copy);
		}
	}
exit1:
	std::cout << "First: " << copy[0] << std::endl;

	copy = nums;
	for (int j = 1; j < 100; j++)
	{
		for (int k = 1; k < 100; k++)
		{
			copy = nums;
			a = j;
			b = k;
			nums[1] = a;
			nums[2] = b;
			for (int i = 0; i < all; i += 4)
			{
				if (copy[i] == 99)
				{
					goto exit2;//break;
				}
				else
				{
					copy[copy[i + 3]] = calculate(copy[i], i + 1, i + 2, copy);
				}
			}
		exit2:
			if (copy[0] == 19690720)
			{
				goto exit4;
			}
			else
			{ }
		}
	}
exit4:
		std::cout << "Second: "<< 100 * copy[1] + copy[2];
}

int calculate(int first, int second, int third, std::vector<int> arr)
{
	int val = 0;
	switch (first)
	{
	case 1:
		val = arr[arr[second]] + arr[arr[third]];
		break;

	case 2:
		val = arr[arr[second]] * arr[arr[third]];
		break;

	default:
		std::cout << "ERROR\n";
		break;
	}

	return val;
}
