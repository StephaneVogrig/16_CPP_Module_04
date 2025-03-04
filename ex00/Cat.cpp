/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:41:40 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/04 15:36:31 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* constructor ---------------------------------------------------------------*/

Cat::Cat(void) : Animal("cat")
{
	std::cout << CYAN "Cat default constructor called : " RESET << *this << std::endl;
}

Cat::Cat(const Cat & toCopy) : Animal(toCopy)
{
	std::cout << CYAN "Cat copy constructor called " RESET << *this << std::endl;
}

/* destructor ----------------------------------------------------------------*/

Cat::~Cat(void)
{
	std::cout << BLUE "Cat default destructor called " RESET << *this << std::endl;
}

/* operator ------------------------------------------------------------------*/

Cat & Cat::operator = (const Cat & toAssign)
{
	std::cout << PURPLE "Cat copy assignment operator called " RESET << *this << std::endl;
	Animal::operator = (toAssign);
	return (*this);
}

/* public utilities ----------------------------------------------------------*/

void Cat::makeSound(void) const
{
	std::cout << GREY "The " RESET << _type << GREY " meows" RESET << std::endl;
}
