#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

using namespace std;

/*used to create the player controlled ship*/
class Player
{
private:
	int m_PlayerLives;
	sf::Sprite m_PlayerSprite;
	sf::Texture m_PlayerTexture;
	float m_PlayerxPosition = 500;
	bool m_playerisAlive;

public:
	Player();
	Player(std::string Filename);
	void drawPlayer(sf::RenderWindow &window);
	void movePlayer(sf::RenderWindow &window, char direction);
	void loseLife();
	void destroyPlayer();
	bool isPlayerAlive();
	int getPlayerLives();
	void restartPlayer();
	sf::Sprite & getSprite();
	
};
