#include <iostream>
#include "subject.h"
#include "observer.h"
#include "subscriptions.h"
using namespace std;

void Subject::attach(Observer *o) {
	observers.emplace_back(o);
};

void Subject::notifyObservers(SubscriptionType t) {
	if(t == SubscriptionType::SwitchOnly){
	//	 cout << "notify(SO)" << endl;
		for (auto ob : observers) {
			ob->notify(*this);			
		}
	}else{
	//	cout << "notify(ALL)" << endl;
		for (auto ob : observers) {
          //               cout << "ALLRUN in subject" << endl;
			 if(ob->subType() == SubscriptionType::All){
				ob->notify(*this);
			}
                }
	}
};

Subject::~Subject() {};
