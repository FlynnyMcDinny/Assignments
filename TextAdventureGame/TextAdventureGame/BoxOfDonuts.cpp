#include "BoxOfDonuts.h"
#include <iostream>
#include <string>
using namespace std;

BoxOfDonuts::BoxOfDonuts()
{
}

void BoxOfDonuts::Description()
{	
	string donuts = std::to_string(count);
	cout << "has a box of donuts with " + donuts + " donuts in it." << endl;
}

void BoxOfDonuts::Use()
{	
	if (count > 0)
	{		
		count -= 1;
		std::string donuts = std::to_string(count);
		cout << "You eat a donut out of the box, there are now " + donuts + " donuts in it." << endl;
	}
	else
	{
		cout << "There aren't any donuts in the box." << endl;
	}
}

void BoxOfDonuts::DonutGenerator()
{
	int x = time(0) * 0.75;
	srand(x);
	count = rand() % 13;
}
