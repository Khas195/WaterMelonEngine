#pragma once
#include <vector>

class Package;
class PackageManager
{
	std::vector<Package*> packages;
	static PackageManager* instance;

	PackageManager();
	~PackageManager();
public:
	static PackageManager* getInstance();
	Package* requestPackage();
	void returnPackage(Package* package);
};

