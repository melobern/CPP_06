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

void	ScalarConverter::convert( std::string const& literal ) {
	ScalarConverter 		tmp;
	ScalarConverter::Scalar scalar;

	scalar.type = tmp.identifyType(literal, scalar);
	tmp.convertToInt(scalar);
	tmp.convertToChar(scalar);
	tmp.convertToFloat(scalar);
	tmp.convertToDouble(scalar);
	std::cout << scalar << std::endl;
}


std::ostream &operator<<(std::ostream &out, ScalarConverter const &src) {
    out << "My name is " << BRIGHT_YELLOW << src.getName() << RESET;
    out << ", I'm a src of grade ";
    out << YELLOW << src.getGrade() << RESET << " !";
    out << std::endl;
    return (out);
}
