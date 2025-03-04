/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:44:07 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/04 18:32:30 by svogrig          ###   ########.fr       */
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

int main(void)
{
	test42();
	test42Wrong();

	test_Animal<Animal, Cat>("test Animal");
	test_AnimalType<Animal, Dog>("test Dog");
	test_AnimalType<Animal, Cat>("test Cat");

	test_Animal<WrongAnimal, WrongCat>("test WrongAnimal");
	test_AnimalType<WrongAnimal, WrongCat>("test WrongCat");

	return (EXIT_SUCCESS);
}
