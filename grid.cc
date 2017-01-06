#include <iostream>
#include "grid.h"
using namespace std;

Grid::Grid() { this->gridSize = -1;};

Grid::~Grid() { clearGrid(); }


// Method clearGrid
void Grid::clearGrid() {
	for (int i = this->gridSize - 1; i >= 0; i--) {
		for (int j = 0; j < this->gridSize; j++) {
			theGrid.at(i).pop_back();
		}
                theGrid.pop_back();
        }
	delete td;
}

// Method isWon
bool Grid::isWon() const {
	for (int i = this->gridSize - 1; i >= 0; i--) {
                for (int j = 0; j < this->gridSize; j++) {
                        if(theGrid[i][j].getState()){
				return false;
			}
                }
        }
	return true;

}

void Grid::init(int n) {
	if(this->gridSize != -1){
		this->clearGrid();
	}
	this->gridSize = n;
	td = new TextDisplay(n);

	for (int i = 0; i < n; i++) {
		std::vector<Cell> row;
		for (int j = 0; j < n; j++) {
			Cell temp;
			temp.setCoords(i, j);
			temp.attach(td);
			row.push_back(temp);
		}
		theGrid.push_back(row);
	}
	
	// Attach their neighbour
	for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

			if(i == 0){
				theGrid[i][j].attach(&theGrid[i+1][j]);
			} // Row at 0 position
			else if(i == gridSize -1){
				theGrid[i][j].attach(&theGrid[i-1][j]);
			} // Row at last postion
			else{
				theGrid[i][j].attach(&theGrid[i+1][j]);
				theGrid[i][j].attach(&theGrid[i-1][j]);
			}

			if(j == 0){
				theGrid[i][j].attach(&theGrid[i][j+1]);
			} // Col at 0 position
			else if(j == gridSize -1){
                                theGrid[i][j].attach(&theGrid[i][j-1]);
                        } // Col at last position
			else{
                                theGrid[i][j].attach(&theGrid[i][j-1]);
                                theGrid[i][j].attach(&theGrid[i][j+1]);
                        } // Col in between 0 and n - 1

		}
        }
	
};

// Done
void Grid::turnOn(int r, int c) {
	theGrid[r][c].setOn();
};

// Done
void Grid::toggle(int r, int c) {
	theGrid[r][c].toggle();
};

// Done
void Grid::init(int r, int c) {
	theGrid[r][c].setOn();
};

// Done
ostream &operator<<(ostream &out, const Grid &g) {
	out << *g.td;
	return out;
};
