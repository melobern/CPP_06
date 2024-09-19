/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:48:17 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/06 09:45:11 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ScalarConverter.hpp"
#include "../includes/Colors.hpp"

ScalarConverter::ScalarConverter(void) {
    return;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
    (void)src;
    return;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const &src)  {
    (void)src;
    return (*this);
}

ScalarConverter::~ScalarConverter() {
    return;
}

ScalarConverter::Scalar::Scalar(void)
 : charVal(0), intVal(0), floatVal(0.0f), doubleVal(0.0),
	charDisplayable(true), charPossible(true), intPossible(true),
    doublePossible(true) {
    return;
}

void	ScalarConverter::convert( std::string const& str ) {
	ScalarConverter 		tmp;
	ScalarConverter::Scalar scalar;

    try {
        scalar.type = tmp.identifyType(str, scalar);
    } catch (ScalarConverter::InvalidInputException &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
        return;
    }
	scalar.intPossible = tmp.convertToInt(str);
    scalar.charPossible = tmp.convertToChar(str);
    scalar.floatPossible = tmp.convertToFloat(str);
    scalar.doublePossible = tmp.convertToDouble(str);
	std::cout << scalar << std::endl;
}

ScalarConverter::inputType	ScalarConverter::identifyType(std::string const &str, ScalarConverter::Scalar &scalar) const {
    if (ScalarConverter::isChar(str, scalar)) {
        return (CHAR);
    }
    if (ScalarConverter::isInt(str, scalar)) {
        return (INT);
    }
    if (ScalarConverter::isFloat(str, scalar)) {
        return (FLOAT);
    }
    if (ScalarConverter::isDouble(str, scalar)) {
        return (DOUBLE);
    }
    throw ScalarConverter::InvalidInputException();
}

bool ScalarConverter::isChar(std::string const &str, ScalarConverter::Scalar &scalar) const {
    if (str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0])) {
        scalar.charVal = str[0];
        return (true);
    }
    return (false);
}

bool ScalarConverter::isInt(std::string const &str, ScalarConverter::Scalar &scalar) const {
    
}

bool ScalarConverter::isFloat(std::string const &str, ScalarConverter::Scalar &scalar) const {
    try {
        std::stof(str);
    } catch (std::exception &e) {
        return (false);
    }
    return (true);
}

bool ScalarConverter::isDouble(std::string const &str, ScalarConverter::Scalar &scalar) const {
    try {
        std::stod(str);
    } catch (std::exception &e) {
        return (false);
    }
    return (true);
}

char	ScalarConverter::convertToChar(std::string const &str) {
    if (scalar.type == ScalarConverter::inputType::CHAR) {
        scalar.charVal = str[0];
        return (1);
    }
    return (0);
}

int		ScalarConverter::convertToInt(std::string const &str) {
    if (scalar.type == ScalarConverter::inputType::INT) {
        scalar.intVal = std::stoi(scalar.str);
        return (1);
    }
    return (0);
}

std::ostream &operator<<(std::ostream &os, ScalarConverter::Scalar const &sc) {
    os << "char:" << sc.charVal << std::endl;
    os << "int:" << sc.intVal << std::endl;
    os << "float:" << sc.floatVal << "f" << std::endl;
    os << "double:" << sc.doubleVal << std::endl;
    return (os);
} 

const char* ScalarConverter::InvalidInputException::what() const throw () {
    return ("Invalid input value.");
}