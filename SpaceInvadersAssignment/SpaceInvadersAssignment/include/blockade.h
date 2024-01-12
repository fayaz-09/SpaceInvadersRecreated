#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

using namespace std;
/*class used to create the blockades*/
class blockade
{
private:
	int m_BlockadeLives;
	sf::Sprite m_BlockadeSprite;
	sf::Texture m_BlockadeTexture;
	sf::Texture m_BlockadeTexture2;
	sf::Texture m_BlockadeTexture3;
	bool m_blockadeisAlive;

public:
	blockade();
	blockade(float posx, sf::RenderWindow &window);
	void drawBlockade(sf::RenderWindow &window);
	void blockadeloseLife();
	void destroyblockade();
	bool isblockadeAlive();
	void restartBlockade();
	sf::Sprite & getSprite();

};