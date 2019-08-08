#include "Snake.hpp"
#include <iostream>


namespace Sagar
{
		Snake::Snake(GameDataRef data) :_data(data)
		{
				snakeHead.setTexture(_data->assets.GetTexture("snakeHead"));
				snakeHead.setPosition(_data->window.getSize().x/2,_data->window.getSize().y/2 - snakeHead.getGlobalBounds().height/2);
				snakeHead.setScale(sf::Vector2f(0.5f, 0.5f));

				snakeHead.setOrigin(snakeHead.getGlobalBounds().width/3*2,snakeHead.getGlobalBounds().height/3*4);
				snakeHeadDirection= UP;
		}
		void Snake::Draw()
		{
				_data->window.draw(snakeHead);
		}

		void Snake::Rotate(int newDirection){
				if(snakeHeadDirection == 4 && newDirection == 1){
						snakeHead.rotate(90.0f);
						snakeHeadDirection = newDirection;
				}
				if(snakeHeadDirection == 1 && newDirection == 4){
						snakeHead.rotate(-90.0f);
						snakeHeadDirection = newDirection;
				}
				else if(newDirection==snakeHeadDirection+1)
				{
						snakeHead.rotate(90.0f);
						snakeHeadDirection = newDirection;
				}
				else if (newDirection==snakeHeadDirection -1)
				{
						snakeHead.rotate(-90.0f);
						snakeHeadDirection = newDirection;
				}
		}

		void Snake::Update()
		{
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
						Rotate(LEFT);
				}
				else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
						Rotate(RIGHT);
				}
				else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
						Rotate(DOWN);
				}
				else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
						Rotate(UP);
				}



				if(snakeHeadDirection == 1)
				{
						snakeHead.move(0,SPEED*-1);
						if(snakeHead.getPosition().y<=0)
								snakeHead.setPosition(snakeHead.getPosition().x,0);
				}
				else if (snakeHeadDirection == 2)
				{
						snakeHead.move(SPEED*1,0);
						if(snakeHead.getPosition().x>=(SCREEN_WIDTH-snakeHead.getGlobalBounds().width/2))
						{
								snakeHead.setPosition(SCREEN_WIDTH-snakeHead.getGlobalBounds().width/2,snakeHead.getPosition().y);
						}
				}
				else if (snakeHeadDirection == 3)
				{
						snakeHead.move(0,SPEED*1);
						if(snakeHead.getPosition().y>=(SCREEN_HEIGHT-snakeHead.getGlobalBounds().height))
						{
								snakeHead.setPosition(snakeHead.getPosition().x,SCREEN_HEIGHT-snakeHead.getGlobalBounds().height);
						}
				}
				else if (snakeHeadDirection == 4)
				{
						snakeHead.move(SPEED*-1,0);
						if(snakeHead.getPosition().x<=0)
								snakeHead.setPosition(0,snakeHead.getPosition().y);
				}
		}

}

