/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:41:40 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/03 14:45:41 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* constructor ---------------------------------------------------------------*/

Animal::Animal(void) : _type("animal")
{
	std::cout << CYAN "Animal default constructor called : " RESET;
	std::cout << *this << CYAN " is created " RESET << std::endl;
}

Animal::Animal(const Animal & toCopy)
{
	std::cout << CYAN "Animal copy constructor called " RESET;
	std::cout << *this << CYAN " is created " RESET << std::endl;
	*this = toCopy;
}

/* destructor ----------------------------------------------------------------*/

Animal::~Animal(void)
{
	std::cout << BLUE "Animal default destructor called " RESET;
	std::cout << *this << BLUE " is destroy " RESET << std::endl;
}

/* operator ------------------------------------------------------------------*/

Animal & Animal::operator = (const Animal & newAnimal)
{
	std::cout << PURPLE "Animal copy assignment operator called " RESET << *this << std::endl;
	if (this == &newAnimal)
		return (*this);
	_type = newAnimal._type;
	return (*this);
}

std::ostream & operator << (std::ostream & os, const Animal & animal)
{
	os << YELLOW "animal type:" RESET << animal.getType();
	return (os);
}

std::string Animal::getType(void) const
{
	return (_type);
}

/* public utilities ----------------------------------------------------------*/

void Animal::makeSound(void) const
{
	std::cout << GREY "The " RESET << _type << GREY " make a strange sound... " RESET << std::endl;
}

/* test ----------------------------------------------------------------------*/

void testAnimal_constructor(void)
{
	displaySubtest("default constructor");
	Animal animal;
}

void testAnimal_new(void)
{
	displaySubtest("new");
	Animal * heap = new Animal();
	delete heap;
}

void testAnimal_array(void)
{
	displaySubtest("Array");
	Animal trap[5];
}

void testAnimal_copy(void)
{
	displaySubtest("copy constructor");

	std::cout << YELLOW "Create a Animal" RESET << std::endl;
	Animal * original = new Animal();

	std::cout << std::endl;
	std::cout << YELLOW "Create a Animal by copy" RESET << std::endl;
	Animal copy(*original);

	std::cout << std::endl;
	std::cout << YELLOW "Delete original" RESET << std::endl;
	delete original;

	std::cout << std::endl;
	std::cout << YELLOW "copy content : " RESET << copy << std::endl;

	std::cout << std::endl;
}

void testAnimal_makeSound(void)
{
	displaySubtest("make sound");
	Animal animal;
	animal.makeSound();
}

void testAnimal(void)
{
	testAnimal_constructor();
	testAnimal_new();
	testAnimal_array();
	testAnimal_copy();
	testAnimal_makeSound();
}
