/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:41:40 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/03 14:46:06 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* constructor ---------------------------------------------------------------*/

Dog::Dog(void)
{
	std::cout << CYAN "Dog default constructor called : " RESET;
	_type = "dog";
	std::cout << *this << CYAN " is created " RESET << std::endl;
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

/* test ----------------------------------------------------------------------*/

void testDog_constructor(void)
{
	displaySubtest("default constructor");
	Dog Dog;
}

void testDog_new(void)
{
	displaySubtest("new");
	Dog * heap = new Dog();
	delete heap;
}

void testDog_array(void)
{
	displaySubtest("Array");
	Dog trap[5];
}

void testDog_copy(void)
{
	displaySubtest("copy constructor");

	std::cout << YELLOW "Create a Dog" RESET << std::endl;
	Dog * original = new Dog();

	std::cout << std::endl;
	std::cout << YELLOW "Create a Dog by copy" RESET << std::endl;
	Dog copy(*original);

	std::cout << std::endl;
	std::cout << YELLOW "Delete original" RESET << std::endl;
	delete original;

	std::cout << std::endl;
	std::cout << YELLOW "copy content : " RESET << copy << std::endl;

	std::cout << std::endl;
}

void testDog_virtual(void)
{
	displaySubtest("virtual");
	Animal animal;
	Dog dog;

	std::cout << std::endl;
	std::cout << YELLOW "pointer" RESET << std::endl;
	Animal * animalPtr = &animal;
	Animal * dogPtr = &dog;

	std::cout << std::endl;
	animalPtr->makeSound();
	dogPtr->makeSound();

	std::cout << std::endl;
	std::cout << YELLOW "reference" RESET << std::endl;
	Animal & animalRef = animal;
	Animal & dogRef = dog;

	std::cout << std::endl;
	animalRef.makeSound();
	dogRef.makeSound();

}


void testDog_makeSound(void)
{
	displaySubtest("make sound");
	Dog Dog;
	Dog.makeSound();
}

void testDog(void)
{
	testDog_constructor();
	testDog_new();
	testDog_array();
	testDog_copy();
	testDog_virtual();
	testDog_makeSound();
}
