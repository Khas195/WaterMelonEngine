#pragma once
#include "GameObject.h"
#include "SFML\Graphics.hpp"
#include "Scene.h"
class GameState;
class GameDirector : public GameObject
{
	GameState* startState;
	GameState* pauseState;
	GameState* gameOverState;
	GameState* inGameState;

	Scene* currentScene;
	sf::RectangleShape start;
	sf::RectangleShape exit;
	sf::RectangleShape retry;
	sf::RectangleShape resume;
	sf::RectangleShape backToMain;
	GameState* previousState;
	GameState* curState;

	float moveSpeed;
	bool transitionDone = false;
public:
	enum MENU { PAUSE, START, GAMEOVER, INGAME};
private:
	std::vector<sf::RectangleShape> getChosenMenu(MENU menu);
public:
	GameDirector(Scene* scene);
	~GameDirector();
	
	void renderChosenMenu(MENU menu, sf::RenderWindow& window);

	void setCurrentState(GameState* state);
	GameState * const getCurrentState() { return curState; };
	void setPreviousState(GameState* state);
	GameState * const getState(MENU menu);

	void setTransitionDone(bool done) { transitionDone = done; };
	void setTransitionSpeed(float speed) { moveSpeed = speed; };
	
	void moveGameMenu(MENU menu, const sf::Vector2f& targetPos);
	bool isMenuAt(const sf::Vector2f& pos, MENU menu);
	void setMenuPosition(MENU menu, const sf::Vector2f& pos);
	
	// Inherited via GameObject
	virtual void update(sf::Event::EventType & type) override;
	virtual void render(sf::RenderWindow & window) override;
	virtual void receiveMessage(Package * package) override;
	virtual std::string getName() override;
};

