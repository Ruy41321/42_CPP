#include "../includes/ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>

using std::cout;
using std::endl;

int is_pseudo_literal(std::string str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return 1;
	if (str == "-inf" || str == "+inf" || str == "nan")
		return 1;
	return 0;
}

void invalid_case()
{
	cout << "char: impossible" << endl;
	cout << "int: impossible" << endl;
	cout << "float: impossible" << endl;
	cout << "double: impossible" << endl;
}

int find_type(std::string str)
{
    if (str.length() == 1 && !isdigit(str[0]))
        return CHAR;
    if (str == "-inff" || str == "+inff" || str == "nanf")
        return FLOAT;
    if (str == "-inf" || str == "+inf" || str == "nan")
        return DOUBLE;
    if (str.find('.') != std::string::npos)
    {
        if (str[str.length() - 1] == 'f')
            return FLOAT;
        else
            return DOUBLE;
    }
    for (size_t i = 0; i < str.length(); ++i)
    {
        char c = str[i];
        if (!isdigit(c) && c != '-' && c != '+')
            return INVALID;
    }
    return INT;
}

void char_case(std::string str)
{
	char ch = str[0];
	cout << "char: '" << ch << "'" << endl;
	cout << "int: " << static_cast<int>(ch) << endl;
    cout << "float: " << static_cast<float>(ch) << ".0f" << endl;
    cout << "double: " << static_cast<double>(ch) << ".0" << endl;
}

void int_case(std::string str)
{
	int n;
	std::stringstream ss(str);
	ss >> n;
	if (n <= std::numeric_limits<int>::min() || n >= std::numeric_limits<int>::max())
		return(invalid_case());
	if (!isprint(n))
		cout << "char: Non displayable" << endl;
	else
		cout << "char: '" << static_cast<char>(n) << "'" << endl;
	cout << "int: " << n << endl;
    cout << "float: " << static_cast<float>(n) << ".0f" << endl;
    cout << "double: " << static_cast<double>(n) << ".0" << endl;
}

void float_case(std::string str)
{
	if (is_pseudo_literal(str))
	{
		cout << "char: impossible" << endl;
		cout << "int: impossible" << endl;
		cout << "float: " << str << endl;
		cout << "double: " << str.substr(0, str.length() - 1) << endl;
		return ;
	}
	float f;
	std::stringstream ss(str);
	ss >> f;
	if (f <= -std::numeric_limits<float>::max() || f >= std::numeric_limits<float>::max())
		return(invalid_case());
	if (!isprint(f))
		cout << "char: Non displayable" << endl;
	else
		cout << "char: '" << static_cast<char>(f) << "'" << endl;
	if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
		cout << "int: impossible" << endl;
	else
	{
		cout << "int: " << static_cast<int>(f) << endl;
		if (f == static_cast<int>(f))
		{
			cout << "float: " << f << ".0f" << endl;
			cout << "double: " << static_cast<double>(f) << ".0" << endl;
		}
		else
		{
			cout << "float: " << f << "f" << endl;
			cout << "double: " << static_cast<double>(f) << endl;
		}
	}
}

void double_case(std::string str)
{
	if (is_pseudo_literal(str))
	{
		cout << "char: impossible" << endl;
		cout << "int: impossible" << endl;
        cout << "float: " << str + "f" << endl;
		cout << "double: " << str << endl;
		return ;
	}
	double d;
	std::stringstream ss(str);
	ss >> d;
	if (d <= std::numeric_limits<double>::min() || d >= std::numeric_limits<double>::max())
		return(invalid_case());
	if (!isprint(d))
		cout << "char: Non displayable" << endl;
	else
	{
		cout << "char: '" << static_cast<char>(d) << "'" << endl;
		cout << "int: " << static_cast<int>(d) << endl;
		cout << "float: " << static_cast<float>(d) << "f" << endl;
		cout << "double: " << d << endl;
	}
}

ScalarConverter::ScalarConverter()
{
}

void ScalarConverter::convert(std::string str)
{
    switch (find_type(str))
    {
        case CHAR:
		{
            char_case(str);
            break;
		}
        case INT:
        {
            int_case(str);
            break;
        }
        case FLOAT:
        {
            float_case(str);
            break;
        }
        case DOUBLE:
        {
            double_case(str);
            break;
        }
        default:
		{
            invalid_case();
            break;
		}
    }
}