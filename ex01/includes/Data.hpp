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
# include <iostream>
# include <string>
# include <climits>
# include <limits>
# include <cerrno>
# include <cstdlib>
# include <iomanip>
# include "../includes/Colors.hpp"

class Data {
 public:

 private:
  Data(void);
  Data(const Data &src);
  Data &operator=(const Data &src);
  ~Data(void);
};

#endif  //  EX01_INCLUDES_DATA_HPP_
