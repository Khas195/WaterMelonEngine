#pragma once

class PostOffice;
class Package;
class IObserver
{
protected:
	PostOffice* office;
public:
	virtual ~IObserver();

	virtual void receiveMessage(Package* package) = 0;
	void setPostOffice(PostOffice* office);
};

