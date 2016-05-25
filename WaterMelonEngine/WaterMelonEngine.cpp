#include "WaterMelonEngine.h"
#include "Square.h"
#include "TextureManager.h"
#include<iostream>

sf::Clock GameTime::game_time;

WaterMelonEngine::WaterMelonEngine()
	: window()
	, timePerFrame(sf::seconds(1.f / 60.0f))
{
	sf::VideoMode destopMode = sf::VideoMode::getDesktopMode();
	window.create(sf::VideoMode(destopMode.width / 2, destopMode.height / 2), "Window Name", sf::Style::Default);
	window.setFramerateLimit(144); // 144.0f framerate per limit
	

	testSquare = new Square();
}
WaterMelonEngine::~WaterMelonEngine()
{
	delete testSquare;
}
void WaterMelonEngine::loop()
{
	//sf::Clock clock;
	sf::Time offset;
	game_time.restart();
	while (window.isOpen())
	{
		if (offset >= timePerFrame) {
			std::cout << game_time.getElapsedTime().asMicroseconds() << std::endl;
			offset -= timePerFrame;
			update(game_time);// Update every frame.
		}
		render();
		offset += game_time.restart();
	}
}
void WaterMelonEngine::update(sf::Clock & gameTime)
{
	testSquare->update(gameTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		window.close();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
		testSquare->disable();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	{
		testSquare->enable();
	}
}

void WaterMelonEngine::render()
{
	window.clear();
	testSquare->render(window);
	window.display();
}