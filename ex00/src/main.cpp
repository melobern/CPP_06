/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:29:57 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/12 11:28:13 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ScalarConverter.hpp"
#include "../includes/Colors.hpp"

static void check_args(int ac, char **av) {
  if (ac == 1) {
    std::cout << RED << "Error : should have one argument at least." << RESET;
    std::cout << "Correct usage : ./convert [number]";
    std::cout << std::endl;
    exit(1);
  }
}

int main(int ac, char **av) {
    check_args(ac, av);
    for (int i = 1; i < ac; i++) {
        ScalarConverter::convert(av[i]);
    }
    return (0);
}
