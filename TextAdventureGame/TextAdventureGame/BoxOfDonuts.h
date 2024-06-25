#pragma once
#include <iostream>
#include "Item.h"

class BoxOfDonuts : public Item
{
public:
	BoxOfDonuts();
	void Description() override;
	void Use();
	void DonutGenerator();

private:
	int count;
};

