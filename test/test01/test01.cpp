
#include <gtest/gtest.h>
#include "Grid.hpp"

TEST(Test, test01)
{
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
	ASSERT_TRUE(true);
	ASSERT_EQ(grid.printFastestOnlyDepth(),8);

}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
