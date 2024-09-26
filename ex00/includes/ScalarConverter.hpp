/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
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
# include "../includes/Colors.hpp"

# define NANF std::numeric_limits<float>::quiet_NaN()
# define INFF std::numeric_limits<float>::infinity()
# define NAN_DOUBLE std::numeric_limits<double>::quiet_NaN()
# define INF_DOUBLE std::numeric_limits<double>::infinity()
# define FLOAT_MAX std::numeric_limits<float>::max()
# define FLOAT_INT_MAX 2147483647.0f
# define FLOAT_INT_MIN -2147483648.0f

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
  void        checkIfIntIsPossible(Scalar &scalar);
};

std::ostream &operator<<(std::ostream &os, ScalarConverter::Scalar const &sc);

#endif  //  EX00_INCLUDES_SCALARCONVERTER_HPP_
