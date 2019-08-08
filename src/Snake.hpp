#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINATIONS.hpp"

#include "Game.hpp"
#include <vector>

namespace Sagar
{
		class Snake
		{
				public:
						Snake(GameDataRef data); void Draw();
						void Update();
						void Animate(float dt);
				private:
						GameDataRef _data;
						sf::Sprite snakeHead;
						sf::Sprite body;
						std::vector<sf::Sprite> snakeBody;
						sf::Clock _clock;

						sf::Clock _movementClock;

						float SPEED=1.5f;
						int snakeHeadDirection;

		};
}
