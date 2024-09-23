/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+   cat         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:48:17 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/06 10:18:55 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX00_INCLUDES_SCALARCONVERTER_HPP_
#define EX00_INCLUDES_SCALARCONVERTER_HPP_
# include <iostream>
# include <string>
# include <climits>
# include <limits>
# include <cerrno>
# include <cstdlib>
# include <iomanip>
# include <cctype>
# include "../includes/Colors.hpp"

# define NANF std::numeric_limits<float>::quiet_NaN()
# define INFF std::numeric_limits<float>::infinity()
# define NAN_DOUBLE std::numeric_limits<double>::quiet_NaN()
# define INF_DOUBLE std::numeric_limits<double>::infinity()
# define FLOAT_MAX std::numeric_limits<float>::max()

class ScalarConverter {
 public:
  static void convert(std::string const &str);
  enum inputType {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID
  };

  struct Scalar {
    inputType type;
    int       intVal;
    float     floatVal;
    char      charVal;
    double    doubleVal;
    bool      charPossible;
    bool      charDisplayable;
    bool      intPossible;
    size_t    floatPrecision;
    Scalar(void);
  };
    class InvalidInputException : public std::exception {
      virtual const char* what() const throw();
    };
 private:
  ScalarConverter(void);
  ScalarConverter(const ScalarConverter &src);
  ScalarConverter &operator=(const ScalarConverter &src);
  ~ScalarConverter(void);
  void        convertToInt(Scalar &scalar);
  void        convertToFloat(Scalar &scalar);
  void        convertToChar(Scalar &scalar);
  void        convertToDouble(Scalar &scalar);

  inputType   identifyType(std::string const &str, Scalar &scalar);
  bool        isChar(std::string const &str, Scalar &scalar);
  bool        isInt(std::string const &str, Scalar &scalar);
  bool        isFloat(std::string const &str, Scalar &scalar);
  bool        isDouble(std::string const &str, Scalar &scalar);
};

std::ostream &operator<<(std::ostream &os, ScalarConverter::Scalar const &sc);

#endif  //  EX00_INCLUDES_SCALARCONVERTER_HPP_
// Write a class ScalarConverter that will contain only one static method "convert"
// that will takes as parameter a string representation of a C++ literal in its most common
// form and output its value in the following serie of scalar types :
// • char
// • int
// • float
// • double
// As this class doesnt need to store anything at all, this class must not be instanciable by
// users.
// Except for char parameters, only the decimal notation will be used.
// Examples of char literals: ’c’, ’a’, ...
// To make things simple, please note that non displayable characters shouldnt be used as
// inputs. If a conversion to char is not displayable, prints an informative message.
// Examples of int literals: 0, -42, 42...
// Examples of float literals: 0.0f, -4.2f, 4.2f...
// You have to handle these pseudo literals as well (you know, for science): -inff, +inff
// and nanf.
// Examples of double literals: 0.0, -4.2, 4.2...
// You have to handle these pseudo literals as well (you know, for fun): -inf, +inf and nan.
//
// Write a program to test that your class works as expected.
// You have to first detect the type of the literal passed as parameter, convert it from
// string to its actual type, then convert it explicitly to the three other data types. Lastly,
// display the results as shown below.
// If a conversion does not make any sense or overflows, display a message to inform
// the user that the type conversion is impossible. Include any header you need in order to
// handle numeric limits and special values.