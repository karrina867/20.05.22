#pragma once
#include "SFML/Graphics.hpp"
class SplashScreen {
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	SplashScreen(std::string file_name) {
		texture.loadFromFile(file_name);
		sprite.setTexture(texture);
	}
	void draw(sf::RenderWindow& window) { window.draw(sprite); }
};