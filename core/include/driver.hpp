// driver_hpp
// @author rvarago

#ifndef DRIVER_HPP_
#define DRIVER_HPP_

#include <istream>
#include <ostream>
#include <string>

#include "calc.hpp"
#include "parser.hpp"

namespace rvcalc
{

template<typename T>
class Driver
{
public:
	explicit Driver(const Calculator<T>& calc, const Parser<T>& parser) : m_calc(calc), m_parser(parser) {}
	void drive(std::istream& in, std::ostream& out) const;
private:
	const Calculator<T> m_calc;
	const Parser<T> m_parser;
};

template<typename T>
void Driver<T>::drive(std::istream& in, std::ostream& out) const
{
	std::string line;
	
	while(std::getline(in, line))
	{
		const auto symbols = m_parser.parse(line);
		out << 	operate(m_calc, symbols) << "\n";
	}
}

}

#endif // DRIVER_HPP_
