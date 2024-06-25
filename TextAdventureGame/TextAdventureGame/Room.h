#pragma once
#include <iostream>
#include "Item.h"
#include "BoxOfDonuts.h"
#include "Cat.h"
#include "Lamp.h"
#include "Shotgun.h"
#include "Empty.h"
#include "Enemy.h"
class Item;

class Room 
{
public:
	Item* item;
	BoxOfDonuts boxofdonuts;
	Cat cat;
	Lamp lamp;
	Shotgun shotgun;
	Empty empty;
	Enemy enemy;
	std::string description;
	Room(std::string descript, Item* item);
	~Room();
	void Description() const;
	void RoomGenerator();
	int RoomNumber();
	bool pickedUp = false;
	bool generated = false;
	std::string roomD[9] =
	{ "You enter a cold room with two dim lights, cascading over the fog that fills the room. The room ",
		"The room you've entered surpisingly looks like a living room. There are childrens toys on the ground, and a tv on a wall. The living room ",
		"This room is ominously styled like a childs bedroom, there is a racing car bed and odd crayon drawings on the walls. The bedroom ",
		"You enter a room, the walls constructed of wooden boards that look like they've been here a while. Through the cracks you can see a unsettlingly fake looking farm. You appear to be inside a barn with hay scattered everywhere. The barn ",
		"You walk into an area with bright pink and blue lights, there is a large window showing immense amounts of highrise buildings. There are holographic images all around them and there are some smaller ones in this room. This odd futuristic room ",
		"As you walk in there is a gust of steam that bursts into your face out of a gold pipe. There are rows and rows of these pipes stretching along the walls and ceiling. You turn a valve that shuts off the steam that just hit you, as you look around the room you realise it ",
		"This room you've entered is covered in pastel pink walls and cinnamoroll merchandise. There is a desk with three pink monitors on it, you turn around and sees that the room ",
		"As you enter the room, you smell a revolting stench, you look around the room and notice all the walls are covered in posters of cartoon looking woman. You also see a bed that has multiple pillows that are quite long that also have woman on them. You search the rest of the room and see that it ",
		"At the entrance of the room there is an aged wooden table with what seems to be old family photos. Further into the room there is a loud grand father clock and a couple of chairs nearby it with floral patterns on the cushions. This old looking room " };	
	int roomnum = 0;
	int itemnum = 0;
private:

public:

	Room() = default;
};

