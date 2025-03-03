/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:41:40 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/02 19:18:47 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* constructor ---------------------------------------------------------------*/

WrongCat::WrongCat(void) : WrongAnimal("wrongCat")
{
	std::cout << CYAN "WrongCat default constructor called : " RESET << *this << std::endl;
}

WrongCat::WrongCat(const WrongCat & toCopy) : WrongAnimal(toCopy)
{
	std::cout << CYAN "WrongCat copy constructor called " RESET << *this << std::endl;
}

/* destructor ----------------------------------------------------------------*/

WrongCat::~WrongCat(void)
{
	std::cout << BLUE "WrongCat default destructor called " RESET << *this << std::endl;
}

/* operator ------------------------------------------------------------------*/

WrongCat & WrongCat::operator = (const WrongCat & toAssign)
{
	std::cout << PURPLE "WrongCat copy assignment operator called " RESET << *this << std::endl;
	WrongAnimal::operator = (toAssign);
	return (*this);
}

/* public utilities ----------------------------------------------------------*/

void WrongCat::makeSound(void) const
{
	std::cout << GREY "The " RESET << _type << GREY " meows" RESET << std::endl;
}
