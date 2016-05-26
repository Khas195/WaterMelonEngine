#pragma once
#include <iostream>
#include <map>
#include <string>
#include <assert.h>
#include "PackageManager.h"

class Package
{
	std::map<std::string, void*> items;
	
	friend class PackageManager;
	Package();
	~Package();
public:
	template <typename T>
	void put(std::string key,T* value)
	{
		assert(value != NULL);
		this->items[key] = static_cast<void*>(value);
	}
	template <typename T>
	T* get(std::string key)
	{
		try
		{
			if (this->items.count(key))
			{
				return static_cast<T*>(this->items[key]);
			}
			else return nullptr;
		}
		catch (...)
		{
			std::cout << "Error returning value for Package" << std::endl;
		}
	}

	void reset();
};

