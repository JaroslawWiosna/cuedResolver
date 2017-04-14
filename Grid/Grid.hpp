#ifndef GRID_HPP
#define GRID_HPP

#include<iostream>
//#include<utility> // pair
#include<list> 
#include<vector> 
#include<string> 
#include<sstream> 

#include "../Cell/Cell.hpp"

struct step {
	unsigned int nr;
	Cell ball;
	std::string path;
}; 

class Grid{
	public:
	std::size_t x1, x2;
	Grid(unsigned int size);
	void setCue(int x1, int x2);
	void setBall(int x1, int x2);
	void setPocket(int x1, int x2);
	void setBoost(int x1, int x2, int addx1, int addx2);
	Cell computeMovement(Cell cue, Cell ball); 
	void detectOutOfGrid();
	void detectBoostCells();
	void solve();
	void printSolution();
	void printFastest();
	int printFastestOnlyDepth();

	private:
	unsigned int size;
	std::list<Cell> cuesVector;
	std::list<PairCell> boostVector;
	Cell ballStartPosition;
	Cell pocketPosition;
	const unsigned int maxDepth = 11;
	std::list<step> combinations;
};
#endif // GRID_HPP

