#ifndef CALC_CPP_
#define CALC_CPP_

#include <functional>
#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_map>

namespace rvcalc
{

template<typename T>
using BinaryOperation = std::function<T(const T, const T)>;

template<typename T>
class Calculator
{
public:
	void registerOperation(const std::string &symbol, const BinaryOperation<T> &operation);
	const BinaryOperation<T>& getOperation(const std::string &symbol) const; 
private:
	bool isValid(const std::string &symbol) const;
	std::unordered_map<std::string, BinaryOperation<T>> operations;
};

template<typename T>
void Calculator<T>::registerOperation(const std::string &symbol, const BinaryOperation<T> &operation)
{
	if(isValid(symbol))
	{
		throw std::invalid_argument("Operation symbol: " + symbol + " has already been defined");
	}
	operations[symbol] = operation;
}

template<typename T>
const BinaryOperation<T>& Calculator<T>::getOperation(const std::string &symbol) const
{
	if(!isValid(symbol))
	{
		throw std::invalid_argument("Operation symbol: " + symbol + " has not been defined");
	}
	return operations.at(symbol);
}

template<typename T> 
bool Calculator<T>::isValid(const std::string &symbol) const
{
	return operations.find(symbol) != cend(operations);
}

template<typename T>
T operate(const Calculator<T> &calc, const std::string &symbol, const double firstOperand, const double secondOperand)
{
	const auto operation = calc.getOperation(symbol);
	return operation(firstOperand, secondOperand);
}

}

#endif // CALC_CPP_
