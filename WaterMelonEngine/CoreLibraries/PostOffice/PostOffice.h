#pragma once
#include<vector>

class IPackage;
class IObserver;
class PostOffice
{
protected:
	std::vector<IObserver*> observerList;
public:
	PostOffice();
	~PostOffice();

	void add(IObserver* observer);
	void notifyAllObserver(IPackage* package);
};