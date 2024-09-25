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

#include "../includes/Data.hpp"
#include "../includes/Serializer.hpp"
#include "../includes/Colors.hpp"

int main(void) {
    Data Amanda("Amanda", 23, 16.50f, true);
    Data Sleepy("Sleepy", 120, 8.50f, false);
    uintptr_t raw = Serializer::serialize(&Amanda);
    Data *ptr = Serializer::deserialize(raw);
    uintptr_t raw2 = Serializer::serialize(&Sleepy);
    Data *ptr2 = Serializer::deserialize(raw2);

    std::cout << *ptr;
    std::cout << "ptr and &Amanda are ";
    std::cout << (ptr == &Amanda ? GREEN "equal" : RED "different");
    std::cout << RESET << std::endl;
    std::cout << CYAN << "-----------------------" << RESET <<std::endl;

    std::cout << *ptr2;
    std::cout << "ptr2 and &Sleepy are ";
    std::cout << (ptr2 == &Sleepy ? GREEN "equal" : RED "different");
    std::cout << RESET << std::endl;
    std::cout << CYAN << "-----------------------" << RESET <<std::endl;
    std::cout << "Oh oh ! Dwarf Boss is coming !" << std::endl;
    std::cout << "\"Heigh-ho Sleepy, go back to work ! ";
    std::cout << "The diamonds won't dig themself up !\"";
    std::cout << std::endl;
    std::cout << "Sleepy has successfuly been waken up !" << std::endl;
    std::cout << CYAN << "-----------------------" << RESET <<std::endl;
    Sleepy._isAwake = true;
    std::cout << *ptr2;
    std::cout << CYAN << "-----------------------" << RESET <<std::endl;

    return (0);
}
