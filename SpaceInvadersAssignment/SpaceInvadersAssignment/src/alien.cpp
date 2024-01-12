#include "Alien.h"


Alien::Alien()
{
	
}

Alien::Alien(sf::Texture& tex, float posx, float posy)
{
	m_alive = true;
	m_alienSprite.setTexture(tex);
	m_alienSprite.setPosition(posx * 80 + 100, posy * 50 + 100);
	m_alienSprite.setOrigin(24.0f, 16.0f);
	m_alienSprite.scale(sf::Vector2f(0.7, 0.7));
}

void Alien::setAlienPosition(float posx, float posy)
{
	m_alive = true;
	m_alienSprite.setPosition(posx * 80 + 100, posy * 50 + 100);
}

float Alien::getAlienPositionx()
{
	return m_alienSprite.getPosition().x;
}

void Alien::alienMove(bool moveRight)
{
	if (moveRight)
	{
		m_alienSprite.move(30, 0);
	}
	else if (!moveRight)
	{
		m_alienSprite.move(-30, 0);
	}
}

void Alien::alienMovey()
{
	m_alienSprite.move(0, 50);
}

float Alien::getAlienWidth()
{
	return m_alienSprite.getGlobalBounds().width;
}

void Alien::destroyAlien()
{
	m_alive = false;
}

bool Alien::alienIsAlive()
{
	return m_alive;
}

void Alien::setAlienTexture(sf::Texture& tex)
{
	m_alienSprite.setTexture(tex);
}

void Alien::drawAlien(sf::RenderWindow &window)
{

	if (m_alive)
	{
		window.draw(m_alienSprite);
	}
}

sf::Sprite Alien::getAlienSprite()
{
	return m_alienSprite;
}