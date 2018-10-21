// calc_test.cpp
// @author rvarago

#include "gtest/gtest.h" //<gtest/gtest.h>
#include "calc.hpp"
#include "calc_factory.hpp"
#include "symbols.hpp"

using namespace rvcalc;

TEST(Calc, Add)
{
	auto calc = makeCalc<double>();

	EXPECT_DOUBLE_EQ(0, operate(calc, Symbols<double>{"+", 0.0, 0.0}));
	EXPECT_DOUBLE_EQ(5, operate(calc, Symbols<double>{"+", 2.0, 3.0}));
	EXPECT_DOUBLE_EQ(20, operate(calc, Symbols<double>{"+", 8.0, 12.0}));
}

TEST(Calc, Sub)
{
	auto calc = makeCalc<double>();

	EXPECT_DOUBLE_EQ(0, operate(calc, Symbols<double>{"-", 0.0, 0.0}));
	EXPECT_DOUBLE_EQ(-1, operate(calc,Symbols<double>{"-", 2.0, 3.0}));
	EXPECT_DOUBLE_EQ(3, operate(calc, Symbols<double>{"-", 5.0, 2.0}));
}

TEST(Calc, Mul)
{
	auto calc = makeCalc<double>();

	EXPECT_DOUBLE_EQ(0, operate(calc, Symbols<double>{"*", 10.0, 0.0}));
	EXPECT_DOUBLE_EQ(1, operate(calc, Symbols<double>{"*", 1.0, 1.0}));
	EXPECT_DOUBLE_EQ(6, operate(calc, Symbols<double>{"*", 2.0, 3.0}));
}

TEST(Calc, Div)
{
	auto calc = makeCalc<double>();

	EXPECT_DOUBLE_EQ(0, operate(calc, Symbols<double>{"/", 0.0, 1.0}));
	EXPECT_DOUBLE_EQ(6, operate(calc, Symbols<double>{"/", 36.0, 6.0}));
	EXPECT_DOUBLE_EQ(20, operate(calc, Symbols<double>{"/", 100.0, 5.0}));
}