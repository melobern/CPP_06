/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:37:21 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/24 21:43:10 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_INCLUDES_SERIALIZER_HPP_
#define EX01_INCLUDES_SERIALIZER_HPP_
# include <stdint.h>
# include "../includes/Data.hpp"

class Serializer {
 public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);
 private:
  Serializer(void);
  Serializer(const Serializer &src);
  Serializer &operator=(const Serializer &src);
  ~Serializer(void);
};

#endif  //  EX01_INCLUDES_SERIALIZER_HPP_
