#include "Header.h"
#include<iostream>
#include <fstream>

int *ReturnMass()
{
	int a;
	int i = 0;
	int masses[255];
	int *ptrToMass = masses;

	std::ifstream reader("mass.txt");
	if (!reader)
	{
		std::cout << "Couldn't open 'mass.txt'\n";
		exit(1);
	}
	while (reader >> a)
	{
		//std::cout << "Iteration: " << i << std::endl;
		masses[i] = a;
		i++;
	}
	reader.close();
	return ptrToMass;
}