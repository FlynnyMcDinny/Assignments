#pragma once
#include <iostream>
#include "Item.h"

class Cat : public Item
{
public:
	Cat();
	void Description() override;
	void Use();

private:
	bool purring = true;
};

