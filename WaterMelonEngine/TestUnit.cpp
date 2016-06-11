#include "TestUnit.h"
#include "TextureManager.h"



TestUnit::TestUnit()
{
	int heroID = TextureManager::requestID("S:/3rd Year/Semester 2/CS411/Lab/Final/WaterMelonEngine/WaterMelonEngine/sprites/hero.png");
	test = new sf::Sprite(TextureManager::requestTexture(heroID));
	test->setTextureRect(sf::IntRect(0, 0, 64, 64));
	test->setPosition(200, 200);
	transform = test->getTransform();
}


TestUnit::~TestUnit()
{
	delete test;
}

sf::Clock temp;
void TestUnit::update(sf::Event::EventType & type)
{
}

void TestUnit::render(sf::RenderWindow & window)
{
	window.draw(*test);
}

void TestUnit::receiveMessage(Package * package)
{
}

std::string TestUnit::getName()
{
	return std::string();
}
