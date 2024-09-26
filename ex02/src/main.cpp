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

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <exception>
#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include "../includes/Colors.hpp"

static Base *generate(void) {
    srand(time(NULL));
    int random = rand() % 3;
    if (random == 0) {
        std::cout << CYAN << "Generating A..." << RESET << std::endl;
        return (new A);
    } else if (random == 1) {
        std::cout << CYAN << "Generating B..." << RESET << std::endl;
        return (new B);
    } else {
        std::cout << CYAN << "Generating C..." << RESET << std::endl;
        return (new C);
    }
}

static void identify(Base *p) {
    if (p != NULL) {
        if (dynamic_cast<A *>(p) != NULL) {
            std::cout << YELLOW << "The pointer is A" << RESET << std::endl;
        } else if (dynamic_cast<B *>(p) != NULL) {
            std::cout << YELLOW << "The pointer is B" << RESET << std::endl;
        } else if (dynamic_cast<C *>(p) != NULL) {
            std::cout << YELLOW << "The pointer is C" << RESET << std::endl;
        }
    } else {
        std::cout << RED "Error : the pointer is NULL." RESET << std::endl;
    }
}

static void identify(Base &p) {
    try {
        A a = dynamic_cast<A &>(p);
        std::cout << GREEN << "The reference is A" << RESET << std::endl;
    } catch (const std::exception &e) {
        try {
            B b = dynamic_cast<B &>(p);
            std::cout << GREEN << "The reference is B" << RESET << std::endl;
        } catch (const std::exception &e) {
            try {
                C c = dynamic_cast<C &>(p);
                std::cout << GREEN "The reference is C" RESET << std::endl;
            } catch (const std::exception &e) {
                std::cout << RED << "Unknown type" << RESET << std::endl;
            }
        }
    }
}

int main(void) {
    std::cout << MAGENTA << "------------Delulu Base------------" << std::endl;
    Base *delulu = NULL;
    identify(delulu);
    identify(*delulu);

    std::cout << MAGENTA << "------------Normal Base------------" << std::endl;
    Base *base = generate();
    identify(base);
    identify(*base);

    delete base;
    return (0);
}
