#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Player.h"

using namespace std;
/*used to create the projectiles used by the player and aliens*/
class projectile
{
private:
	sf::Sprite m_projectileSprite;
	sf::Texture m_projectileTexture;
	bool m_isActive;

public:
	projectile();
	projectile(const int projectileID, float speed);
	void setLocation(float posx, float posy);
	void kill();
	bool isAlive();
	void spawn(bool b_project);
	sf::Sprite & getSprite();
	void drawProjectile(sf::RenderWindow &window);
};