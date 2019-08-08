#include "Snake.hpp"
#include <iostream>


namespace Sagar
{
		Snake::Snake(GameDataRef data) :_data(data)
		{
				snakeHead.setTexture(_data->assets.GetTexture("snakeHead"));
				snakeHead.setPosition(_data->window.getSize().x/2,_data->window.getSize().y/2 - snakeHead.getGlobalBounds().height/2);
				snakeHead.setScale(sf::Vector2f(0.5f, 0.5f));

				body.setTexture(_data->assets.GetTexture("snakeBody"));

				snakeHead.setOrigin(snakeHead.getGlobalBounds().width/3*2,snakeHead.getGlobalBounds().height/3*4);
				snakeHeadDirection= UP;
				snakeLife= 3;
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
						{
								snakeHead.setPosition(snakeHead.getPosition().x,0);
								snakeLife--;
						}
				}
				else if (snakeHeadDirection == 2)
				{
						snakeHead.move(SPEED*1,0);
						if(snakeHead.getPosition().x>=(SCREEN_WIDTH-snakeHead.getGlobalBounds().width/2))
						{
								snakeLife--;
								snakeHead.setPosition(SCREEN_WIDTH-snakeHead.getGlobalBounds().width/2,snakeHead.getPosition().y);
						}
				}
				else if (snakeHeadDirection == 3)
				{
						snakeHead.move(0,SPEED*1);
						if(snakeHead.getPosition().y>=(SCREEN_HEIGHT-snakeHead.getGlobalBounds().height))
						{
								snakeLife--;
								snakeHead.setPosition(snakeHead.getPosition().x,SCREEN_HEIGHT-snakeHead.getGlobalBounds().height);
						}
				}
				else if (snakeHeadDirection == 4)
				{
						snakeHead.move(SPEED*-1,0);
						if(snakeHead.getPosition().x<=0)
						{
								snakeLife--;
								snakeHead.setPosition(0,snakeHead.getPosition().y);
						}
				}
		}

		void Snake::DrawBody()
		{
				for (unsigned short int i=0;i<snakeBody.size() i++)
				{
						_data->window.draw(snakeBody.at(i));
				}
		}

}

