/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:22:30 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/09 22:43:32 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "utils.hpp"

void test_subject(void)
{
	displaySection("test from subject");

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout << std::endl;
}

void test_materia(void)
{
	displaySection("Materia");

	AMateria * array[10];
	for (int i = 0; i < 5; ++i)
	{
		array[i] = new Ice();
		array[i + 5] = new Cure();
	}

	AMateria * arrayClone[10];
	
	for (int i = 0; i < 10; ++i)
	{
		std::cout << i << " : cloning " << array[i]->getType() << std::endl;
		arrayClone[i] = array[i]->clone();
	}

	Character somebody("somebody");
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "arrayClone " << i << " : " << arrayClone[i]->getType() << std::endl;
		arrayClone[i]->use(somebody);
	}
	
	for (int i = 0; i < 10; ++i)
	{
		delete array[i];
		delete arrayClone[i];
	}
}

void test_character(void)
{
	displaySection("Character");

	Character marion("Marion");
	Character astranger("A stranger");
	std::cout << "character : " << marion.getName() << std::endl;
	
	marion.unequip(3);
	marion.unequip(-1);
	marion.unequip(10);
	marion.equip(new Ice());
	marion.equip(new Ice());
	marion.equip(new Ice());
	marion.use(0, astranger);
	marion.use(1, astranger);
	marion.use(2, astranger);
	AMateria * onTheFloor = new Cure();
	marion.equip(onTheFloor);
	marion.use(3, astranger);
	marion.unequip(3);
	marion.use(3, astranger);
	marion.unequip(3);
	delete onTheFloor;
}

int main(void)
{
	test_subject();
	test_materia();
	test_character();

	return (EXIT_SUCCESS);
}
