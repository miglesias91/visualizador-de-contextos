
// gtest
#include <gtest/gtest.h>

// vld
#include <vld.h>

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);

	int result = RUN_ALL_TESTS();

	std::getchar();

	return result;
}