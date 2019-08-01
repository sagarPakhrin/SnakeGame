#include <iostream>
#include <SFML/Graphics.hpp>


int main(){
		sf::RenderWindow window(sf::VideoMode(600,600),"SFML WORKS!");
		while(window.isOpen())
		{
				sf::Event event;
				while(window.pollEvent(event))
				{
						switch(event.type){
								case sf::Event::Closed:
										window.close();
										break;
								case sf::Event::KeyPressed:
										std::cout<<"Key has been pressed"<<std::endl;
										switch(event.key.code)
										{
												case sf::Keyboard::A:
														std::cout<<"A"<<std::endl;
														break;
										}
										break;
								case sf::Event::KeyReleased:
										std::cout<<"Key has been released"<<std::endl;
										break;

								case sf::Event::MouseButtonPressed:
										std::cout<<"Mouse pressed"<<std::endl;

										switch(event.key.code){
												case sf::Mouse::Left:
																			 std::cout<<"Left Button Pressed"<<std::endl;
																			 break;
												default:
																			 std::cout<<"Right Button Pressed"<<std::endl;
																			 break;
										}
										break;
								case sf::Event::MouseMoved:
										std::cout<<"Mouse moved"<<std::endl;
										std::cout<<"Mouse X: "<<event.mouseMove.x<<"Mouse Y: "<<event.mouseMove.y<<std::endl;
								case sf::Event::MouseEntered:
										std::cout<<"Mouse entered: "<<std::endl;
										break;
								case sf::Event::MouseLeft:
										std::cout<<"Mouse Left: "<<std::endl;
										break;

								case sf::Event::GainedFocus:
															 std::cout<<"Gained Focus"<<std::endl;
								case sf::Event::LostFocus:
															 std::cout<<"Lost Focus"<<std::endl;
						}
				}
		}
}
