#include <iostream>
#include <string>
#include "grid.h"
using namespace std;

int main() {
	cin.exceptions(ios::eofbit | ios::failbit);
	string cmd, aux;
	int switchergame = 0;
	Grid *g = new Grid();
	int moves = 0;

	try {
		while (true) {
			cin >> cmd;
			if (cmd == "new") {
				int n;
				cin >> n;
				g->init(n);
				switchergame = 1;
			} // new
			else if (cmd == "init") {
				int r, c;

				// Assume the input is valid in the size of 0 <= r <= n-1;
				while (cin >> r >> c) {
					if(r == -1 && c == -1){
						break;
					}
					else{
						g->turnOn(r, c);
					}
				}
				cout << *g;
			} // init
			else if (cmd == "game") {
				cin >> moves;
				if(moves != 1){
                                	cout << moves << " moves left" << endl;
                                }else{
                                        cout << "1 move left" << endl;
                                }
			} // game
			else if (cmd == "switch") {
				moves--;
				int r = 0, c = 0 ;
				cin >> r >> c;
				g->toggle(r, c);
				cout << *g;
					
				if(moves != 1){
					cout << moves << " moves left" << endl;
				}else{
					cout << "1 move left" << endl;
				}

				if(moves == 0 || g->isWon()){
					if (g->isWon()){
						cout << "Won" << endl;
					} // Print Win if the game is won
					else{
						cout << "Lost" << endl;
					}// Print Lost if the game is lost
					break;
				}
			} // switch
		} // while command
	}// try
	catch (ios::failure &) {
	}

	delete g;
}
