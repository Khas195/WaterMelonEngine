#pragma once
#include <vector>
#include "BaseObject.h"
#include "CoreLibraries\PostOffice\IObserver.h"
#include <assert.h>
class GameObject : public  BaseObject, public IObserver
{
	sf::Transform* transform;
	std::vector<GameObject*> childObjects;
protected:
	bool isEnable;
	bool isAwake;
	virtual void onAwake() {};
	virtual void onSleep() {};
	virtual void onEnable() {};
	virtual void onDisable() {};
	void updateChildren(sf::Clock& gameTime);
	void renderChildren(sf::RenderWindow& window);
public:
	GameObject() = default;
	virtual ~GameObject();
	// Inherited via BaseObject
	virtual std::string getName() = 0;
	void enable();
	void disable();
	void sleep();
	void awake();
	void addGameObject(GameObject* gameObject);
	void removeGameObject(GameObject* target);
	template <typename T>
	T* findGameObjectByType()
	{
		for (int i = 0; i < childObjects.size(); ++i)
		{
			T* result = dynamic_cast<T*>(childObjects[i]);
			if (result)
				return result;
		}
		return nullptr;
	}
};