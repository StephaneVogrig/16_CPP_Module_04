/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:41:40 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/04 00:49:15 by svogrig          ###   ########.fr       */
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

/* test ----------------------------------------------------------------------*/

static void test_constructor(void)
{
	displaySubtest("default constructor");
	Dog Dog;
}

static void test_new(void)
{
	displaySubtest("new");
	Dog * heap = new Dog();
	delete heap;
}

static void test_array(void)
{
	displaySubtest("Array");

	Dog * arrayPtr[5];
	for (int i = 0; i < 5; ++i)
		arrayPtr[i] = new Dog();
	for (int i = 0; i < 5; ++i)
		arrayPtr[i]->makeSound();
	for (int i = 0; i < 5; ++i)
		delete arrayPtr[i];

	std::cout << std::endl;
	Dog array[5];
	for (int i = 0; i < 5; ++i)
		array[i].makeSound();
}

static void test_copy(void)
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

static void test_makeSound(void)
{
	displaySubtest("make sound");
	Dog Dog;
	Dog.makeSound();
}

static void test_virtual(void)
{
	displaySubtest("virtual");

	Animal * animalVirtual = new Dog();
	animalVirtual->makeSound();
	delete animalVirtual;

	std::cout << std::endl;
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

void Dog::test(void)
{
	displaySection("test Dog");

	test_constructor();
	test_new();
	test_array();
	test_copy();
	test_makeSound();
	test_virtual();
}
