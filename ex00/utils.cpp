/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:31:06 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/04 00:45:51 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "utils.hpp"

void displaySubtest(std::string const & title)
{
	int width = 80;
	int padding = (width - 2 - title.length()) / 2;
	std::string left = std::string(padding, '-');
	std::string right = std::string(width - padding - 2 - title.length(), '-');
	std::cout << GREEN << std::endl;
	std::cout<< left << " "  << title << " " << right << std::endl;
	std::cout << RESET << std::endl;
}

void displaySection(std::string title)
{
	std::cout << std::endl;
	int width = 80;
	int padding = (width - 2 - title.length()) / 2;
	std::string star = std::string(width, '*');
	std::string blankLeft = std::string(padding, ' ');
	std::string blankRight = std::string(width - padding - 2 - title.length(), ' ');
	std::cout << GREEN << star << std::endl;
	std::cout << "*" << blankLeft << title << blankRight << "*" << std::endl;
	std::cout << star << RESET << std::endl;
}
