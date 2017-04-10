#include<iostream>
#include"Grid/Grid.hpp"
int main()
{

	std::cout << __cplusplus << "\n";

	Grid grid(9);
	
	grid.setCue(2,3);
	grid.setCue(3,1);
	grid.setCue(5,9);
	grid.setCue(6,6);
	grid.setCue(9,3);
	
	grid.setBoost(1,3,2,0);
	grid.setBoost(3,5,0,3);
	grid.setBoost(7,4,-3,0);
	grid.setBoost(7,5,0,-1);

	grid.setBall(5,6);
	grid.setPocket(8,7);

	grid.solve();
	grid.printSolution();
	
	return 0;
}
