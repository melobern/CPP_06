/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:48:17 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/24 21:59:07 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/Data.hpp"

Data::Data(std::string name, int age, float grade, bool isAwake) :
    _name(name), _age(age), _grade(grade), _isAwake(isAwake) {
    return;
}

std::ostream &operator<<(std::ostream &out, const Data &data) {
  const std::string awaken = data._isAwake ? GREEN"true" : RED"false";

  out << YELLOW << "Name:\t\t" << RESET << data._name  << std::endl;
  out << BLUE << "Age:\t\t" << RESET << data._age << std::endl;
  out << MAGENTA << "Grade:\t\t" << RESET << data._grade << std::endl;
  out << CYAN << "Is awake:\t" << RESET << awaken << RESET << std::endl;
  return out;
}
