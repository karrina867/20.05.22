#pragma once
#include "SFML/Graphics.hpp"
#include "sattings.h"

class Platform {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f pos;
	float width;
	float height;
	bool del = false;
public:
	Platform(float x, float y, float width, float height) {
		texture.loadFromFile(
			IMAGES_FOLDER +
			PLATFORM_IMAGES_FOLDER +
			PLATFORM_IMAGE_FILENAME);
		sprite.setTexture(texture);
		sf::FloatRect g_bounds = sprite.getGlobalBounds();
		sprite.setScale(width / g_bounds.width, height / g_bounds.height);
		sprite.setPosition(x, y);
	}
	void update() {}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
	sf::Vector2f getPosition() { return sprite.getPosition(); }
	void setPosition(sf::Vector2f pos) { sprite.setPosition(pos); }
	void setPosition(float x, float y) {
		sprite.setPosition(sf::Vector2f(x, y));
	}
	bool getDel() { return del; }
	void setDel() { del = true; }
};