#include <gtest/gtest.h>
#include "Grid.hpp"

TEST(Test, GridTeleport)
{
	Grid grid(5);
	
	grid.setCue(2,1);
	grid.setCue(4,5);

	grid.setTeleport(2,3);
	grid.setTeleport(3,5);
	
	grid.setBall(2,2);
	grid.setPocket(2,5);

	grid.solve();
	ASSERT_TRUE(true);
	EXPECT_EQ(grid.getNrOfSolution(),2);
	EXPECT_EQ(grid.getBallPositionOfSolution(),std::make_pair(2,5));
	EXPECT_EQ(grid.getPathOfSolution(),"2-1 4-5");
	
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
