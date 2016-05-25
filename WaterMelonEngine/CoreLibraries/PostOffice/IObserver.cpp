#include"IObserver.h"
#include"PostOffice.h"
#include<iostream>


IObserver::~IObserver()
{
	delete office;
}

void IObserver::setPostOffice(PostOffice * office)
{
	this->office = office;
}
