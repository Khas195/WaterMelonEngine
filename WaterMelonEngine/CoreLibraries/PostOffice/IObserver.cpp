#include"IObserver.h"
#include"PostOffice.h"
#include<iostream>


void IObserver::setPostOffice(PostOffice * office)
{
	this->office = office;
}
