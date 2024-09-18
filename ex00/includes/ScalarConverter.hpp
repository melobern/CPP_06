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

#define GREEN "\033[0;32m"
#define RED "\033[31m"
#define YELLOW "\033[0;33m"
#define BRIGHT_YELLOW "\033[1;93m"
#define RESET "\033[0m"

class ScalarConverter {
 private:
  ScalarConverter(void);
  ScalarConverter(const ScalarConverter &src);
  ScalarConverter &operator=(const ScalarConverter &src);
  ~ScalarConverter(void);

 public:
  static void convert(std::string const &str);
  int         convertToInt(std::string const &str);
  float       convertToFloat(std::string const &str);
  char        convertToChar(std::string const &str);
  double      convertToDouble(std::string const &str);
  std::string identifyType(std::string const &str);
};

std::ostream &operator<<(std::ostream &out, ScalarConverter const &src);

#endif  //  EX00_INCLUDES_SCALARCONVERTER_HPP_
