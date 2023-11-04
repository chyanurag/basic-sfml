#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>

int main(){
	const int W_WIDTH = 1920;
	const int W_HEIGHT = 1080;
	sf::SoundBuffer buffer;
	sf::Sound sound;
	sf::Texture texture;
	sf::Sprite sprite;
	if(!texture.loadFromFile("image.png")){
		std::cerr << "image not loaded" << std::endl;
		return -1;
	}
	sprite.setTexture(texture);
	if(!buffer.loadFromFile("song.wav")){
		std::cerr << "couldn't load song" << std::endl;
		return -1;
	}
	sound.setBuffer(buffer);
	sound.play();
	sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), "MY Game", sf::Style::Fullscreen);
	sf::CircleShape circle(50.f);
	while(window.isOpen()){
		sf::Event ev;
			while(window.pollEvent(ev)){
				if(ev.type == sf::Event::Closed){
					window.close();
				}
			window.clear(sf::Color::Black);
			window.draw(sprite);
			window.display();
		}
	}
	return 0;
}
