#include "projectile.h"

projectile::projectile()
{

}

projectile::projectile(const int projectileID, float speed)
{
	m_isActive = false;

	if (!m_projectileTexture.loadFromFile(".\\assets\\images\\Bullet.png"))
	{
		std::cout << "Texture not found";
	}

	/*m_projectileSprite.scale(sf::Vector2f(0.3, 0.3));*/
}

void projectile::setLocation(float posx,float posy)
{
	m_projectileSprite.setPosition(posx, posy);
}

sf::Sprite & projectile::getSprite()
{
	return m_projectileSprite;
}

void projectile::kill()
{
	m_isActive = false;
}

bool projectile::isAlive()
{
	return m_isActive;
}

void projectile::spawn(bool b_project)
{
	m_isActive = b_project;
}

void projectile::drawProjectile(sf::RenderWindow &window)
{
	m_projectileSprite.setTexture(m_projectileTexture);
	window.draw(m_projectileSprite);
}