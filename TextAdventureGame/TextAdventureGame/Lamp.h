#pragma once
#include <iostream>
#include "Item.h"

class Lamp : public Item
{
public:
	Lamp();
	void Description() override;
	void Use();

private:
	bool turnedOn;
};

