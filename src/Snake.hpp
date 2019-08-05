#pragma once
#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include <vector>

namespace Sagar
{
		class Snake
		{
				public:
						Snake(GameDataRef data);
						void DrawSnake();
				private:
						GameDataRef _data;
						sf::Sprite snakeHead;
						sf::Sprite body;
						std::vector<sf::Sprite> snakeBody;
		};
}
