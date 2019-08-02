#include "InputManager.hpp"

namespace Sagar
{
		bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
		{
				if(sf::Mouse::isButtonPressed(button))
				{
						sf::IntRect tempReact(object.getPosition().x,object.getPosition().y, object.getGlobalBounds().width,object.getGlobalBounds().height);
						if(tempReact.contains(sf::Mouse::getPosition(window)))
						{
								return true;
						}
				}
				return false;
		}

		sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow &window)
		{
				return sf::Mouse::getPosition(window);
		}
}
