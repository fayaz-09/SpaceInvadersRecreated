#include "alienManager.h"

alienManager::alienManager()
{
	/*loading the different textures for the aliens*/
	alienTexture.loadFromFile(".\\assets\\images\\InvaderA1.png");
	alienTexture2.loadFromFile(".\\assets\\images\\InvaderB1.png");
	alienTexture3.loadFromFile(".\\assets\\images\\InvaderC1.png");

	alienTexturea.loadFromFile(".\\assets\\images\\InvaderA2.png");
	alienTextureb.loadFromFile(".\\assets\\images\\InvaderB2.png");
	alienTexturec.loadFromFile(".\\assets\\images\\InvaderC2.png");

	m_moveRight = true;
	

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (j < 2)
			{
				/*creating and assigning the aliens to the array, a pointer is being used to assign the textures*/
				Alien alien1(*p_aTex3, i, j);
				alienSwarm[i][j] = alien1;
			}
			else if (j < 4)
			{
				Alien alien1(*p_aTex2, i, j);
				alienSwarm[i][j] = alien1;
			}
			else if (j < 7)
			{
				Alien alien1(*p_aTex, i, j);
				alienSwarm[i][j] = alien1;
			}
		}
	}

	m_state2 = true;
}

void alienManager::moveAliens(sf::RenderWindow &window)
{
	if (alienSwarm[9][0].getAlienPositionx() >= window.getSize().x - alienSwarm[9][0].getAlienWidth() && m_moveRight)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				alienSwarm[i][j].alienMovey();
			}
		}
		m_moveRight = false;
	}
	else if (alienSwarm[9][0].getAlienPositionx() >= window.getSize().x - alienSwarm[9][0].getAlienWidth() && !m_moveRight)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				alienSwarm[i][j].alienMove(m_moveRight);
			}
		}
	}
	else if (alienSwarm[0][0].getAlienPositionx() - alienSwarm[0][0].getAlienWidth() < 50 && !m_moveRight)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				alienSwarm[i][j].alienMovey();
			}
		}
		m_moveRight = true;
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				alienSwarm[i][j].alienMove(m_moveRight);
			}
		}
	}
}

void alienManager::drawAliens(sf::RenderWindow &window)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (alienSwarm[i][j].alienIsAlive()) 
			{
				alienSwarm[i][j].drawAlien(window);
			}
		}
	}
}

void alienManager::killAlien(int x,int y)
{	
	alienSwarm[x][y].destroyAlien();
}

void alienManager::destroyAll()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (alienSwarm[i][j].alienIsAlive())
			{
				alienSwarm[i][j].destroyAlien();
			}
		}
	}
}

void alienManager::changeState()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (j < 2)
			{
				if (m_state2)
				{
					alienSwarm[i][j].setAlienTexture(*p_aTexc);
				}
				else
				{
					alienSwarm[i][j].setAlienTexture(*p_aTex3);
				}
			}
			else if (j < 4)
			{
				if (m_state2)
				{
					alienSwarm[i][j].setAlienTexture(*p_aTexb);
				}
				else
				{
					alienSwarm[i][j].setAlienTexture(*p_aTex2);
				}
			}
			else if (j < 7)
			{
				if (m_state2)
				{
					alienSwarm[i][j].setAlienTexture(*p_aTexa);
				}
				else
				{
					alienSwarm[i][j].setAlienTexture(*p_aTex);
				}
			}
		}
	}

	if (m_state2)
	{
		m_state2 = false;
	}
	else
	{
		m_state2 = true;
	}
	
}

/*used to set back to its orignial state when the game is restarted*/
void alienManager::restart()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (j < 2)
			{
				alienSwarm[i][j].setAlienPosition(i, j);
			}
			else if (j < 4)
			{
				alienSwarm[i][j].setAlienPosition(i, j);
			}
			else if (j < 7)
			{
				alienSwarm[i][j].setAlienPosition(i, j);
			}
		}
	}
}

Alien alienManager::getAlienSwarm(int x, int y)
{
	return alienSwarm[x][y];
}