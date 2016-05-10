#include"PostOffice.h"
#include<iostream>
#include"Package/Package.h"
#include"IObserver.h"


PostOffice::PostOffice()
{
	std::cout << "PostOffice contructor.\n";
}


PostOffice::~PostOffice()
{
	std::cout << "PostOffice destructor.\n";
}

void PostOffice::add(IObserver * observer)
{
	this->observerList.push_back(observer);
}

void PostOffice::notifyAllObserver(Package * package)
{
	for (int i = 0; i < observerList.size();i++)
	{
		observerList[i]->receiveMessage(package);
	}
}
