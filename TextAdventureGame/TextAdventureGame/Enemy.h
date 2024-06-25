#pragma once
#include <iostream>
#include "Item.h"

class Enemy : public Item
{
public:
	Enemy();
	void Description() override;
	void Use();
};

