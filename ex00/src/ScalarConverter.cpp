/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
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

ScalarConverter::Scalar::Scalar(void) {
    this->type = INVALID;
    this->intVal = 0;
    this->floatVal = 0;
    this->charVal = 0;
    this->doubleVal = 0;
    this->charPossible = false;
    this->charDisplayable = false;
    this->intPossible = false;
    this->floatPrecision = 1;
}

void    ScalarConverter::convert(std::string const& str) {
    ScalarConverter         tmp;
    ScalarConverter::Scalar scalar;

    scalar.type = tmp.identifyType(str, scalar);
    if (scalar.type != INVALID) {
        tmp.convertToInt(scalar);
        tmp.convertToChar(scalar);
        tmp.convertToFloat(scalar);
        tmp.convertToDouble(scalar);
    }
    std::cout << scalar << std::endl;
}

ScalarConverter::inputType ScalarConverter::identifyType(std::string const &str,
                                                         Scalar &scalar) {
    if (ScalarConverter::isChar(str, scalar))
        return (CHAR);
    if (ScalarConverter::isInt(str, scalar))
        return (INT);
    if (ScalarConverter::isFloat(str, scalar))
        return (FLOAT);
    if (ScalarConverter::isDouble(str, scalar))
        return (DOUBLE);
    return (INVALID);
}

bool    ScalarConverter::isChar(std::string const &str, Scalar &scalar) {
    if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0])) {
        scalar.charVal = str[0];
        scalar.charPossible = true;
        scalar.charDisplayable = true;
        return (true);
    }
    if (str == "nan" || str == "nanf"
        || str == "inf" || str == "inff"
        || str == "+inf" || str == "+inff"
        || str == "-inf" || str == "-inff") {
        scalar.charDisplayable = true;
    }
    return (false);
}

bool    ScalarConverter::isInt(std::string const &str, Scalar &scalar) {
    errno = 0;
    char *end;

    int64_t num = std::strtol(str.c_str(), &end, 10);
    if (*end != '\0' || errno == ERANGE || num > INT_MAX || num < INT_MIN)
        return (false);
    scalar.intVal = static_cast<int>(num);
    scalar.intPossible = true;
    return (true);
}

bool    ScalarConverter::isFloat(std::string const &str, Scalar &scalar) {
    errno = 0;
    char *end;

    if (str == "nanf" || str == "nan") {
        scalar.floatVal = NANF;
        scalar.doubleVal = NAN_DOUBLE;
        return (true);
    }
    if (str == "inf" || str == "inff"
        || str == "+inf" || str == "+inff") {
        scalar.floatVal = INFF;
        scalar.doubleVal = INF_DOUBLE;
        return (true);
    }
    if (str == "-inf" || str == "-inff") {
        scalar.floatVal = -INFF;
        scalar.doubleVal = -INF_DOUBLE;
        return (true);
    }
    if (str.find(".") == std::string::npos)
        return (false);
    float num = std::strtof(str.c_str(), &end);
    if (*(end) == '\0'|| *(end) != 'f' || *(++end)
        || errno == ERANGE || num > FLOAT_MAX || num < -FLOAT_MAX)
        return (false);
    scalar.floatVal = num;
    scalar.floatPrecision = str.length() - str.find('.') - 2;
    return (true);
}

bool    ScalarConverter::isDouble(std::string const &str, Scalar &scalar) {
    errno = 0;
    char *end;
    if (str.find(".") == std::string::npos)
        return (false);
    double num = std::strtod(str.c_str(), &end);
    if (*end != '\0' || errno == ERANGE
        || num > std::numeric_limits<double>::max()
        || num < -std::numeric_limits<double>::max())
        return (false);
    scalar.doubleVal = num;
    if (scalar.doubleVal > FLOAT_MAX) {
        scalar.floatVal = INFF;
    } else if (scalar.doubleVal < -FLOAT_MAX) {
        scalar.floatVal = -INFF;
    }
    scalar.floatPrecision = str.length() - str.find('.') - 1;
    return (true);
}

void   ScalarConverter::checkIfIntIsPossible(Scalar &scalar) {
    switch (scalar.type) {
        case INT:
        case CHAR:
            scalar.intPossible = true;
            break;
        case FLOAT:
            if (scalar.floatVal == scalar.floatVal &&
                scalar.floatVal <= INT_MAX && scalar.floatVal >= INT_MIN) {
                scalar.intPossible = true;
            }
            break;
        case DOUBLE:
            if (scalar.doubleVal == scalar.doubleVal &&
                scalar.doubleVal <= INT_MAX && scalar.doubleVal >= INT_MIN) {
                scalar.intPossible = true;
            }
            break;
        default:
            break;
    }
}

