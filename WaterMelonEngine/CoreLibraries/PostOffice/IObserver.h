#pragma once

class PostOffice;
class IPackage;
class IObserver
{
protected:
	PostOffice* office;
public:
	virtual ~IObserver() = default;

	virtual void receiveMessage(IPackage* package) = 0;
	void setPostOffice(PostOffice* office);
};

