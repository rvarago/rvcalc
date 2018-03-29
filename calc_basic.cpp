#include "calc.cpp"

namespace rvcalc
{

template<typename T>
std::unique_ptr<rvcalc::Calculator<T>> buildBasicCalculator()
{
	std::unique_ptr<rvcalc::Calculator<T>> calc = std::make_unique<rvcalc::Calculator<T>>();

	calc->registerOperation("+", [](const auto firstOperand, const auto secondOperand) { return firstOperand + secondOperand; });
	calc->registerOperation("-", [](const auto firstOperand, const auto secondOperand) { return firstOperand - secondOperand; });
	calc->registerOperation("*", [](const auto firstOperand, const auto secondOperand) { return firstOperand * secondOperand; });
	calc->registerOperation("/", [](const auto firstOperand, const auto secondOperand) { return firstOperand / secondOperand; });

	return calc;
}

}
