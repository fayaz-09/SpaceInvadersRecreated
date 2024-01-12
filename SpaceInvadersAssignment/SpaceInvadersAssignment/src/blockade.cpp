#include "blockade.h"

blockade::blockade()
{

}

blockade::blockade(float posx, sf::RenderWindow &window)
{
	m_BlockadeTexture.loadFromFile(".\\assets\\images\\FullBlock.png");
	m_BlockadeTexture2.loadFromFile(".\\assets\\images\\OkBlock.png");
	m_BlockadeTexture3.loadFromFile(".\\assets\\images\\WeakBlock.png");

	m_BlockadeSprite.setTexture(m_BlockadeTexture);
	m_BlockadeSprite.setPosition(posx, window.getSize().y - 250);

	m_BlockadeSprite.scale(sf::Vector2f(6, 5));

	m_BlockadeLives = 2;
	m_blockadeisAlive = true;
}

void blockade::drawBlockade(sf::RenderWindow &window)
{

	window.draw(m_BlockadeSprite);

}

void blockade::blockadeloseLife()
{
	if (m_BlockadeLives == 2)
	{
		m_BlockadeLives--;
		m_BlockadeSprite.setTexture(m_BlockadeTexture2);
	}
	else if (m_BlockadeLives == 1)
	{
		m_BlockadeLives--;
		m_BlockadeSprite.setTexture(m_BlockadeTexture3);
	}
	else
	{
		destroyblockade();
	}
}

void blockade::destroyblockade()
{
	m_blockadeisAlive = false;
}

bool blockade::isblockadeAlive()
{
	return m_blockadeisAlive;
}

/*used to set back to its orignial state when the game is restarted*/
void blockade::restartBlockade()
{
	m_BlockadeSprite.setTexture(m_BlockadeTexture);
	m_BlockadeLives = 2;
	m_blockadeisAlive = true;
}
sf::Sprite & blockade::getSprite()
{
	return m_BlockadeSprite;
}