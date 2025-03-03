/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:41:40 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/04 00:48:40 by svogrig          ###   ########.fr       */
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

/* test ----------------------------------------------------------------------*/

static void test_constructor(void)
{
	displaySubtest("default constructor");
	Cat Cat;
}

static void test_new(void)
{
	displaySubtest("new");
	Cat * heap = new Cat();
	delete heap;
}

static void test_array(void)
{
	displaySubtest("Array");

	Cat * arrayPtr[5];
	for (int i = 0; i < 5; ++i)
		arrayPtr[i] = new Cat();
	for (int i = 0; i < 5; ++i)
		arrayPtr[i]->makeSound();
	for (int i = 0; i < 5; ++i)
		delete arrayPtr[i];

	std::cout << std::endl;
	Cat array[5];
	for (int i = 0; i < 5; ++i)
		array[i].makeSound();
}

static void test_copy(void)
{
	displaySubtest("copy constructor");

	std::cout << YELLOW "Create a Cat" RESET << std::endl;
	Cat * original = new Cat();

	std::cout << std::endl;
	std::cout << YELLOW "Create a Cat by copy" RESET << std::endl;
	Cat copy(*original);

	std::cout << std::endl;
	std::cout << YELLOW "Delete original" RESET << std::endl;
	delete original;

	std::cout << std::endl;
	std::cout << YELLOW "copy content : " RESET << copy << std::endl;

	std::cout << std::endl;
}

static void test_makeSound(void)
{
	displaySubtest("make sound");
	Cat Cat;
	Cat.makeSound();
}

static void test_virtual(void)
{
	displaySubtest("virtual");

	Animal * animalVirtual = new Cat();
	animalVirtual->makeSound();
	delete animalVirtual;

	std::cout << std::endl;
	Animal animal;
	Cat cat;

	std::cout << std::endl;
	std::cout << YELLOW "pointer" RESET << std::endl;
	Animal * animalPtr = &animal;
	Animal * catPtr = &cat;

	std::cout << std::endl;
	animalPtr->makeSound();
	catPtr->makeSound();

	std::cout << std::endl;
	std::cout << YELLOW "reference" RESET << std::endl;
	Animal & animalRef = animal;
	Animal & catRef = cat;

	std::cout << std::endl;
	animalRef.makeSound();
	catRef.makeSound();
}

void Cat::test(void)
{
	displaySection("test Cat");

	test_constructor();
	test_new();
	test_array();
	test_copy();
	test_makeSound();
	test_virtual();
}
