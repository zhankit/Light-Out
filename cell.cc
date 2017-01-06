#include <utility>
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "subscriptions.h"
#include "info.h"
using namespace std;
// CTOR 
Cell::Cell() {
	this->isOn = false;
}

// DTOR
Cell::~Cell() {}

// METHOD GETSTATE
bool Cell::getState() const { return isOn; }

// METHOD SETON
void Cell::setOn() {
	this->isOn = true;
	this->notifyObservers(SubscriptionType::All);
}

//METHOD TOGGLE
void Cell::toggle() {
	if (this->isOn == true){
		this->isOn = false;
	}else{
		this->isOn = true;
	}
	this->notifyObservers(SubscriptionType::SwitchOnly);
}

// METHOD SETCOORDS
void Cell::setCoords(int r, int c) { this->r = r; this->c = c; }

// METHOD NOTIFY
void Cell::notify(Subject &a) {
	isOn = !(this->isOn);
	this->notifyObservers(SubscriptionType::All);
}

// Subscription Type
SubscriptionType Cell::subType() const {
	return SubscriptionType::SwitchOnly;
}

// METHOD GETINFO
Info Cell::getInfo() const {
	return Info{ this->r , this->c, this->isOn };
};
