8#include "SquareObject.h"

SquareObject::SquareObject(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f scale, float degree, sf::Color color)
{
	TextureManager::init();
	int tex_id = TextureManager::requestID("./sprites/dragonFrames.png");
	this->tile = new Sprite(TextureManager::requestTexture(tex_id), sf::Vector2f(64, 64), sf::Vector2f(3, 4));
	gameView.setSize(sf::Vector2f(768, 448));
	gameView.setFillColor(sf::Color::Blue);
	gameView.setPosition(16, 0);
	menuView.setSize(sf::Vector2f(800, 152));
	menuView.setFillColor(sf::Color::Red);
	menuView.setPosition(0, 448);
	dragons.setTimePerFrame(.1f);
	for (unsigned int i = 0; i < 4; ++i)
	{
		dragons.setFixedRow(i);
		anim.set(i, dragons);
	}
	int sound_id = SoundManager::requestID("./sounds/dragonRoar.wav");
	this->sound.setBuffer(*SoundManager::requestSoundBuffer(sound_id));
	SoundManager::setBackgroundMusic("./musics/musicsBox.ogg");
	SoundManager::playBackgroundMusic();
}

SquareObject::~SquareObject()
{
}

void SquareObject::update(sf::Clock & gameTime)
{
	anim.stop();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		sound.play();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		anim.trigger(0);
		anim.move(0, 1);
		anim.go();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		anim.trigger(1);
		anim.move(-1, 0);
		anim.go();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		anim.trigger(2);
		anim.move(1, 0);
		anim.go();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		anim.trigger(3);
		anim.move(0, -1);
		anim.go();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		// special effect
		anim.setScale(2,2);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		// special effect
		anim.setScale(1, 1);
	}
	
}

void SquareObject::render(sf::RenderWindow & window)
{
	//window.draw(gameView);
	//window.draw(menuView);
	map.render(window);
	tile->render(window);
}

void SquareObject::receiveMessage(Package * package)
{
}

std::string SquareObject::getName()
{
	return "SquareObject";
}
