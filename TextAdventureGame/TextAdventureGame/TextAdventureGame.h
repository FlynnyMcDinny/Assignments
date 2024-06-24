#pragma once
#include <iostream>
#include "Room.h"
#include "Player.h"

class TextAdventureGame
{
public:
	void Game();
	Player player;
	Room room;
	Room rooms[3][3] = {
	{Room(rooms[0][0].description,room.item),Room(rooms[0][1].description,room.item),Room(rooms[0][2].description,room.item)},
	{Room(rooms[1][0].description,room.item),Room(rooms[1][1].description,room.item),Room(rooms[1][2].description,room.item)},
	{Room(rooms[2][0].description,room.item),Room(rooms[2][1].description,room.item),Room(rooms[2][2].description,room.item)} };
private:

};

