#include <iostream>
#include "Header.h"

int ModuleFuelReq(int mass);
int FuelFuelReq(int &mass);
int Compare(int arr[]);

int main()
{
	int Fuel[100];
	int *toFuel = Fuel;
	int comp;
	int *pointer = ReturnMass();
	int totalMass = 0;
	for (int i = 0; i < 100; i++)
	{
		totalMass += ModuleFuelReq(pointer[i]);
		Fuel[i] = ModuleFuelReq(pointer[i]);
	}
	comp = Compare(toFuel);

	std::cout << totalMass << std::endl;
	int counter = 0;
	bool isOver = false;
	while (!isOver)
	{
		totalMass += FuelFuelReq(toFuel[counter++]);
		if (counter == 100)
		{
			counter = 0;
		}
		if (Fuel[comp] == 0)
		{
			for (int i = 0; i < 100; i++)
				totalMass += FuelFuelReq(toFuel[i]);
			isOver = true;
		}
	}
	std::cout << std::endl << totalMass << std::endl;
}

int ModuleFuelReq(int mass) //How much fuel does one module require
{
	return ((mass / 3) - 2);
}

int FuelFuelReq(int &mass) //How much fuel does fuel require rooDerp <- if x < 0 x = 0
{
	mass = (mass / 3) - 2;
	if (mass < 0)
		return (mass = 0);
	else
		return mass;
}

int Compare(int arr[])
{
	int a = 0, b = 1;
	for (int i = 0; i < 99; i++)
	{
		//std::cout << "arr[" << a << "] ? arr[" << b << "]\n";
		if (arr[a] >= arr[b])
		{
			if (a > b)
			{
				b = a + 1;
			}
			else if (a == b)
			{
				b++;
			}
			else if (a < b)
			{
				b++;
			}
		}
		else if (arr[a] < arr[b])
		{
			if (a < b)
				a = b + 1;
			else if (a == b)
				a++;
			else if (a > b)
				a++;
		}
	}
	if (a > 99)
		a = 99;
	if (b > 99)
		b = 99;
	return (arr[a] > arr[b] ? a : b);
}