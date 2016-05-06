#pragma once
#include <vector>
#include <memory>
#include "IState.h"
#include "IGameObject.h"
class WaterMelonEngine;

class Scene  : public IState
{
	typedef std::unique_ptr<IGameObject> ObjectPointer;
	static WaterMelonEngine* engine;
	std::vector<ObjectPointer> gameObjects;
public:
	Scene();
	virtual ~Scene();

	static void setEngine(WaterMelonEngine* engine);

	void addGameObject(ObjectPointer gameObject);
	void removeGameObject(ObjectPointer target);

	virtual void update();
	virtual void render(sf::RenderWindow & window);

	// Inherited via IState
	virtual void onPushed() override;

	virtual void onPoped() override;

	virtual void onReturnToTop() override;

	virtual void onPressed() override;

}