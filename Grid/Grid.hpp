#ifndef GRID_HPP
#define GRID_HPP

#include<iostream>
#include<utility> // pair
#include<vector> 

using Cell = std::pair<int, int>;
//typedef std::pair<int, int> Cell;

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
	Cell computeMovement(Cell cue, Cell ball) {
		int new_x1 = ball.first + (ball.first - cue.first);
		int new_x2 = ball.second + (ball.second - cue.second);
		return std::make_pair(new_x1, new_x2);
	}
	
	void detectOutOfGrid() {

		for(step s : combinations) {
			
		}
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
			
		}	
	}

	void printSolution() {
		for(step n : combinations) {
			std::cout << n.nr << " " 
				<< n.ball.first << "-" << n.ball.second << "\n";
			for(Cell c : n.path) {
				std::cout << c.first << "-" << c.second <<"\n";
			}


			std::cout << "\n\n";
		}	
	}	

	private:
	unsigned int size;
	std::vector<Cell> cuesVector;
	Cell ballStartPosition;
	Cell pocketPosition;

	const unsigned int maxDepth = 3;

	std::vector<step> combinations;
	
};


#endif // GRID_HPP

