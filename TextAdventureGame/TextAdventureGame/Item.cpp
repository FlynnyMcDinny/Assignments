#include "Item.h"

using namespace std;

void Item::Description() 
{
	cout << "DIDN'T WORK FIX IT" << endl;
}

void Item::Use()
{

}

int Item::ItemNumber()
{
	int x = time(0) * 0.65;
	srand(x);
	int item = rand() % 6;
	return item;
}
