// symbols.hpp
// @author rvarago

#ifndef SYMBOLS_HPP_
#define SYMBOLS_HPP_

#include <string>

namespace rvcalc
{

template<typename T>
class Symbols
{
public:

	Symbols(const std::string operatorSymbol, const T &firstOperand, const T &secondOperand) 
		: m_operatorSymbol(operatorSymbol), m_firstOperand(firstOperand), m_secondOperand(secondOperand) {}
	
	const std::string operatorSymbol() const
	{
		return m_operatorSymbol;
	}
	
	const T firstOperand() const
	{ 
		return m_firstOperand; 
	}

	const T secondOperand() const
	{
		return m_secondOperand; 
	}
	
private:
	const std::string m_operatorSymbol;
	const T m_firstOperand;
	const T m_secondOperand;
};

template<typename T>
bool operator==(const Symbols<T> &lhs, const Symbols<T> &rhs)
{
	return lhs.operatorSymbol() == rhs.operatorSymbol() 
		&& lhs.firstOperand() == rhs.firstOperand() 
		&& lhs.secondOperand() == rhs.secondOperand();
}

}

#endif // SYMBOL_HPP_
