#pragma once
#include <iostream>
#include "Item.h"

class Empty : public Item
{
public:
	Empty();
	void Description() override;
	void Use();
};

