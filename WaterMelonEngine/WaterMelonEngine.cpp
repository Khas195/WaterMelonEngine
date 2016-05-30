#include "WaterMelonEngine.h"
#include "CoreLibraries\SpriteManager\TextureManager.h"
#include "GameScene.h"
#include "StateStack.h"
#include "Definition.h"
#include <iostream>
WaterMelonEngine::WaterMelonEngine()
	: window()
	, timePerFrame(sf::seconds(1.f / 144.0f))
{
	window.create(sf::VideoMode(SCREEN_WIDTH , SCREEN_HEIGHT), "Window Name", sf::Style::Default);
	window.setFramerateLimit(144); // 144.0f framerate per limit
	GameScene* gameScene = new GameScene();
	this->sceneStack.push(gameScene);
	std::cout << timePerFrame.asMilliseconds() << std::endl;
}
WaterMelonEngine::~WaterMelonEngine()
{
}
void WaterMelonEngine::loop()
{
	sf::Clock clock;
	sf::Clock tempClock;
	int i = 0;
	tempClock.restart();
	while (window.isOpen())
	{
		sf::Event events;
		window.pollEvent(events);
		if (events.type == sf::Event::Closed)
			window.close();

		if (clock.getElapsedTime() >= timePerFrame)
		{
			++i;
			update(events.type);// Update every frame.
			clock.restart();
		}
		render();
		if (tempClock.getElapsedTime().asMilliseconds() >= 1000.f)
		{
			std::cout << i << "\n";
			i = 0;
			tempClock.restart();
		}
	}
}
void WaterMelonEngine::update(sf::Event::EventType& type)
{
	this->sceneStack.getTop<Scene>()->update(type);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		window.close();
	}
}

void WaterMelonEngine::render()
{
	window.clear();
	this->sceneStack.getTop<Scene>()->render(window);
	window.display();
}