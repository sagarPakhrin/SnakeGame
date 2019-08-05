#include "Snake.hpp"

namespace Sagar
{
		Snake::Snake(GameDataRef data) :_data(data)
		{}

		void Snake::DrawSnake()
		{
				for (unsigned short int i = 0; i<snakeBody.size(); i++)
				{
						_data->window.draw(snakeBody.at(i));
				}
		}
}
