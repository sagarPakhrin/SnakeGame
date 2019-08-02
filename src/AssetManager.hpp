#pragma once
#include <SFML/Graphics.hpp>
#include <map>


namespace Sagar
{
		class AssetManager
		{
				public:
						AssetManager(){};
						~AssetManager(){};

						void LoadTexture(std::string name,std::string fileName);
						sf::Texture &GetTexture(std::string name);

		}
}
