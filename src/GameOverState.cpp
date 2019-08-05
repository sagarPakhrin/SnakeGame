#include <sstream>
#include "GameOverState.hpp"
#include "MainMenuState.hpp"
#include "DEFINATIONS.hpp"
#include <iostream>

namespace Sagar
{
		GameOverState::GameOverState(GameDataRef data): _data(data)
		{

		}

		void GameOverState::Init()
		{
				std::cout<<"Game State"<<std::endl;
				_data->assets.LoadTexture("Game Background",GAME_TITLE_FILEPATH);
				_background.setTexture(this->_data->assets.GetTexture("Game Background"));
		}

		void GameOverState::HandleInput()
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


		void GameOverState::Update(float dt)
		{

		}

		void GameOverState::Draw(float dt)
		{
				_data->window.clear(sf::Color(255,255,255));
				_data->window.draw(_background);
				_data->window.display();
		}

}
