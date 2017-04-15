#include <gtest/gtest.h>
#include "Grid.hpp"

TEST(Test, Grid05)
{
	Grid grid(5);
	
	grid.setCue(3,1);
	grid.setCue(4,5);
	
	grid.setBall(3,3);
	grid.setPocket(2,5);

	grid.solve();
	ASSERT_TRUE(true);
	EXPECT_EQ(grid.getNrOfSolution(),2);
	EXPECT_EQ(grid.getBallPositionOfSolution(),std::make_pair(2,5));
	EXPECT_EQ(grid.getPathOfSolution(),"3-1 4-5");
	
}


TEST(Test, Grid05Chrono)
{
	Grid grid(5);
	
	grid.setCue(3,1);
	grid.setCue(4,5);
	
	grid.setBall(3,3);
	grid.setPocket(2,5);

	grid.solve();
	ASSERT_TRUE(true);
	// TODO:
//	EXPECT_TRUE(grid.getStoperMilliSecond() > 1); 
	
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
