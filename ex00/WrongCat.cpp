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

WrongCat::WrongCat(void)
{
	std::cout << CYAN "WrongCat default constructor called : " RESET << *this << std::endl;
	_type = "wrongCat";
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

/* test ----------------------------------------------------------------------*/

void testWrongCat_constructor(void)
{
	displaySubtest("default constructor");
	WrongCat WrongCat;
}

void testWrongCat_new(void)
{
	displaySubtest("new");
	WrongCat * heap = new WrongCat();
	delete heap;
}

void testWrongCat_array(void)
{
	displaySubtest("Array");
	WrongCat trap[5];
}

void testWrongCat_copy(void)
{
	displaySubtest("copy constructor");

	std::cout << YELLOW "Create a WrongCat" RESET << std::endl;
	WrongCat * original = new WrongCat();

	std::cout << std::endl;
	std::cout << YELLOW "Create a WrongCat by copy" RESET << std::endl;
	WrongCat copy(*original);

	std::cout << std::endl;
	std::cout << YELLOW "Delete original" RESET << std::endl;
	delete original;

	std::cout << std::endl;
	std::cout << YELLOW "copy content : " RESET << copy << std::endl;

	std::cout << std::endl;
}

void testWrongCat_virtual(void)
{
	displaySubtest("virtual");
	WrongAnimal wrongAnimal;
	WrongCat wrongCat;

	std::cout << std::endl;
	std::cout << YELLOW "pointer" RESET << std::endl;
	WrongAnimal * wrongAnimalPtr = &wrongAnimal;
	WrongAnimal * wrongCatPtr = &wrongCat;

	std::cout << std::endl;
	wrongAnimalPtr->makeSound();
	wrongCatPtr->makeSound();

	std::cout << std::endl;
	std::cout << YELLOW "reference" RESET << std::endl;
	WrongAnimal & animalRef = wrongAnimal;
	WrongAnimal & wrongCatRef = wrongCat;

	std::cout << std::endl;
	animalRef.makeSound();
	wrongCatRef.makeSound();
}

void testWrongCat_makeSound(void)
{
	displaySubtest("make sound");
	WrongCat wrongCat;
	wrongCat.makeSound();
}

void testWrongCat(void)
{
	testWrongCat_constructor();
	testWrongCat_new();
	testWrongCat_array();
	testWrongCat_copy();
	testWrongCat_virtual();
	testWrongCat_makeSound();
}