void    ScalarConverter::convertToInt(Scalar &scalar) {
    if (scalar.type == INT)
        return;
    checkIfIntIsPossible(scalar);
    switch (scalar.type) {
        case CHAR:
            scalar.intVal = static_cast<int>(scalar.charVal);
            break;
        case FLOAT:
            if (scalar.intPossible) {
                if (scalar.floatVal < 0)
                    scalar.intVal = static_cast<int>(scalar.floatVal - 0.5);
                else
                    scalar.intVal = static_cast<int>(scalar.floatVal + 0.5);
            }
            break;
        case DOUBLE:
            if (scalar.intPossible) {
                if (scalar.doubleVal < 0)
                    scalar.intVal = static_cast<int>(scalar.doubleVal - 0.5);
                else
                    scalar.intVal = static_cast<int>(scalar.doubleVal + 0.5);
            }
            break;
        default:
            break;
    }
}

void    ScalarConverter::convertToChar(Scalar &scalar) {
    if (scalar.type == CHAR)
        return;
    if (!scalar.intPossible
        || scalar.intVal < CHAR_MIN
        || scalar.intVal > CHAR_MAX) {
        scalar.charPossible = false;
        scalar.charDisplayable = true;
        return;
    }
    scalar.charPossible = true;
    switch (scalar.type) {
        case INT:
            scalar.charVal = static_cast<char>(scalar.intVal + 0.5);
            break;
        case FLOAT:
            scalar.charVal = static_cast<char>(scalar.floatVal + 0.5);
            break;
        case DOUBLE:
            scalar.charVal = static_cast<char>(scalar.doubleVal + 0.5);
            break;
        default:
            break;
    }
    scalar.charDisplayable = std::isprint(scalar.charVal);
}

void     ScalarConverter::convertToFloat(Scalar &scalar) {
    if (scalar.type == FLOAT)
        return;
    if ((scalar.doubleVal == NAN_DOUBLE
        || scalar.doubleVal == INF_DOUBLE
        || scalar.doubleVal == -INF_DOUBLE)) {
        scalar.floatVal = NANF;
        return;
    }
    switch (scalar.type) {
        case CHAR:
            scalar.floatVal = static_cast<float>(scalar.charVal);
            break;
        case INT:
            scalar.floatVal = static_cast<float>(scalar.intVal);
            break;
        case DOUBLE:
            if (scalar.doubleVal > FLOAT_MAX)
                scalar.floatVal = INFF;
            else if (scalar.doubleVal < -FLOAT_MAX)
                scalar.floatVal = -INFF;
            else
                scalar.floatVal = static_cast<float>(scalar.doubleVal);
            break;
        default:
            break;
    }
}

void    ScalarConverter::convertToDouble(Scalar &scalar) {
    switch (scalar.type) {
        case CHAR:
            scalar.doubleVal = static_cast<double>(scalar.charVal);
            break;
        case INT:
            scalar.doubleVal = static_cast<double>(scalar.intVal);
            break;
        case FLOAT:
            scalar.doubleVal = static_cast<double>(scalar.floatVal);
            break;
        case DOUBLE:
            break;
        default:
            break;
    }
}

std::ostream &operator<<(std::ostream &os, ScalarConverter::Scalar const &sc) {
    if (sc.type == ScalarConverter::INVALID) {
        os << RED << "Invalid input" << RESET;
        return (os);
    }
    if (!sc.charDisplayable) {
        os << "char: Non displayable" << std::endl;
    } else if (!sc.charPossible) {
         os << "char: impossible" << std::endl;
    } else {
        os << "char: '" << sc.charVal << "'" << std::endl;
    }
    if (!sc.intPossible) {
        os << "int: impossible" << std::endl;
    } else {
        os << "int: " << sc.intVal << std::endl;
    }
    os << "float: ";
    os << std::fixed << std::setprecision(sc.floatPrecision) << sc.floatVal;
    os << "f" << std::endl;

    os << "double: ";
    os << std::fixed << std::setprecision(sc.floatPrecision) << sc.doubleVal;
    return (os);
}
