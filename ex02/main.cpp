/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:44:07 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/09 17:17:01 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include "utils.hpp"
#include "test_template.hpp"
#include "testBrain_template.hpp"
#include <sstream>

void test42(void)
{
	displaySection("test 42");
	AAnimal * animals[10];

	for (int i = 0; i < 5; ++i)
	{
		animals[i] = new Dog();
		animals[i + 5] = new Cat();
	}

	for (int i = 0; i < 10; ++i)
	{
		animals[i]->makeSound();
	}

	for (int i = 0; i < 5; ++i)
	{
		delete animals[i];
		delete animals[i + 5];
	}

	std::cout << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	
	i->makeSound();
	j->makeSound();

	delete j;
	delete i;
}

void test42Wrong(void)
{
	displaySection("test 42 Wrong");
	const WrongAnimal* meta = new WrongAnimal();
	const AAnimal* j = new Dog();
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

void test_Brain(void)
{
	displaySection("test Brain");

	testBrain_constructor<Brain>();
	testBrain_array<Brain>();
	testBrain_constructorByCopy<Brain>();

	displaySubtest("add idea");
	Brain brain;
	for (int i = 0; i < 110; ++i)
	{
		std::ostringstream oss;
		oss << "I think " << i;
		brain.addIdea(oss.str());
	}
	brain.display();
}

int main(void)
{
	test42();
	test42Wrong();

	// test_Animal<Animal, Cat>("test Animal");
	testBrain_AnimalType<AAnimal, Dog>("test Dog");
	testBrain_AnimalType<AAnimal, Cat>("test Cat");

	test_Animal<WrongAnimal, WrongCat>("test WrongAnimal");
	test_AnimalType<WrongAnimal, WrongCat>("test WrongCat");

	test_Brain();

	return (EXIT_SUCCESS);
}
