/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:37:21 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/24 21:59:26 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_INCLUDES_DATA_HPP_
#define EX01_INCLUDES_DATA_HPP_
# include <string>
# include <iostream>
# include "../includes/Colors.hpp"

struct Data {
  std::string _name;
  int         _age;
  float       _grade;
  bool        _isAwake;

  Data(std::string name, int age, float grade, bool isAwake);
};

std::ostream &operator<<(std::ostream &out, const Data &data);

#endif  //  EX01_INCLUDES_DATA_HPP_
