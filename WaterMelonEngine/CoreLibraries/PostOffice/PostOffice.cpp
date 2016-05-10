#include"PostOffice.h"
#include"IPackage.h"
#include"IObserver.h"
#include<iostream>


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

void PostOffice::notifyAllObserver(IPackage * package)
{
	for (int i = 0; i < observerList.size();i++)
	{
		observerList[i]->receiveMessage(package);
	}
}
