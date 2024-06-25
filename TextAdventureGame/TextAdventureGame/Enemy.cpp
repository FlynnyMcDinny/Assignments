#include "Enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy()
{
}

void Enemy::Description()
{
	cout << "is full of mysterious eldritch creatures lurking and squirming in the dark corners of the room." << endl;
}

void Enemy::Use()
{
	cout << "The creatures hiss and swipe at you as you approach them, you step back not wanting to threaten them." << endl;
}
