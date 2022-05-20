#include "game.h"

Game::Game() :
	window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Jumper"),
	game_over_screen("images/ дабавить имя файла ")
{
	//â ñàìîì íèçó ýêðàíà øèðèíîé íà âåñü ýêðàí
	Platform* p1 = new Platform(0, WINDOW_HEIGHT - 55.f,
		WINDOW_WIDTH, 55.f);
	platform_sprites.push_back(p1);
	//âûøå 1-îé è íà 1/2 ýêðàíà øèðèíîé
	Platform* p2 = new Platform(WINDOW_WIDTH / 4,
		WINDOW_HEIGHT * 3 / 4, WINDOW_WIDTH / 4, 55.f);
	platform_sprites.push_back(p2);
	Platform* p3 = new Platform(WINDOW_WIDTH * 2 / 3,
		WINDOW_HEIGHT / 2, WINDOW_WIDTH / 4, 55.f);
	platform_sprites.push_back(p3);
	window.setVerticalSyncEnabled(true);
}
void Game::play() {
	while (window.isOpen()) {
		check_events();
		update();
		check_collisions();
		draw();
	}
}
void Game::check_events() {
	sf::Event event;
	while (window.pollEvent(event)) {
		// Ïîëüçîâàòåëü íàæàë íà «êðåñòèê» è õî÷åò çàêðûòü îêíî?
		if (event.type == sf::Event::Closed)
			// òîãäà çàêðûâàåì åãî
			window.close();
	}
}
void Game::update() {
	switch (game_state) {
	case GameState::INTRO:
		break;
	case GameState::PLAY:
	{
		player.update();
		if (player.getPosition().y > WINDOW_HEIGHT) {
			game_state = GameState::GAME_OVER;
		}
		for (auto iter = platform_sprites.begin();
			iter != platform_sprites.end(); iter++) {
			(*iter)->update();
		}
		//äâèæåíèå âñåõ ïëàòôîðì âíèç åñëè èãðîê äîïðûãàë äî âåðõà
		if (player.getPosition().y <= WINDOW_HEIGHT / 3.f) {
			for (auto iter = platform_sprites.begin();
				iter != platform_sprites.end(); iter++) {
				(*iter)->setPosition((*iter)->getPosition().x,
					(*iter)->getPosition().y + abs(player.getSpeed().y));
				//ïëàòôîðìû, êîòîðûå îïóñòèëèñü íèæå 4/3 âûñîòû ýêðàíà 
				//ïîìå÷àåì íà óäàëåíèå
				if ((*iter)->getPosition().y > 4 * WINDOW_HEIGHT / 3) {
					(*iter)->setDel();
				}
			}
		}
		//óäàëÿåì íåíóæíûå ïëàòôîðìû
		platform_sprites.remove_if([](Platform* p) {
			return p->getDel(); });
		while (platform_sprites.size() < PLATFORMS_QTY) {
			int len = rand() % 151 + 100;
			int new_x = rand() % (static_cast<int>(
				WINDOW_WIDTH - len));
			int new_y = rand() % 451 - 300;
			Platform* p = new Platform(new_x, new_y, len, 55.f);
			platform_sprites.push_back(p);
		}
		break;
	}
	case GameState::GAME_OVER:
		break;
	}
}
void Game::draw() {
	window.clear(BACKGROUND_COLOR);
	switch (game_state) {
	case GameState::INTRO:
		break;
	case GameState::PLAY:
		player.draw(window);
		for (auto iter = platform_sprites.begin();
			iter != platform_sprites.end(); iter++) {
			(*iter)->draw(window);
		}
		break;
	case GameState::GAME_OVER:
		game_over_screen.draw(window);
		break;
	}

	window.display();
}
void Game::check_collisions() {
	for (auto iter = platform_sprites.begin();
		iter != platform_sprites.end(); iter++) {
		if (player.getSpeed().y > 0) {
			if (player.getHitBox().intersects((*iter)->getHitBox())) {
				if (player.getSpeed().y >= 0) {
					player.setIsJumping(false);
					player.resetSpeed();
					sf::Vector2f platform_pos = (*iter)->getPosition();
					sf::Vector2f player_new_pos =
						sf::Vector2f(player.getPosition().x,
							platform_pos.y - player.getHitBox().height);
					player.setPosition(player_new_pos);
				}
			}
		}
	}
}
