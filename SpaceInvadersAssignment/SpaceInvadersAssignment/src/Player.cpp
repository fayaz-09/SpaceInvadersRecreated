#include "Player.h"

Player::Player()
{
	
}

Player::Player(std::string Filename)
{
	if (!m_PlayerTexture.loadFromFile(".\\assets\\images\\" + Filename))
	{
		std::cout << "Texture not found";
	}
	m_PlayerSprite.setTexture(m_PlayerTexture);
	m_PlayerSprite.setPosition(m_PlayerxPosition, 900);
	m_PlayerSprite.setOrigin(30.0f, 16.0f);
	m_PlayerSprite.scale(sf::Vector2f(0.7, 0.7));

	m_playerisAlive = true;
	m_PlayerLives = 3;


}

void Player::drawPlayer(sf::RenderWindow &window)
{

	window.draw(m_PlayerSprite);

}

void Player::movePlayer(sf::RenderWindow &window, char direction)
{
	if (direction == 'r')
	{
		if (m_PlayerSprite.getPosition().x <= window.getSize().x - m_PlayerSprite.getGlobalBounds().width)
		{
			m_PlayerSprite.move(10, 0);
		}
	}
	if (direction == 'l')
		if (m_PlayerSprite.getPosition().x >= 0 + m_PlayerSprite.getGlobalBounds().width)
		{
			m_PlayerSprite.move(-10, 0);
		}
}

void Player::loseLife()
{
	if (m_PlayerLives > 0)
	{
		m_PlayerLives--;
	}
	else
	{
		destroyPlayer();
	}
}

void Player::destroyPlayer()
{
	m_playerisAlive = false;
}

bool Player::isPlayerAlive()
{
	return m_playerisAlive;
}

int Player::getPlayerLives()
{
	return m_PlayerLives;
}

void Player::restartPlayer()
{
	m_PlayerLives = 3;
	m_playerisAlive = true;
	m_PlayerSprite.setPosition(m_PlayerxPosition, 900);
}

sf::Sprite & Player::getSprite()
{
	return m_PlayerSprite;
}