#include "Snake.hpp"
/* #include "DEFINATIONS.hpp" */
#include <iostream>


namespace Sagar
{
		Snake::Snake(GameDataRef data) :_data(data)
		{
				snakeHead.setTexture(_data->assets.GetTexture("snakeHead"));

				snakeHead.setPosition(_data->window.getSize().x/2,_data->window.getSize().y/2 - snakeHead.getGlobalBounds().height/2);
				snakeHead.setScale(sf::Vector2f(0.5f, 0.5f));

				snakeHeadDirection= DOWN;
		}
		void Snake::Draw()
		{
				_data->window.draw(snakeHead);
		}

		void Snake::Update()
		{
				if(snakeHeadDirection == 1)
				{
						snakeHead.move(0,SPEED*-1);
						if(snakeHead.getPosition().y<=0)
								snakeHead.setPosition(snakeHead.getPosition().x,0);
				}
				else if (snakeHeadDirection == 2)
				{
						snakeHead.move(SPEED*1,0);
						if(snakeHead.getPosition().x>=(SCREEN_WIDTH-snakeHead.getGlobalBounds().width))
						{
								snakeHead.setPosition(SCREEN_WIDTH-snakeHead.getGlobalBounds().width,snakeHead.getPosition().y);
						}
				}
				else if (snakeHeadDirection == 3)
				{
						snakeHead.move(0,SPEED*1);
						if(snakeHead.getPosition().y>=(SCREEN_HEIGHT-snakeHead.getGlobalBounds().height*2))
						{
								snakeHead.setPosition(snakeHead.getPosition().x,SCREEN_HEIGHT-snakeHead.getGlobalBounds().height*2);
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

