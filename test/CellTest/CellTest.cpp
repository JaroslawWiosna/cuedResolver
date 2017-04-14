
#include <gtest/gtest.h>
//#include "../../Grid/Grid.hpp"
#include "../../Cell/Cell.hpp"

TEST(Test, CellTest)
{
	Cell cell1 = std::make_pair(2,4);
	Cell cell2 = std::make_pair(2,4);
	Cell cell3 = std::make_pair(1,5);

	ASSERT_EQ(cell1,cell2);
	ASSERT_NE(cell1,cell3);
	ASSERT_EQ(cell2,cell1);
	ASSERT_NE(cell2,cell3);
	ASSERT_NE(cell3,cell1);
	ASSERT_NE(cell3,cell2);

}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
