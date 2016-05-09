#include "PackageManager.h"
#include "Package.h"

PackageManager* PackageManager::instance;
PackageManager::PackageManager()
{
}
PackageManager::~PackageManager()
{
	while (!this->packages.empty())
	{
		delete this->packages.back();
		this->packages.pop_back();
	}
}

PackageManager* PackageManager::getInstance()
{
	if (!instance)
	{
		instance = new PackageManager();
	}
	return instance;
}
Package * PackageManager::requestPackage()
{
	Package* requestedPackage;
	if (packages.empty())
	{
		requestedPackage = new Package();
	}
	else
	{
		requestedPackage = this->packages.back();
		this->packages.pop_back();
	}
	return requestedPackage;
}

void PackageManager::returnPackage(Package* package)
{
	assert(package != nullptr);
	package->reset();
	this->packages.push_back(package);
	package = nullptr;
}
