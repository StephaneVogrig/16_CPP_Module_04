/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testBrain_template.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:33:24 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/04 19:38:46 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTBRAIN_TEMPLATE_HPP
# define TESTBRAIN_TEMPLATE_HPP

# include <iostream>
# include <sstream>

template <typename T>
void testBrain_constructor(void)
{
	displaySubtest("default constructor");

	std::cout << YELLOW "ont he heap" RESET << std::endl;
	T * heap = new T();
	heap->display();
	std::cout << YELLOW "add an idea" RESET << std::endl;
	heap->addIdea("I think therefore I am");
	heap->display();
	delete heap;
	std::cout << std::endl;

	std::cout << YELLOW "ont he stack" RESET << std::endl;
	T stack;
	stack.display();
	std::cout << YELLOW "add an idea" RESET << std::endl;
	stack.addIdea("I think therefore I am");
	stack.display();
}

template <typename T>
void testBrain_array(void)
{
	displaySubtest("Array");

	std::cout << YELLOW "array of ptr" RESET << std::endl;
	T * arrayPtr[5];
	for (int i = 0; i < 5; ++i)
	{
		arrayPtr[i] = new T();
		std::ostringstream oss;
		oss << "I think " << i;
		arrayPtr[i]->addIdea(oss.str());
	}
	for (int i = 0; i < 5; ++i)
		arrayPtr[i]->display();
	for (int i = 0; i < 5; ++i)
		delete arrayPtr[i];

	std::cout << std::endl;
	std::cout << YELLOW "array of object" RESET << std::endl;
	T array[5];
	for (int i = 0; i < 5; ++i)
	{
		std::ostringstream oss;
		oss << "I think " << i;
		array[i].addIdea(oss.str());
	}
	for (int i = 0; i < 5; ++i)
		array[i].display();
}

template <typename T>
void testBrain_constructorByCopy(void)
{
	displaySubtest("constructor by copy");

	std::cout << YELLOW "Create original" RESET << std::endl;
	T * original = new T();
	std::cout << YELLOW "add an idea" RESET << std::endl;
	original->addIdea("I think therefore I am");
	original->display();

	std::cout << std::endl;
	std::cout << YELLOW "Create by copy" RESET << std::endl;
	T copy(*original);

	std::cout << std::endl;
	std::cout << YELLOW "Delete original" RESET << std::endl;
	delete original;

	std::cout << std::endl;
	std::cout << YELLOW "Copy content : " RESET << std::endl;
	copy.display();

	std::cout << std::endl;
}
template <typename AnimalType>
void testBrain_assignation(void)
{
	displaySubtest("Assignation");
	AnimalType	original;
	original.display();
	AnimalType	toAssign;
	toAssign.addIdea("I think therefore I am");
	toAssign.display();

	std::cout << std::endl;
	original = toAssign;
	toAssign.display();

	std::cout << std::endl;
}

template <typename Animal, typename Type>
void testBrain_AnimalType(const std::string & testName)
{
	displaySection(testName);

	testBrain_constructor<Type>();
	test_array<Type>();
	testBrain_constructorByCopy<Type>();
	test_makeSound<Type>();
	test_virtual<Animal, Type>();
	testBrain_assignation<Type>();
}

#endif