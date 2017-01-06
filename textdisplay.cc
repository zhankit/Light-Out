#include <iostream>
#include <utility>
#include "textdisplay.h"
#include "cell.h"
#include "info.h"
using namespace std;

// CTOR
TextDisplay::TextDisplay(int n) : gridSize{ n } {
	for (int i = 0; i < this->gridSize; i++) {
		vector<char> row;
		for (int j = 0; j < this->gridSize; j++) {
			row.push_back('_');
		}
		theDisplay.push_back(row);
	}
}

// METHOD NOTIFY
void TextDisplay::notify(Subject &whoNotified) {
	//cout << "Notify All: call" << endl;
	int r, c;
	r = whoNotified.getInfo().row;
	c = whoNotified.getInfo().col;
	if (whoNotified.getInfo().state) {
		//cout << "X" << endl;
		theDisplay.at(r).at(c) = 'X';
	}
	else {
		//cout << "_" << endl;
		theDisplay.at(r).at(c) = '_';
	}
}

// DTOR
TextDisplay::~TextDisplay() {}

// SUBSCRIPTION
SubscriptionType TextDisplay::subType() const {
	return SubscriptionType::All;
}

// OPERATOR <<
ostream &operator<<(ostream &out, const TextDisplay &td) {
	for (int i = 0; i < td.gridSize; i++) {
		for (int j = 0; j < td.gridSize; j++) {
			out << td.theDisplay.at(i).at(j);
		}
		out << endl;
	}
	return out;
}
