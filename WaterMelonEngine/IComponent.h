#pragma once
#include "BaseObject.h"
#include "SFML\Graphics.hpp"
#include <assert.h>
class IComponent : public BaseObject
{
protected:
	sf::Transform* transform;
public :
	inline void setTransform(sf::Transform* transform)
	{
		assert(transform);
		this->transform = transform;
	}
};