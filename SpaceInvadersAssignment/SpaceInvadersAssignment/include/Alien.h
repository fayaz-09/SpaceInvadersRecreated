#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>

using namespace std;

/*The class used to create seperate instances of the aliens*/
class Alien
{
private:
	int m_AlienHealth;
	float m_alienPositionx;
	float m_alientPositiony;
	sf::Sprite m_alienSprite;
	sf::Texture m_alienTexture;
	bool m_alive;

public:
	Alien();
	Alien(sf::Texture& tex, float posx, float posy);
	void setAlienPosition(float posx, float posy);
	float getAlienPositionx();
	void alienMove(bool moveRight);
	void alienMovey();
	float getAlienWidth();
	void destroyAlien();
	bool alienIsAlive();
	void setAlienTexture(sf::Texture& tex);
	void drawAlien(sf::RenderWindow &window);
	sf::Sprite getAlienSprite();
	
};

