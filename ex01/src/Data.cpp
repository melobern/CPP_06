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
};

std::ostream &operator<<(std::ostream &out, const Data &data) {
  out << "Name: " << data._name << std::endl;
  out << "Age: " << data._age << std::endl;
  out << "Grade: " << data._grade << std::endl;
  out << "Is awake: " << data._isAwake << std::endl;
  return out;
}