/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:44:07 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/04 17:28:49 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "utils.hpp"
#include "test_template.hpp"

void test42(void)
{
	displaySection("test 42");

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
}

void test42Wrong(void)
{
	displaySection("test 42 Wrong");

	const WrongAnimal* meta = new WrongAnimal();
	const Animal* j = new Dog();
	const WrongAnimal* i = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
}

void test_Animal(void)
{
	displaySection("test Animal");

	test_constructor<Animal>();
	test_array<Animal>();
	test_copy<Animal>();
	test_makeSound<Animal>();
	{
		displaySubtest("Assignation");
		Animal	animal;
		Cat		cat;

		std::cout << std::endl;
		std::cout << "animal: " << animal << std::endl;
		animal = cat;
		std::cout << "animal: " << animal << std::endl;

		std::cout << std::endl;
	}
}

void test_Dog(void)
{
	displaySection("test Dog");

	test_constructor<Dog>();
	test_array<Dog>();
	test_copy<Dog>();
	test_makeSound<Dog>();
	test_virtual<Animal, Dog>();
}

void test_Cat(void)
{
	displaySection("test Cat");

	test_constructor<Cat>();
	test_array<Cat>();
	test_copy<Cat>();
	test_makeSound<Cat>();
	test_virtual<Animal, Cat>();
}

void test_WrongAnimal(void)
{
	displaySection("test WrongAnimal");

	test_constructor<WrongAnimal>();
	test_array<WrongAnimal>();
	test_copy<WrongAnimal>();
	test_makeSound<WrongAnimal>();
	{
		displaySubtest("Assignation");
		WrongAnimal	animal;
		WrongCat	cat;

		std::cout << std::endl;
		std::cout << "animal: " << animal << std::endl;
		animal = cat;
		std::cout << "animal: " << animal << std::endl;

		std::cout << std::endl;
	}
}

void test_WrongCat(void)
{
	displaySection("test WrongCat");

	test_constructor<WrongCat>();
	test_array<WrongCat>();
	test_copy<WrongCat>();
	test_makeSound<WrongCat>();
	test_virtual<WrongAnimal, WrongCat>();
}

int main(void)
{
	test42();
	test42Wrong();
	test_Animal();
	test_Dog();
	test_Cat();
	test_WrongAnimal();
	test_WrongCat();

	return (EXIT_SUCCESS);
}
