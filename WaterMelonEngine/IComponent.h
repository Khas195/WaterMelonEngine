#pragma once
#include <SFML\Graphics.hpp>
#include <string>

#include "CoreLibraries\PostOffice\IObserver.h"
// interface
class IComponent  : public IObserver
{
	std::vector<IComponent*> components;
protected:
	bool isEnable = true; // stop/begin update and render
	bool isAwake = true; // stop/begin update 
	virtual void onAwake() = 0;
	virtual void onSleep() = 0;
	virtual void onEnable() = 0;
	virtual void onDisable() = 0;

	
	void updateChildren(sf::Clock& gameTime);
	void renderChildren(sf::RenderWindow& window);
public:
	IComponent() = default;
	virtual ~IComponent();
	virtual void init() = 0;
	virtual void update(sf::Clock& gameTime) = 0;
	virtual void render(sf::RenderWindow& window) = 0;
	virtual std::string getName() = 0 ;

	void enable();
	void disable();
	void awake();
	void sleep();

	// Inherited via IObserver
	virtual void receiveMessage(Package * package) override;

	void addComponent(IComponent* component)
	{
		this->components.push_back(component);
	}
	template <typename T>
	T* findComponent()
	{
		for (IComponent* component : components)
		{
			if (dynamic_cast<T>(*component))
			{
				return component;
			}
		}
		return nullptr;
	}
	template <typename T>
	T* findComponentInChild()
	{
		auto result;
		for (IComponent* component : components)
		{
			result = component->findComponent();
			if (result)
			{
				return result;
			}
		}
		return nullptr;
	}
};

