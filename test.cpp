#include <gtest/gtest.h>
#include "calc.cpp"
#include "calc_basic.cpp"

using namespace rvcalc;

TEST(Calc, Add)
{
	auto calc = buildBasicCalculator<double>();

	ASSERT_EQ(0, operate(*calc, "+", 0, 0));
	ASSERT_EQ(5, operate(*calc, "+", 2, 3));
	ASSERT_EQ(20, operate(*calc, "+", 8, 12));
}

TEST(Calc, Sub)
{
	auto calc = buildBasicCalculator<double>();

	ASSERT_EQ(0, operate(*calc, "-", 0, 0));
	ASSERT_EQ(-1, operate(*calc, "-", 2, 3));
	ASSERT_EQ(3, operate(*calc, "-", 5, 2));
}

TEST(Calc, Mul)
{
	auto calc = buildBasicCalculator<double>();

	ASSERT_EQ(0, operate(*calc, "*", 10, 0));
	ASSERT_EQ(1, operate(*calc, "*", 1, 1));
	ASSERT_EQ(6, operate(*calc, "*", 2, 3));
}

TEST(Calc, Div)
{
	auto calc = buildBasicCalculator<double>();

	ASSERT_EQ(0, operate(*calc, "/", 0, 1));
	ASSERT_EQ(6, operate(*calc, "/", 36, 6));
	ASSERT_EQ(20, operate(*calc, "/", 100, 5));
}

int main(int argc, char **argv) 
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
