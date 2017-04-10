#ifndef GRID_HPP
#define GRID_HPP

#include<iostream>
#include<utility> // pair
#include<vector> 

using Cell = std::pair<int, int>;
using PairCell = std::pair<Cell, Cell>;

struct step {
	unsigned int nr;
	Cell ball;
	std::vector<Cell> path;
}; 

class Grid{
	public:
	std::size_t x1, x2;
	Grid(unsigned int size = 5) : size(size)
	{

		
	}
	void setCue(int x1, int x2) {
		cuesVector.push_back(std::make_pair(x1,x2));
	}
	void setBall(int x1, int x2) {
		ballStartPosition = std::make_pair(x1,x2);
	}
	void setPocket(int x1, int x2) {
		pocketPosition = std::make_pair(x1,x2);
	}
	void setBoost(int x1, int x2, int addx1, int addx2) {
		boostVector.push_back(std::make_pair(
			std::make_pair(x1,x2),
			std::make_pair(x1+addx1,x2+addx2)
			));
	}
	Cell computeMovement(Cell cue, Cell ball) {
		int new_x1 = ball.first + (ball.first - cue.first);
		int new_x2 = ball.second + (ball.second - cue.second);
		return std::make_pair(new_x1, new_x2);
	}
	
	void detectOutOfGrid() {

		auto it = combinations.begin();
		for( ; it != combinations.end() ; ) {
			if ( it->ball.first < 1 
				|| it->ball.second < 1 
				|| it->ball.first > size
				|| it->ball.second > size 
				)
				it = combinations.erase(it);
			else
				++it;
		}

	}

	void detectBoostCells() {
		auto it = combinations.begin();
		for( ; it != combinations.end() ; ) {
			auto boost = boostVector.begin();
			for( ; boost != boostVector.end() ; ) {
				if (it->ball.first == boost->first.first
					&& it->ball.second == boost->first.second) {
					std::cout << it->ball.first 
						<< "-" << it->ball.second << "\n" ;
					//it->ball = boost->second;
					it->ball.first = boost->second.first;
					it->ball.second = boost->second.second;
				}
				++boost;
			}
			++it;
		}
/*
		for (step s : combinations) {
			for (PairCell p : boostVector) {
				if(s.ball.first == 7 && s.ball.second == 1) {
					s.ball.first = 5;

				if (s.ball.first == p.first.first 
					&& s.ball.second == p.first.second) {
					//s.ball = p.second;
					s.ball.first = p.second.first;
					s.ball.second = p.second.second;
					
					//std::cout << "!\n";
				}
			}
		}
*/
	}

	void solve() {
/*
		for(Cell n : cuesVector) {
			std::cout << n.first << "-" << n.second << "\n";
		}
*/
		// set init position
		//combinations.push_back({0, ballStartPosition, std::vector<Cell>{}});
		combinations.push_back({0, ballStartPosition, {}});

		for (unsigned int depth=1 ; depth <= maxDepth ; ++depth) {
			for(step s : combinations) {
				if (s.nr != depth-1) continue;
				for(Cell n : cuesVector) {
					std::vector<Cell> newPath = s.path;
					newPath.push_back(n);
					combinations.push_back(
						{depth, 
						computeMovement(n, s.ball), 
						newPath});
				}
			}
			this->detectOutOfGrid();
			this->detectBoostCells();	
			
		}	
	}

	void printSolution() {
		for(step n : combinations) {
			std::cout << n.nr << " " 
				<< n.ball.first << "-" << n.ball.second << "\n";
			for(Cell c : n.path) {
				std::cout << c.first << "-" << c.second <<", ";
			}


			std::cout << "\n\n";
		}	
	}	

	private:
	unsigned int size;
	std::vector<Cell> cuesVector;
	std::vector<PairCell> boostVector;
	Cell ballStartPosition;
	Cell pocketPosition;

	const unsigned int maxDepth = 7;

	std::vector<step> combinations;
	
};


#endif // GRID_HPP

