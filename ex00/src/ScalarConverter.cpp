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
    if (scalar.type != ScalarConverter::INVALID) {
        tmp.convertToInt(str, scalar);
        tmp.convertToChar(str, scalar);
        tmp.convertToFloat(str, scalar);
        tmp.convertToDouble(str, scalar);
    }
	std::cout << scalar << std::endl;
}

ScalarConverter::inputType ScalarConverter::identifyType(std::string const &str, ScalarConverter::Scalar &scalar) {
    if (ScalarConverter::isChar(str))
        return (CHAR);
    if (ScalarConverter::isInt(str))
        return (INT);
    if (ScalarConverter::isFloat(str))
        return (FLOAT);
    if (ScalarConverter::isDouble(str))
        return (DOUBLE);
    return (INVALID);
}

bool    ScalarConverter::isChar(std::string const &str, Scalar &scalar) {
    if (str.length() == 1 && std::isprint(str[0] && !std::isdigit(str[0])))
        return (true);
    scalar.charVal = str[0];
    return (false);
}

bool    ScalarConverter::isInt(std::string const &str, Scalar &scalar) {
    errno = 0;
    char *end;
    long num = std::strtol(str.c_str(), &end, 10);
    if (*end != '\0' || errno == ERANGE || num > INT_MAX || num < INT_MIN)
        return (false);
    scalar.intVal = static_cast<int>(num);
    return (true);
}

bool    ScalarConverter::isFloat(std::string const &str, Scalar &scalar) {
    errno = 0;
    char *end;
    float num = std::strtof(str.c_str(), &end);
    if (*end != '\0' || errno == ERANGE || num > FLOAT_MAX || num < -FLOAT_MAX)
        return (false);
    scalar.floatVal = num;
    scalar.floatPrecision = str.length() - str.find('.') - 2;
    return (true);
}

void		ScalarConverter::convertToInt(std::string const &str, Scalar &scalar) {
    switch (scalar.type) {
        case CHAR:
            scalar.intVal = static_cast<int>(scalar.charVal);
            break;
        case INT:
            break;
        case FLOAT:
            scalar.intVal = static_cast<int>(scalar.floatVal);
            break;
        case DOUBLE:
            scalar.intVal = static_cast<int>(scalar.doubleVal);
            break;
        default:
            break;
    }
}

void		ScalarConverter::convertToDouble(std::string const &str, Scalar &scalar) {
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

    }
}
std::ostream &operator<<(std::ostream &os, ScalarConverter::Scalar const &sc) {
    if (sc.type == ScalarConverter::INVALID) {
        os << RED << "Invalid input" << RESET << std::endl;
        return (os);
    }
    if (!sc.charDisplayable) {
        os << "char: Non displayable" << std::endl;
    } else if (!sc.charPossible) {
         os << "char: impossible" << std::endl;
    } else {
        os << "char: '" << sc.charVal << "'" << std::endl;
    }
    os << "char: " << sc.charVal << std::endl;
    os << "int: " << sc.intVal << std::endl;
    os << "float: " << sc.floatVal << "f" << std::endl;
    os << "double: " << sc.doubleVal << std::endl;
    return (os);
} 
/*Handling conversions between different scalar types in C++ can be tricky due to potential issues like data loss, overflow, and type safety. Here are some best practices to follow:

1. **Use Explicit Conversions**: Avoid implicit conversions that can lead to unexpected results. Use explicit casting to make conversions clear and intentional.
    ```cpp
    int intValue = static_cast<int>(doubleValue);
    ```

2. **Check for Overflows and Underflows**: Before performing a conversion, ensure that the value is within the range of the target type to prevent overflow or underflow.
    ```cpp
    if (doubleValue >= INT_MIN && doubleValue <= INT_MAX) {
        int intValue = static_cast<int>(doubleValue);
    } else {
        // Handle overflow/underflow
    }
    ```

3. **Handle Special Floating-Point Values**: Be aware of special floating-point values like NaN (Not a Number) and infinity, and handle them appropriately.
    ```cpp
    if (std::isnan(floatValue) || std::isinf(floatValue)) {
        // Handle special cases
    } else {
        int intValue = static_cast<int>(floatValue);
    }
    ```

4. **Use Standard Library Functions**: Utilize functions from the standard library for conversions, as they are well-tested and handle many edge cases.
    ```cpp
    double doubleValue = std::stod(stringValue);
    ```

5. **Validate Input**: Always validate input before performing conversions to ensure it is in the expected format and range.
    ```cpp
    if (std::isdigit(stringValue[0])) {
        int intValue = std::stoi(stringValue);
    } else {
        // Handle invalid input
    }
    ```

6. **Use Exception Handling**: Use exceptions to handle errors during conversions, such as invalid input or out-of-range values.
    ```cpp
    try {
        int intValue = std::stoi(stringValue);
    } catch (const std::invalid_argument& e) {
        // Handle invalid argument
    } catch (const std::out_of_range& e) {
        // Handle out of range
    }
    ```

7. **Document Conversion Logic**: Clearly document the conversion logic, including any assumptions and edge cases, to make the code easier to understand and maintain.

8. **Test Thoroughly**: Write comprehensive tests to cover all possible conversion scenarios, including edge cases and invalid inputs.

By following these best practices, you can ensure that scalar type conversions in your C++ code are safe, reliable, and maintainable.*/