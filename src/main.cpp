// main.cpp
// @author rvarago

#include <iostream>

#include "calc.hpp"
#include "calc_factory.hpp"
#include "driver.hpp"
#include "parser.hpp"
#include "utils.hpp"

int main(int argc, char **argv)
{
	const auto calc = rvcalc::makeCalc<double>();
	const auto parser = rvcalc::Parser<double>{rvcalc::stod};
	const auto driver = rvcalc::Driver<double>{calc, parser};

	std::cout << "Initializing RVCalc...\n";

	driver.drive(std::cin, std::cout);
	
	return 0;
}
