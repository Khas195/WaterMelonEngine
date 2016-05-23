#include "WaterMelonEngine.h"
#include "Square.h"
WaterMelonEngine::WaterMelonEngine()
	: window()
	, timePerFrame(sf::seconds(1.f / 144.0f))
{
	sf::VideoMode destopMode = sf::VideoMode::getDesktopMode();
	window.create(sf::VideoMode(destopMode.width / 2, destopMode.height / 2), "Window Name", sf::Style::Default);
	window.setFramerateLimit(144); // 144.0f framerate per limit


	testSquare = new Square(sf::Color::Red, sf::Vector2f(50, 50), sf::Vector2f(100, 100));
	IComponent* testSquare2 = new Square(sf::Color::Blue, sf::Vector2f(100, 100), sf::Vector2f(50, 50));
	testSquare->addComponent(testSquare2);
}
WaterMelonEngine::~WaterMelonEngine()
{
	delete testSquare;
}
void WaterMelonEngine::loop()
{
	while (window.isOpen())
	{
		update();// Update every frame.
		render();
	}
}
void WaterMelonEngine::update()
{
	sf::Clock clock;
	testSquare->update(clock);
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