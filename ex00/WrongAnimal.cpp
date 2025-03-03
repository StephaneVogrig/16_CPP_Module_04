/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:41:40 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/03 15:23:42 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* constructor ---------------------------------------------------------------*/

WrongAnimal::WrongAnimal(void) : _type("wrongAnimal")
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

std::string WrongAnimal::getType(void) const
{
	return (_type);
}

/* public utilities ----------------------------------------------------------*/

void WrongAnimal::makeSound(void) const
{
	std::cout << GREY "The " RESET << _type << GREY " make a strange sound... " RESET << std::endl;
}

/* test ----------------------------------------------------------------------*/

void testWrongAnimal_constructor(void)
{
	displaySubtest("default constructor");
	WrongAnimal wrongAnimal;
}

void testWrongAnimal_new(void)
{
	displaySubtest("new");
	WrongAnimal * heap = new WrongAnimal();
	delete heap;
}

void testWrongAnimal_array(void)
{
	displaySubtest("Array");
	WrongAnimal trap[5];
}

void testWrongAnimal_copy(void)
{
	displaySubtest("copy constructor");

	std::cout << YELLOW "Create a Animal" RESET << std::endl;
	WrongAnimal * original = new WrongAnimal();

	std::cout << std::endl;
	std::cout << YELLOW "Create a Animal by copy" RESET << std::endl;
	WrongAnimal copy(*original);

	std::cout << std::endl;
	std::cout << YELLOW "Delete original" RESET << std::endl;
	delete original;

	std::cout << std::endl;
	std::cout << YELLOW "copy content : " RESET << copy << std::endl;

	std::cout << std::endl;
}

void testWrongAnimal_makeSound(void)
{
	displaySubtest("make sound");
	WrongAnimal wrongAnimal;
	wrongAnimal.makeSound();
}

void testWrongAnimal(void)
{
	testWrongAnimal_constructor();
	testWrongAnimal_new();
	testWrongAnimal_array();
	testWrongAnimal_copy();
	testWrongAnimal_makeSound();
}
