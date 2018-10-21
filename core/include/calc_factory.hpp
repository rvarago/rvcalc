// calc_factory_hpp
// @author rvarago

#ifndef CALC_FACTORY_HPP_
#define CALC_FACTORY_HPP_

#include "calc.hpp"

namespace rvcalc
{

// Helper to build calculators with pre-defined operations
template<typename T>
rvcalc::Calculator<T> makeCalc()
{
	rvcalc::Calculator<T> calc;

	calc.registerOperation("+", [](const auto firstOperand, const auto secondOperand) { return firstOperand + secondOperand; });
	calc.registerOperation("-", [](const auto firstOperand, const auto secondOperand) { return firstOperand - secondOperand; });
	calc.registerOperation("*", [](const auto firstOperand, const auto secondOperand) { return firstOperand * secondOperand; });
	calc.registerOperation("/", [](const auto firstOperand, const auto secondOperand) { return firstOperand / secondOperand; });

	return calc;
}

}

#endif // CALC_FACTORY_HPP_
