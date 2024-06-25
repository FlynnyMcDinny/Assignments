#include "Room.h"
#include "Item.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>

using namespace std;

Room::Room(string descript, Item* item1)
{
	description = descript;
	item = item1;
}

Room::~Room()
{
	
}

void Room::Description() const
{
	cout << description;
	item->Description();
}

void Room::RoomGenerator() 
{
	itemnum = item->ItemNumber();
	roomnum = RoomNumber();
	string inum = to_string(itemnum);
	string rnum = to_string(roomnum);
	description = roomD[roomnum];
	if (itemnum == 0) 
	{
		boxofdonuts.DonutGenerator();
		item = &boxofdonuts;
	}
	else if (itemnum == 1)
	{
		item = &cat;
	}
	else if (itemnum == 2)
	{
		item = &lamp;
	}
	else if (itemnum == 3)
	{
		item = &shotgun;
	}
	else if (itemnum == 4)
	{
		item = &empty;
	}
	else if (itemnum == 5)
	{
		item = &enemy;
	}
}

int Room::RoomNumber() 
{
	int x = time(0);
	srand(x);
	int random = rand() % 9;
	return random;
}

