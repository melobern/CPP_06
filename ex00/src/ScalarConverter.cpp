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

void	ScalarConverter::convert( std::string const& str ) {
	ScalarConverter 		tmp;
	ScalarConverter::Scalar scalar;

	scalar.type = tmp.identifyType(str, scalar);
	scalar.intPossible = tmp.convertToInt(str);
    scalar.charPossible = tmp.convertToChar(str);
    scalar.floatPossible = tmp.convertToFloat(str);
    scalar.doublePossible = tmp.convertToDouble(str);
	std::cout << scalar << std::endl;
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
