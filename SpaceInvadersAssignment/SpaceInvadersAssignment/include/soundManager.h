#pragma once
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <iostream>

using namespace std;
/*used to set up and load sounds into the game to be used at specific points*/
class soundManager
{
private:
	sf::SoundBuffer m_soundBuff;
	sf::Sound m_soundPlay;
public:
	soundManager();
	soundManager(string filename);
	void playSound();
};