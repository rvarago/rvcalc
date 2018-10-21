// parser.hpp
// @author rvarago

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <functional>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include <boost/algorithm/string.hpp>

#include "symbols.hpp"

namespace rvcalc
{

template<typename T>
using TokenToOperand = std::function<T(const std::string&)>;

// Parse binary expressions of the form:
// <Operand><SEPARATOR><Operator><SEPARATOR><Operand>
// Where <SEPARATOR> is a text separator between operands, default is space
template<typename T>
class Parser
{
public:
	explicit Parser(TokenToOperand<T> interpreter, char delimiter = ' ') : m_interpreter(interpreter), m_delimiter(delimiter) {}
	Symbols<T> parse(const std::string& expression) const;
private:
	TokenToOperand<T> m_interpreter;
	char m_delimiter;
};

template<typename T>
Symbols<T> Parser<T>::parse(const std::string& expression) const
{
	std::vector<std::string> tokens;
	boost::split(tokens, expression, [this](auto it){return it == m_delimiter;});

	if(tokens.size() != 3)
	{
		throw std::invalid_argument("Expression: " + expression + " must be of the form <OPERAND>" + m_delimiter + "<OPERATOR>" + m_delimiter+ "<OPERAND>");
	}

	const auto operatorSymbol = tokens[1];
	const auto firstOperand = m_interpreter(tokens[0]);
	const auto secondOperand = m_interpreter(tokens[2]);

	return Symbols<T>{operatorSymbol, firstOperand, secondOperand};
}

}
#endif // PARSER_HPP_
