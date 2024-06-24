#include "Empty.h"
#include <iostream>

using namespace std;

Empty::Empty()
{
}

void Empty::Description()
{
	cout << "is empty." << endl;
}

void Empty::Use()
{
	cout << "There is nothing in this room." << endl;
}
