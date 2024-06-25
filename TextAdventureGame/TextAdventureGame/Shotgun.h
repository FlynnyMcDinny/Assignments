#pragma once
#include <iostream>
#include "Item.h"

class Shotgun : public Item
{
public:
	Shotgun();
	void Description() override;
	int sAmmo = 0;
	std::string ammo;
	bool hasShotgun = false;
};