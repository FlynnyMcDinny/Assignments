#include "Lamp.h"
#include <iostream>
using namespace std;

Lamp::Lamp()
{
	int x = time(0) * 0.2;
	srand(x);
	int i = rand() % 2;
	if (i == 1)
	{
		turnedOn = true;
	}
	else if (i == 0)
	{

		turnedOn = false;
	}
}

void Lamp::Description() 
{
	std::string descript;
	if (turnedOn == false)
	{
		cout << "has a lamp in it, the lamp is turned off, making the room a little bit darker." << endl;
	}
	else
	{
		cout << "has a lamp in it, the lamp is turned on, illuminating the room." << endl;
	}
}

void Lamp::Use()
{
	if (turnedOn == false)
	{
		cout << "You turn the lamp on, illuminating the room." << endl;
		turnedOn = true;
	}
	else
	{
		cout << "You turn the lamp off, making the room slightly darker." << endl;
		turnedOn = false;
	}
}
