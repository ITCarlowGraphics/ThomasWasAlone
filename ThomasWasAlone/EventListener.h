#pragma once


class EventListener
{
public:

	//list of possible events
	enum Event {
		REVERSE,
		PAUSE,
		QUIT
	};


	virtual void OnEvent(Event) {};
};

class a {
	int i;

};

