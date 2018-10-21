// calc.hpp
// @author rvarago

#ifndef CALC_HPP_
#define CALC_HPP_

#include <functional>
#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include "symbols.hpp"

namespace rvcalc
{

template<typename T>
using BiFunction = std::function<T(const T, const T)>;

// Map symbols to math operations
template<typename T>
class Calculator
{
public:
	void registerOperation(const std::string& symbol, BiFunction<T> operation);
	const BiFunction<T> getOperation(const std::string &symbol) const; 
private:
	bool alreadyRegistered(const std::string& symbol) const;
	std::unordered_map<std::string, BiFunction<T>> operations;
};

template<typename T>
void Calculator<T>::registerOperation(const std::string& symbol, BiFunction<T> operation)
{
	if(alreadyRegistered(symbol))
	{
		throw std::invalid_argument("Operation symbol: " + symbol + " has already been defined");
	}
	operations[symbol] = operation;
}

template<typename T>
const BiFunction<T> Calculator<T>::getOperation(const std::string& symbol) const
{
	if(!alreadyRegistered(symbol))
	{
		throw std::invalid_argument("Operation symbol: " + symbol + " has not been defined");
	}
	return operations.at(symbol);
}

template<typename T> 
bool Calculator<T>::alreadyRegistered(const std::string& symbol) const
{
	return operations.find(symbol) != cend(operations);
}

template<typename T>
T operate(const Calculator<T>& calc, const Symbols<T>& symbols)
{
	const auto operation = calc.getOperation(symbols.operatorSymbol());
	return operation(symbols.firstOperand(), symbols.secondOperand());
}

}

#endif // CALC_HPP_
