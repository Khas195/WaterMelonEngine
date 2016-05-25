#include "WaterMelonEngine.h"
#include "CoreLibraries\SpriteManager\TextureManager.h"
#include "GameScene.h"
#include "StateStack.h"
WaterMelonEngine::WaterMelonEngine()
	: window()
	, timePerFrame(sf::seconds(1.f / 144.0f))
{
	sf::VideoMode destopMode = sf::VideoMode::getDesktopMode();
	window.create(sf::VideoMode(destopMode.width / 2, destopMode.height / 2), "Window Name", sf::Style::Default);
	window.setFramerateLimit(144); // 144.0f framerate per limit
	GameScene* gameScene = new GameScene();
	this->sceneStack.push(gameScene);
}
WaterMelonEngine::~WaterMelonEngine()
{
}
void WaterMelonEngine::loop()
{
	sf::Clock clock;

	while (window.isOpen())
	{
		update(clock);// Update every frame.
		render();
		clock.restart();
	}
}
void WaterMelonEngine::update(sf::Clock& gameTime)
{
	this->sceneStack.getTop<Scene>()->update(gameTime);
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