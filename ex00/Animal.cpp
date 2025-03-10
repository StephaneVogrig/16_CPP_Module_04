/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:41:40 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/07 18:03:07 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* constructor ---------------------------------------------------------------*/

Animal::Animal(const std::string & type) : _type(type)
{
	std::cout	<< CYAN "Animal default constructor called : " RESET
				<< *this << CYAN " is created " RESET << std::endl;
}

Animal::Animal(const Animal & toCopy)
{
	std::cout	<< CYAN "Animal copy constructor called " RESET
				<< *this << CYAN " is created " RESET << std::endl;
	*this = toCopy;
}

/* destructor ----------------------------------------------------------------*/

Animal::~Animal(void)
{
	std::cout	<< BLUE "Animal default destructor called " RESET
				<< *this << BLUE " is destroy " RESET << std::endl;
}

/* operator ------------------------------------------------------------------*/

Animal & Animal::operator = (const Animal & toAssign)
{
	std::cout	<< PURPLE "Animal assignment operator called " RESET
				<< *this << std::endl;
	if (this == &toAssign)
		return (*this);
	_type = toAssign._type;
	return (*this);
}

std::ostream & operator << (std::ostream & os, const Animal & animal)
{
	os << YELLOW "animal type:" RESET << animal.getType();
	return (os);
}

/* getter --------------------------------------------------------------------*/

std::string Animal::getType(void) const
{
	return (_type);
}

/* public utilities ----------------------------------------------------------*/

void Animal::makeSound(void) const
{
	std::cout	<< GREY "The " RESET << _type
				<< GREY " make a strange sound... " RESET << std::endl;
}
