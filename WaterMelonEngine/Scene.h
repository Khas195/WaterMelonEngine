#pragma once
#include <vector>
#include "BaseObject.h"
#include "GameObject.h"
#include "IState.h"
class Scene : public BaseObject, public IState, public IObserver
{
protected:
	GameObject* godObject;
public:
	Scene();
	void addGameObject(GameObject* gameObject);
	void removeGameObject(GameObject* gameObject);
	// Inherited via Scene
	virtual void update(sf::Clock & gameTime) override;
	virtual void render(sf::RenderWindow & window) override;
	virtual ~Scene();

	// Inherited via IObserver
	virtual void receiveMessage(Package * package) override;
};