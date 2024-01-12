#include "soundManager.h"

soundManager::soundManager()
{

}

soundManager::soundManager(string filename)
{
	if (!m_soundBuff.loadFromFile(".\\assets\\sounds\\" + filename))
	{
		std::cout << "failed to load sound" << endl;
	}

	m_soundPlay.setBuffer(m_soundBuff);
}

void soundManager::playSound()
{
	m_soundPlay.play();
}