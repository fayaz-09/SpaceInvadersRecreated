#include "collision.h"

bool collision::collidesWith(projectile &obj1, Alien &obj2)
{
	sf::FloatRect projectile1;

	projectile1.left = obj1.getSprite().getPosition().x + 10;
	projectile1.top = obj1.getSprite().getPosition().y + 10;

	projectile1.width = obj1.getSprite().getGlobalBounds().width;
	projectile1.height = obj1.getSprite().getGlobalBounds().height;

	sf::FloatRect alien1;

	alien1.left = obj2.getAlienSprite().getPosition().x;
	alien1.top = obj2.getAlienSprite().getPosition().y;

	alien1.width = obj2.getAlienSprite().getGlobalBounds().width;
	alien1.height = obj2.getAlienSprite().getGlobalBounds().height;


	return projectile1.intersects(alien1);
}

bool collision::collidesWith(Player &obj1, projectile &obj2)
{
	sf::FloatRect player1;

	player1.left = obj1.getSprite().getPosition().x -10;
	player1.top = obj1.getSprite().getPosition().y;

	player1.width = obj1.getSprite().getGlobalBounds().width;
	player1.height = obj1.getSprite().getGlobalBounds().height;

	sf::FloatRect projectile1;

	projectile1.left = obj2.getSprite().getPosition().x;
	projectile1.top = obj2.getSprite().getPosition().y;

	projectile1.width = obj2.getSprite().getGlobalBounds().width;
	projectile1.height = obj2.getSprite().getGlobalBounds().height;


	return player1.intersects(projectile1);
}

bool collision::collidesWith(blockade &obj1, projectile &obj2)
{
	sf::FloatRect blockade1;

	blockade1.left = obj1.getSprite().getPosition().x;
	blockade1.top = obj1.getSprite().getPosition().y;

	blockade1.width = obj1.getSprite().getGlobalBounds().width;
	blockade1.height = obj1.getSprite().getGlobalBounds().height;

	sf::FloatRect projectile1;

	projectile1.left = obj2.getSprite().getPosition().x;
	projectile1.top = obj2.getSprite().getPosition().y;

	projectile1.width = obj2.getSprite().getGlobalBounds().width;
	projectile1.height = obj2.getSprite().getGlobalBounds().height;


	return blockade1.intersects(projectile1);
}