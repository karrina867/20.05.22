#pragma once
#include <string>

const std::string WINDOW_TITLE = "Jumper";
const size_t FPS = 60;// size_t = unsight short int

const float PLAYER_FICTTION = -0.075;
const std::string PLAYER_READY_IMG = "images/Players/bunny1_ready.png";
const std::string   PLATFORM_IMG="image/lass.png";
const float GRAVITI = 0.5;
const float PLAYER_JUMP_SPEED = -20;
const size_t PLATFORM_QTY = 8;


const float WINDOW_HEIGHT = 1000;
const float WINDOW_WIDTH = 600;
const std::string IMAGES_FOLDER = "images/";
const std::string PLAYER_IMAGES_FOLDER = "Players/";
const std::string PLAYER_IMAGE_FILENAME = "bunny1_ready.png";
const float PLAYER_ACC_X = 0.6f;
const float FRICTION = -0.1f;
const std::string PLATFORM_IMAGES_FOLDER = "Platforms/";
const std::string PLATFORM_IMAGE_FILENAME = "ground_grass.png";
const float GRAVITY = 0.6f;
const float JUMP_SPEED = -20.f;
const size_t PLATFORMS_QTY = 8;
const sf::Color BACKGROUND_COLOR = sf::Color(135, 206, 250);