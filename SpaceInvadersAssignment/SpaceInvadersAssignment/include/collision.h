#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

#include "Player.h"
#include "alien.h"
#include "projectile.h"
#include "blockade.h"

using namespace std;

/*class used for checking collisions between various other classes*/
class collision
{
private:

public:
	static bool collidesWith(projectile &, Alien &);
	static bool collidesWith(Player &, projectile&);
	static bool collidesWith(blockade &, projectile&);
};