/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:41:40 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/04 16:01:46 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* constructor ---------------------------------------------------------------*/

WrongAnimal::WrongAnimal(const std::string & type) : _type(type)
{
	std::cout << CYAN "WrongAnimal default constructor called : " RESET;
	std::cout << *this << CYAN " is created " RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal & toCopy)
{
	std::cout << CYAN "WrongAnimal copy constructor called " RESET;
	std::cout << *this << CYAN " is created " RESET << std::endl;
	*this = toCopy;
}

/* destructor ----------------------------------------------------------------*/

WrongAnimal::~WrongAnimal(void)
{
	std::cout << BLUE "WrongAnimal default destructor called " RESET;
	std::cout << *this << BLUE " is destroy " RESET << std::endl;
}

/* operator ------------------------------------------------------------------*/

WrongAnimal & WrongAnimal::operator = (const WrongAnimal & toAssign)
{
	std::cout << PURPLE "WrongAnimal copy assignment operator called " RESET << *this << std::endl;
	if (this == &toAssign)
		return (*this);
	_type = toAssign._type;
	return (*this);
}

std::ostream & operator << (std::ostream & os, const WrongAnimal & wrongAnimal)
{
	os << YELLOW "animal type:" RESET << wrongAnimal.getType();
	return (os);
}

/* getter --------------------------------------------------------------------*/

std::string WrongAnimal::getType(void) const
{
	return (_type);
}

/* public utilities ----------------------------------------------------------*/

void WrongAnimal::makeSound(void) const
{
	std::cout << GREY "The " RESET << _type << GREY " make a strange sound... " RESET << std::endl;
}
