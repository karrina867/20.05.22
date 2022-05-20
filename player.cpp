#include "player.h"
#include "sattings.h"
Player::Player() {
	texture.loadFromFile(PLAYER_READY_IMG);
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setScale(0.5f, 0.5f);
	pos = sf::Vector2f(WINDOW_WIDTH / 2 - getHitBox().width / 2,
		WINDOW_HEIGHT / 2 - getHitBox().height / 2);
	sprite.setPosition(pos);
}
void Player::update() {
	acc = sf::Vector2f( 0.f, GRAVITI);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		acc.x = -PLAYER_ACC_X;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		acc.x = PLAYER_ACC_X;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&& !isJump) {
		isJump = true;
		speed.y = PLAYER_JUMP_SPEED;
	}
	acc.x += speed.x * PLAYER_FICTTION;
	speed += acc;
	pos += speed + sf::Vector2f(acc.x * 0.5, acc.y * 0.5);
	if (pos.x < 0 - getHitBox().width / 2) {
		pos.x = WINDOW_WIDTH - getHitBox().width / 2;
	}
	else if (pos.x > WINDOW_WIDTH - getHitBox().width / 2) {
		pos.x = 0 - getHitBox().width / 2;
	}
	sprite.setPosition(pos);

}