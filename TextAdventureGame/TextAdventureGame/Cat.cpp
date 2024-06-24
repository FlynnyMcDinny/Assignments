#include "Cat.h"
#include <iostream>
#include <string>
using namespace std;

Cat::Cat()
{
	int x = time(0) * 0.4;
	srand(x);
	int i = rand() % 2;
	if (i == 1) 
	{
		purring = true;
	}
	else if (i == 0)
	{
		purring = false;
	}
}

void Cat::Description() 
{
	std::string descript;
	if (purring == false) 
	{
		cout << "has a cat in it, the cat looks like its ready to attack." << endl;
	}
	else
	{
		cout << "has a cat in it, the cat is laying down leaving its self open. You approach the cat and can hear that it's purring." << endl;
	}
}

void Cat::Use()
{
	if (purring == false)
	{
		cout << "You go to pet the cat, as your hand approaches it, it attacks your hand with it's claws and scratches you." << endl;
	}
	else
	{
		cout << "You go to pet the cat, as your hand approaches it, it pushes its head into your hand and starts to purr louder." << endl;
	}
}
