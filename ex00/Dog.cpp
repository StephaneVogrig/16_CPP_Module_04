/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:41:40 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/04 15:33:19 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* constructor ---------------------------------------------------------------*/

Dog::Dog(void) : Animal("dog")
{
	std::cout << CYAN "Dog default constructor called : " RESET << *this << std::endl;
}

Dog::Dog(const Dog & toCopy) : Animal(toCopy)
{
	std::cout << CYAN "Dog copy constructor called " RESET << *this << std::endl;
}

/* destructor ----------------------------------------------------------------*/

Dog::~Dog(void)
{
	std::cout << BLUE "Dog default destructor called " RESET << *this << std::endl;
}

/* operator ------------------------------------------------------------------*/

Dog & Dog::operator = (const Dog & toAssign)
{
	std::cout << PURPLE "Dog copy assignment operator called " RESET << *this << std::endl;
	Animal::operator = (toAssign);
	return (*this);
}

/* public utilities ----------------------------------------------------------*/

void Dog::makeSound(void) const
{
	std::cout << GREY "The " RESET << _type << GREY " barks" RESET << std::endl;
}
