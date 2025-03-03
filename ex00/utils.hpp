/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:29:35 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/02 23:18:47 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_HPP
# define DISPLAY_HPP

#include <iostream>
#include <string>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define PURPLE "\033[35m"
#define CYAN "\033[36m"
#define GREY "\033[37m"
#define RESET "\033[0m"

void displaySubtest(std::string const & title);
void displaySection(std::string title);

#endif