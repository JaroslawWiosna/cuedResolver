#include<iostream>
#include"Grid/Grid.hpp"
int main()
{

	std::cout << __cplusplus << "\n";

	Grid grid(9);
	
	grid.setCue(1,1);
	grid.setCue(1,4);
	grid.setCue(1,6);
	grid.setCue(1,8);
	grid.setCue(6,7);
	grid.setCue(9,7);
	
	grid.setBoost(5,2,0,1);
	grid.setBoost(5,3,-2,2);
	grid.setBoost(5,6,-3,0);
	grid.setBoost(5,8,2,-2);

	grid.setBall(2,3);
	grid.setPocket(8,3);

	grid.solve();
	grid.printSolution();
	
	return 0;
}
