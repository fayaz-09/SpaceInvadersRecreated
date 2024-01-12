#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include "player.h"
#include "alien.h"
#include "alienManager.h"
#include "projectile.h"
#include "collision.h"
#include "blockade.h"
#include "soundManager.h"

using namespace std;

int main()
{
	/*setting up the various variables needed*/
	const int i_numofAliens = 60;
	const float f_projectileSpeed = 10.f;
	bool gameOver = false;
	bool winner = false;
	int iScore = 0;

	/*setting up the window size*/
	sf::RenderWindow window(sf::VideoMode(1300, 1000), "SMFL window.", sf::Style::Default);

	window.setPosition(sf::Vector2i(200, 10));

	window.setFramerateLimit(60);

	/*the following are creating objects of the soundmanager class to load in the sounds being used for the game*/
	soundManager shipFire("ShipBullet.wav");
	soundManager alienFire("InvaderBullet.wav");
	soundManager shipHit("ShipHit.wav");
	soundManager alienHit("InvaderHit.wav");

	/*clock used for timing the movement of the aliens*/
	sf::Clock timer;

	/*clock used for timing the movement of both alien and player projectiles*/
	sf::Clock projectileClock;
	projectileClock.restart().asSeconds();

	projectile projectile1(0, f_projectileSpeed);
	projectile enemyprojectile(0, f_projectileSpeed);

	/*creating a player object*/
	Player player1("ship.png");

	/*creating an object of the alienManager class, this will handle all the functions for controlling the aliens*/
	alienManager spaceAliens;

	/*creating the blockades*/
	blockade protect1(100, window);
	blockade protect2(400, window);
	blockade protect3(700, window);
	blockade protect4(1000, window);

	/*the following is used to load the font, i then assign this font to various text that is being used for the game*/
	sf::Font spaceFont;
	if (!spaceFont.loadFromFile(".\\assets\\fonts\\unifont.TTF"))
	{
		std::cout << "Failed to load font" << endl;
	}

	/*text used to display the players score*/
	sf::Text scoreLabel;
	scoreLabel.setFont(spaceFont);
	scoreLabel.setPosition(1000, 50);
	scoreLabel.setString("Score: " + to_string(iScore));
	scoreLabel.setCharacterSize(24);
	scoreLabel.setFillColor(sf::Color::White);

	/*text used to display the players lives*/
	sf::Text livesLabel;
	livesLabel.setFont(spaceFont);
	livesLabel.setPosition(100, 50);
	livesLabel.setString("Lives: " + to_string(player1.getPlayerLives()));
	livesLabel.setCharacterSize(24);
	livesLabel.setFillColor(sf::Color::White);

	/*text used to display a game over message*/
	sf::Text gameOverLabel;
	gameOverLabel.setFont(spaceFont);
	gameOverLabel.setPosition(500, 400);
	gameOverLabel.setString("Game Over");
	gameOverLabel.setCharacterSize(70);
	gameOverLabel.setFillColor(sf::Color::White);

	/*text used to display if the player won or not*/
	sf::Text winLabel;
	winLabel.setFont(spaceFont);
	winLabel.setPosition(500, 500);
	winLabel.setString("");
	winLabel.setCharacterSize(60);
	winLabel.setFillColor(sf::Color::White);

	/*text used to display to the player they can click to restart the game*/
	sf::Text clickLabel;
	clickLabel.setFont(spaceFont);
	clickLabel.setPosition(300, 600);
	clickLabel.setString("Click anywhere on screen to restart");
	clickLabel.setCharacterSize(50);
	clickLabel.setFillColor(sf::Color::White);

	while (window.isOpen())
	{
		// check all user events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// User has pressed the close button
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			/*the following will check to see if the mouse button has been pressed. if it has and the game is over the game will restart*/
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (gameOver)
				{
					winner = false;
					gameOver = false;
					iScore = 0;
					spaceAliens.restart();
					player1.restartPlayer();
					protect1.restartBlockade();
					protect2.restartBlockade();
					protect3.restartBlockade();
					protect4.restartBlockade();
					scoreLabel.setString("Score: " + to_string(iScore));
					livesLabel.setString("Lives: " + to_string(player1.getPlayerLives()));
				}
			}

			if (event.type == sf::Event::KeyPressed)
			{
				/*the following is used to check for the various player inputs*/
				if (event.key.code == sf::Keyboard::Right) player1.movePlayer(window, 'r');
				if (event.key.code == sf::Keyboard::Left) player1.movePlayer(window, 'l');

				if (event.key.code == sf::Keyboard::Space)
				{
					if (!projectile1.isAlive() && player1.isPlayerAlive())
					{
						projectile1.spawn(true);
						projectile1.setLocation(player1.getSprite().getPosition().x, player1.getSprite().getPosition().y);
						shipFire.playSound();
					}
				}
			}
		}

		sf::Time elapsedTime = timer.getElapsedTime();

		if (elapsedTime.asSeconds() > 1.0f)
		{
			/*the follwing two functions belong to the alienManager class and will change the aliens sprite and move them*/
			spaceAliens.changeState();
			spaceAliens.moveAliens(window);

			int rand1 = rand() % 10;
			int rand2 = rand() % 6;

			/*the following is used to get a random liivng alien and have them fire at the player*/
			if (!enemyprojectile.isAlive() && spaceAliens.getAlienSwarm(rand1, rand2).alienIsAlive())
			{
				enemyprojectile.spawn(true);
				enemyprojectile.setLocation(spaceAliens.getAlienSwarm(rand1, rand2).getAlienSprite().getPosition().x, spaceAliens.getAlienSwarm(rand1, rand2).getAlienSprite().getPosition().y);
				alienFire.playSound();
			}

			timer.restart();
		}



		window.clear(sf::Color::Black);

		
		sf::Time projectElapsedTime = projectileClock.getElapsedTime();

		/*the following will check to see if a projectile is alive and allow it to travel*/
		if (projectElapsedTime.asSeconds() > 1.0)
		{
			if (projectile1.isAlive())
			{
				projectile1.drawProjectile(window);
				projectile1.getSprite().move(0.f, -20);
			}

			if (enemyprojectile.isAlive())
			{
				enemyprojectile.drawProjectile(window);
				enemyprojectile.getSprite().move(0.f, 10);
			}
		}

		/*the following for loop is used to check if an alien has been hit by a player projectile*/
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				Alien alien2;
				alien2 = spaceAliens.getAlienSwarm(i, j);

				if (collision::collidesWith(projectile1, alien2) && spaceAliens.getAlienSwarm(i,j).alienIsAlive() && projectile1.isAlive())
				{
					/*since the alien has been hit the projectile and alien need to dissapear and a sound is also played*/
					spaceAliens.killAlien(i, j);
					projectile1.kill();
					alienHit.playSound();
					iScore = iScore + 100;
					scoreLabel.setString("Score: " + to_string(iScore));
				}

				if (spaceAliens.getAlienSwarm(i, j).getAlienSprite().getPosition().y >= window.getSize().y - 50)
				{
					player1.loseLife();
					spaceAliens.getAlienSwarm(i, j).destroyAlien();
				}
			}
		}

		/*checking to see if the player has been hit by an enemy projectile*/
		if (collision::collidesWith(player1, enemyprojectile) && player1.isPlayerAlive() && enemyprojectile.isAlive())
		{
			player1.loseLife();
			enemyprojectile.kill();
			shipHit.playSound();
			livesLabel.setString("Lives: " + to_string(player1.getPlayerLives()));
			if (player1.getPlayerLives() == 0)
			{
				gameOver = true;
			}
		}

		/*The following are checking to see if the four blockades have been hit by an enemy or player projectile*/
		if (collision::collidesWith(protect1, enemyprojectile) && protect1.isblockadeAlive() && enemyprojectile.isAlive())
		{
			protect1.blockadeloseLife();
			enemyprojectile.kill();
		}
		else if (collision::collidesWith(protect1, projectile1) && protect1.isblockadeAlive() && projectile1.isAlive())
		{
			projectile1.kill();
		}

		if (collision::collidesWith(protect2, enemyprojectile) && protect2.isblockadeAlive() && enemyprojectile.isAlive())
		{
			protect2.blockadeloseLife();
			enemyprojectile.kill();
		}
		else if (collision::collidesWith(protect2, projectile1) && protect2.isblockadeAlive() && projectile1.isAlive())
		{
			projectile1.kill();
		}

		if (collision::collidesWith(protect3, enemyprojectile) && protect3.isblockadeAlive() && enemyprojectile.isAlive())
		{
			protect3.blockadeloseLife();
			enemyprojectile.kill();
		}
		else if (collision::collidesWith(protect3, projectile1) && protect3.isblockadeAlive() && projectile1.isAlive())
		{
			projectile1.kill();
		}

		if (collision::collidesWith(protect4, enemyprojectile) && protect4.isblockadeAlive() && enemyprojectile.isAlive())
		{
			protect4.blockadeloseLife();
			enemyprojectile.kill();
		}
		else if (collision::collidesWith(protect4, projectile1) && protect4.isblockadeAlive() && projectile1.isAlive())
		{
			projectile1.kill();
		}

		
		/*when the players projectile goes off screen this will disable it and allow the player to shoot again*/
		if (projectile1.getSprite().getPosition().y < 0)
		{
			projectile1.kill();
		}

		/*used to disable an enemy projectile when it goes off screen*/
		if (enemyprojectile.getSprite().getPosition().y >= window.getSize().y)
		{
			enemyprojectile.kill();
		}

		int i_deadAliens = 0;

		/*used to check if all the aliens have been killed by checking how many are not alive and comparing to the total number of aliens*/
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (!spaceAliens.getAlienSwarm(i, j).alienIsAlive())
				{
					i_deadAliens++;
				}

				/*if the 2 values are equal it means the player has destroyed all the aliens and has won*/
				if (i_deadAliens == i_numofAliens)
				{
					if (!gameOver)
					{
						winner = true;
						gameOver = true;
					}
				}
			}
		}

		/*the following is used to draw all the various aspects of the game to the window*/
		if (!gameOver)
		{
			if (player1.isPlayerAlive())
			{
				player1.drawPlayer(window);
			}

			spaceAliens.drawAliens(window);

			if (protect1.isblockadeAlive())
			{
				protect1.drawBlockade(window);
			}

			if (protect2.isblockadeAlive())
			{
				protect2.drawBlockade(window);
			}

			if (protect3.isblockadeAlive())
			{
				protect3.drawBlockade(window);
			}

			if (protect4.isblockadeAlive())
			{
				protect4.drawBlockade(window);
			}

			window.draw(scoreLabel);
			window.draw(livesLabel);

			window.display();
		}
		else
		{
			player1.destroyPlayer();
			spaceAliens.destroyAll();

			if (winner)
			{
				winLabel.setString("You win!");
			}
			else
			{
				winLabel.setString("You Lose!");
			}

			window.draw(gameOverLabel);
			window.draw(scoreLabel);
			window.draw(livesLabel);
			window.draw(winLabel);
			window.draw(clickLabel);

			window.display();
		}

	}

	return 0;
}