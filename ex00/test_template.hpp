/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_template.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:26:02 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/04 17:31:04 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_TEMPLATE_HPP
# define TEST_TEMPLATE_HPP

#include <iostream>
# include "utils.hpp"

template <typename T>
void test_constructor(void)
{
	displaySubtest("default constructor");

	std::cout << YELLOW "ont he heap" RESET << std::endl;
	T * heap = new T();
	delete heap;
	std::cout << std::endl;

	std::cout << YELLOW "ont he stack" RESET << std::endl;
	T stack;
}

template <typename T>
void test_array(void)
{
	displaySubtest("Array");

	std::cout << YELLOW "array of ptr" RESET << std::endl;
	T * arrayPtr[5];
	for (int i = 0; i < 5; ++i)
		arrayPtr[i] = new T();
	for (int i = 0; i < 5; ++i)
		arrayPtr[i]->makeSound();
	for (int i = 0; i < 5; ++i)
		delete arrayPtr[i];

	std::cout << std::endl;
	std::cout << YELLOW "array of object" RESET << std::endl;
	T array[5];
	for (int i = 0; i < 5; ++i)
		array[i].makeSound();
}

template <typename T>
void test_copy(void)
{
	displaySubtest("constructor by copy");

	std::cout << YELLOW "Create original" RESET << std::endl;
	T * original = new T();

	std::cout << std::endl;
	std::cout << YELLOW "Create copy" RESET << std::endl;
	T copy(*original);

	std::cout << std::endl;
	std::cout << YELLOW "Delete original" RESET << std::endl;
	delete original;

	std::cout << std::endl;
	std::cout << YELLOW "Copy content : " RESET << copy << std::endl;

	std::cout << std::endl;
}

template <typename T>
void test_makeSound(void)
{
	displaySubtest("make sound");

	T * instancePtr = new T();
	instancePtr->makeSound();
	delete instancePtr;

	std::cout << std::endl;
	T instance;
	instance.makeSound();
}

template <typename Animal, typename Child>
void test_virtual(void)
{
	displaySubtest("virtual");

	Animal * animalBase = new Child();
	animalBase->makeSound();
	delete animalBase;

	std::cout << std::endl;
	Animal animal;
	Child child;

	std::cout << std::endl;
	std::cout << YELLOW "pointer" RESET << std::endl;
	Animal * animalPtr = &animal;
	Animal * childPtr = &child;

	std::cout << std::endl;
	animalPtr->makeSound();
	childPtr->makeSound();

	std::cout << std::endl;
	std::cout << YELLOW "reference" RESET << std::endl;
	Animal & animalRef = animal;
	Animal & childRef = child;

	std::cout << std::endl;
	animalRef.makeSound();
	childRef.makeSound();
}

#endif
