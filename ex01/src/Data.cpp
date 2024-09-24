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

Data::Data(void) {
    return;
}

Data::Data(const Data &src) {
    (void)src;
    return;
}

Data& Data::operator=(Data const &src)  {
    (void)src;
    return (*this);
}

Data::~Data() {
    return;
}

