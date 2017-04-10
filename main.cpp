#include<iostream>
#include"Grid/Grid.hpp"
int main()
{

	std::cout << __cplusplus << "\n";

	Grid grid(5);
	
	grid.setCue(3,1);
	grid.setCue(4,5);
	grid.setCue(5,5);
	grid.setCue(1,1);
	
	grid.setBall(3,3);
	grid.setPocket(2,5);

	grid.solve();
	grid.printSolution();
	
	return 0;
}
