// parser_test.cpp
// @author rvarago

#include <gtest/gtest.h>
#include <string>

#include "parser.hpp"
#include "utils.hpp"

using namespace std;
using namespace rvcalc;

TEST(Parser, ParseIntAdd)
{
	Parser<int> parser{rvcalc::stoi};
	Symbols<int> expected{"+", 1, 2};

	EXPECT_EQ(expected, parser.parse("1 + 2"));
}

TEST(Parser, ParseDoubleSub)
{

	Parser<double> parser{rvcalc::stod};
	Symbols<double> expected{"-", 10.5, -2.0};

	EXPECT_EQ(expected, parser.parse("10.5 - -2.0"));
}

TEST(Parser, ParseCustomDelim)
{

	Parser<int> parser{rvcalc::stoi, ';'};
	Symbols<int> expected{"+", 2, 2};

	EXPECT_EQ(expected, parser.parse("2;+;2"));
}


int main(int argc, char **argv) 
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
