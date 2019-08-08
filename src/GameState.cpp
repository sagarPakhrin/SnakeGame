#include <sstream>
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "DEFINATIONS.hpp"
#include <iostream>

namespace Sagar
{
		GameState::GameState(GameDataRef data): _data(data)
		{

		}

		void GameState::Init()
		{
				_data->assets.LoadTexture("Game Background",GAME_TITLE_FILEPATH);
				_data->assets.LoadTexture("snakeHead",SNAKE_HEAD_FILE_PATH);

				_background.setTexture(this->_data->assets.GetTexture("Game Background"));

				snake = new Snake(_data);
		}

		void GameState::HandleInput()
		{
				sf::Event event;
				while(_data->window.pollEvent(event))
				{
						if(sf::Event::Closed == event.type)
						{
								_data->window.close();
						}
				}
		}


		void GameState::Update(float dt)
		{
				snake->Update();
		}

		void GameState::Draw(float dt)
		{
				_data->window.clear(sf::Color(255,255,255));
				_data->window.draw(_background);

				snake->Draw();
				_data->window.display();
		}
}
