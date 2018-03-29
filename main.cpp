#include <iostream>
#include "calc.cpp"
#include "calc_basic.cpp"

int main(int argc, char **argv)
{
	auto calc = rvcalc::buildBasicCalculator<double>();
	
	double add = operate(*calc, "+", 2, 3);
	std::cout << "Resultado: " << add << std::endl;
	
	double mul = operate(*calc, "*", 2, 3);
	std::cout << "Resultado: " << mul << std::endl;

	return 0;
}
