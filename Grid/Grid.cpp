#include "Grid.hpp"


Grid::Grid(unsigned int size = 5) : size(size)
{

}
void Grid::setCue(int x1, int x2) {
	cuesVector.push_back(std::make_pair(x1,x2));
}

void Grid::setBall(int x1, int x2) {
	ballStartPosition = std::make_pair(x1,x2);
}
void Grid::setPocket(int x1, int x2) {
	pocketPosition = std::make_pair(x1,x2);
}

void Grid::setBoost(int x1, int x2, int addx1, int addx2) {
	boostVector.push_back(std::make_pair(
		std::make_pair(x1,x2),
		std::make_pair(x1+addx1,x2+addx2)
		));
}
Cell Grid::computeMovement(Cell cue, Cell ball) {
	int new_x1 = ball.first + (ball.first - cue.first);
	int new_x2 = ball.second + (ball.second - cue.second);
	return std::make_pair(new_x1, new_x2);
}
	
void Grid::detectOutOfGrid() {
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

void Grid::detectBoostCells() {
	bool willContinue{false};
	do {
		willContinue = false;
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
					willContinue = true;
				}
				++boost;
			}
			++it;
		}
	} while(willContinue);
}

void Grid::solve() {
	combinations.push_back({0, ballStartPosition, ""});

	for (unsigned int depth=1 ; depth <= maxDepth ; ++depth) {
		for(step s : combinations) {
		if (s.nr == depth-1) {
			for(Cell n : cuesVector) {
				std::string newPath{s.path};
					//newPath += std::to_string(n.first);
					//newPath += "-";
					//newPath += std::to_string(n.second);
					//newPath += " ";
				std::stringstream ss;
				ss << s.path;
				ss << n.first << "-" << n.second << " ";
				combinations.push_back(
					{depth, 
					computeMovement(n, s.ball), 
					ss.str()});
			}
		}
		}
		this->detectOutOfGrid();
		this->detectBoostCells();	
	}
	// find the best solution
	for(step n : combinations) {
		if(n.ball.first == pocketPosition.first &&
		n.ball.second == pocketPosition.second) {
			solution.nr = n.nr;
			solution.ball = std::make_pair(n.ball.first, n.ball.second);
			solution.path = n.path;			
			break;
		}
	}				
}

void Grid::printSolution() {
	std::cout << solution.nr << " "
	<< solution.ball.first << "-" << solution.ball.second << "\n";
	std::cout << ":" << solution.path;
	std::cout << "\n\n";
}	

void Grid::printFastest() {
	for(step n : combinations) {
		if(n.ball.first == pocketPosition.first &&
		n.ball.second == pocketPosition.second) {
			std::cout << n.nr << " " 
			<< n.ball.first << "-" << n.ball.second << "\n";
			std::cout << "<" << n.path;
			
			std::cout << "\n\n";
			break;
		}
	}	
}	

int Grid::printFastestOnlyDepth() {
	for(step n : combinations) {
		if(n.ball.first == pocketPosition.first &&
		n.ball.second == pocketPosition.second) {
			return n.nr;
		}
	}	
}	

unsigned int Grid::getNrOfSolution() {
	return solution.nr;
}

Cell Grid::getBallPositionOfSolution() {
	return solution.ball;
}

std::string Grid::getPathOfSolution() {
	// Removing trailing space char is necessary
	// TODO: dirty solution... 
	std::string res = solution.path;
	return solution.path.substr(0, solution.path.size()-1); 
}
