/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:29:35 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/04 01:31:34 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_HPP
# define DISPLAY_HPP

#include <iostream>
#include <string>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define PURPLE "\033[35m"
#define CYAN "\033[36m"
#define GREY "\033[37m"
#define RESET "\033[0m"


void displaySection(const std::string & title);
void displaySubtest(const std::string & title);

template <typename T>
void test_constructor(void)
{
	displaySubtest("default constructor");

	T object;
}

template <typename T>
void test_new(void)
{
	displaySubtest("new");

	T * heap = new T();
	delete heap;
}

template <typename T>
void test_array(void)
{
	displaySubtest("Array");

	T * arrayPtr[5];
	for (int i = 0; i < 5; ++i)
		arrayPtr[i] = new T();
	for (int i = 0; i < 5; ++i)
		arrayPtr[i]->makeSound();
	for (int i = 0; i < 5; ++i)
		delete arrayPtr[i];

	std::cout << std::endl;
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

	T * animalPtr = new T();
	animalPtr->makeSound();
	delete animalPtr;

	std::cout << std::endl;
	T animal;
	animal.makeSound();
}

template <typename S, typename T>
void test_virtual(void)
{
	displaySubtest("virtual");

	S * animalVirtual = new T();
	animalVirtual->makeSound();
	delete animalVirtual;

	std::cout << std::endl;
	S animal;
	T dog;

	std::cout << std::endl;
	std::cout << YELLOW "pointer" RESET << std::endl;
	S * animalPtr = &animal;
	S * dogPtr = &dog;

	std::cout << std::endl;
	animalPtr->makeSound();
	dogPtr->makeSound();

	std::cout << std::endl;
	std::cout << YELLOW "reference" RESET << std::endl;
	S & animalRef = animal;
	S & dogRef = dog;

	std::cout << std::endl;
	animalRef.makeSound();
	dogRef.makeSound();
}

#endif
