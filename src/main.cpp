#include <iostream>
#include "calc.hpp"
#include "calc_factory.hpp"

int main(int argc, char **argv)
{
	auto calc = rvcalc::makeCalc<double>();
	return 0;
}
