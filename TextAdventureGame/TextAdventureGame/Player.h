#pragma once
#include <iostream>
#include <list>
#include <vector>

class Player
{
public:
	Player();
	bool BinarySearch(const std::vector<std::string>& arr, const std::string& target);
	std::vector<std::string> spells = { "Eclipse", "Eruption", "Frostbite","Levitate","Mirage","Petrify","Polymorph","Teleport","Thunderwave","Vortex" };
	std::string inventory[6] = { "","","","","","" };
	int x = 0;
	int y = 0;
};

