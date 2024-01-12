#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "alien.h"

using namespace std;

/*The class used to create an array of the alien class and the control them*/
class alienManager
{
private:
	/*using an array to store the aliens*/
	Alien alienSwarm[10][6];
	sf::Texture alienTexture;
	sf::Texture alienTexture2;
	sf::Texture alienTexture3;
	sf::Texture* p_aTex = &alienTexture;
	sf::Texture* p_aTex2 = &alienTexture2;
	sf::Texture* p_aTex3 = &alienTexture3;
	sf::Texture alienTexturea;
	sf::Texture alienTextureb;
	sf::Texture alienTexturec;
	sf::Texture* p_aTexa = &alienTexturea;
	sf::Texture* p_aTexb = &alienTextureb;
	sf::Texture* p_aTexc = &alienTexturec;
	bool m_moveRight;
	bool aliveBullet;
	bool m_state2;

public:
	alienManager();
	void moveAliens(sf::RenderWindow &window);
	void drawAliens(sf::RenderWindow &window);
	void killAlien(int x,int y);
	void destroyAll();
	void changeState();
	void restart();
	Alien getAlienSwarm(int x, int y);
};