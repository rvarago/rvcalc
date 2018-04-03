// calc_factory_hpp
// @author rvarago

#ifndef CALC_FACTORY_HPP_
#define CALC_FACTORY_HPP_

#include "calc.hpp"

namespace rvcalc
{

// Helper to build calculators with pre-defined operations
template<typename T>
std::unique_ptr<rvcalc::Calculator<T>> makeCalc()
{
	auto calc = std::make_unique<rvcalc::Calculator<T>>();

	calc->registerOperation("+", [](const auto firstOperand, const auto secondOperand) { return firstOperand + secondOperand; });
	calc->registerOperation("-", [](const auto firstOperand, const auto secondOperand) { return firstOperand - secondOperand; });
	calc->registerOperation("*", [](const auto firstOperand, const auto secondOperand) { return firstOperand * secondOperand; });
	calc->registerOperation("/", [](const auto firstOperand, const auto secondOperand) { return firstOperand / secondOperand; });

	return calc;
}

}

#endif // CALC_FACTORY_HPP_
