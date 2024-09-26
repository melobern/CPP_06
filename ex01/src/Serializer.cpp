/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:44:31 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/24 21:49:52 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/Serializer.hpp"

Serializer::Serializer(void) {
    return;
}

Serializer::Serializer(const Serializer &src) {
    (void)src;
    return;
}

Serializer& Serializer::operator=(Serializer const &src)  {
    (void)src;
    return (*this);
}

Serializer::~Serializer() {
    return;
}

uintptr_t Serializer::serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data *>(raw));
}
