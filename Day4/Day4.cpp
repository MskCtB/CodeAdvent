#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

int main()
{
	int x;
	int k = 0;
	int convert;
	int pairs[6] = { 0, 0, 0, 0, 0, 0 };
	std::string s;
	s ="000000";
	bool pair = false;
	bool growing = true;
	
	int counter = 0;
	for (int i = 388888; i < 900000; i++) // 388888 | 900000 | 387638; i < 919123
	{
		x = i;
		s = std::to_string(x);
		for (int h = 0; h < 5; h++)
		{
			
			int o = h + 2;
			if (h == 0 && s[h] == s[h + 1])
			{
				if (s[h] != s[o])
				{
					pair = true;
					pairs[k] = h;
					k++;
				}
			}
			if (h > 0 && s[h] == s[h + 1] && s[h] != s[h-1])
			{
				if (s[h] != s[o])
				{
					pair = true;
					pairs[k] = h;
					k++;
				}
				if (o == 6 && s[h] != s[h - 1])
				{

					pair = true;
					pairs[k] = h;
					k++;
				}
			}
		}
		k = 0;
		int slider = 0;
		for (int g = 1; g < 6; g++)
		{
			int y = pow(10, g);
			int y2 = pow(10, g - 1);
			int a = x % y /y2;
			y = pow(10, g + 1);
			int b = x % y / (10 * y2);
			if (a < b)
			{
				growing = false;
			}
			slider++;
		}
		if (pair && growing)
		{
			counter++;
		}
		pair = false;
		growing = true;
	}
	std::cout << "Counter = " << counter << std::endl;
}
