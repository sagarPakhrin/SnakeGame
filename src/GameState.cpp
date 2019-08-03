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
				std::cout<<"Game State"<<std::endl;
				_data->assets.LoadTexture("Game Background",GAME_TITLE_FILEPATH);
				_background.setTexture(this->_data->assets.GetTexture("Game Background"));
				/* _background.setPosition(sf::Vector2f(200.0f,120.0f)); */
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

		}

		void GameState::Draw(float dt)
		{
				_data->window.clear(sf::Color(255,255,255));
				_data->window.draw(_background);
				_data->window.display();
		}

}
