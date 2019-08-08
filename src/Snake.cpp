#include "Snake.hpp"
#include "DEFINATIONS.hpp"

namespace Sagar
{
		Snake::Snake(GameDataRef data) :_data(data)
		{
				snakeHead.setTexture(_data->assets.GetTexture("snakeHead"));

				snakeHead.setPosition(_data->window.getSize().x/2,_data->window.getSize().y/2 - snakeHead.getGlobalBounds().height/2);
				snakeHead.setScale(sf::Vector2f(0.5f, 0.5f));

				snakeHeadDirection= UP;
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
				}
				else if (snakeHeadDirection == 2)
				{
						snakeHead.move(SPEED*1,0);
				}
				else if (snakeHeadDirection == 3)
				{
						snakeHead.move(0,SPEED*1);
				}
				else
				{
						snakeHead.move(SPEED*-1,0);
				}
		}


}

