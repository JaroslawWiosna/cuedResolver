
#include <gtest/gtest.h>
#include "Cell/Cell.hpp"

TEST(Test, cppVersion)
{
	#if __cplusplus <= 199711L
		ASSERT_TRUE(false);
	#else
		ASSERT_TRUE(true);
	#endif
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
