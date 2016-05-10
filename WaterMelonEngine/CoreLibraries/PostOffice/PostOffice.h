#pragma once
#include<vector>

class Package;
class IObserver;
class PostOffice
{
protected:
	std::vector<IObserver*> observerList;
public:
	PostOffice();
	~PostOffice();

	void add(IObserver* observer);
	void notifyAllObserver(Package* package);
};