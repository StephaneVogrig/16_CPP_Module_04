/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:00:18 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/09 19:07:54 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	// std::cout << CYAN "MateriaSource constructor is called" RESET << std::endl;
	for (int i = 0; i < _inventorySize; ++i)
		_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource & toCopy)
{
	// std::cout << CYAN "MateriaSource constructor by copy is called" RESET << std::endl;
	for (int i = 0; i < _inventorySize; ++i)
	{
		if (toCopy._inventory[i])
			_inventory[i] = toCopy._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

MateriaSource::~MateriaSource(void)
{
	// std::cout << BLUE "MateriaSource destructor is called" RESET << std::endl;
	for (int i = 0; i < _inventorySize; ++i)
		delete _inventory[i];
}

MateriaSource & MateriaSource::operator = (const MateriaSource & toAssign)
{
	
	if (this == &toAssign)
		return (*this);

	for (int i = 0; i < _inventorySize; ++i)
	{
		if (_inventory[i] != NULL)
			delete _inventory[i];
		if (toAssign._inventory[i])
			_inventory[i] = toAssign._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}

	return (*this);
}

void MateriaSource::learnMateria(AMateria * newMateria)
{
	if (newMateria == NULL)
		return ;
	for (int i = 0; i < _inventorySize; ++i)
	{
		if (_inventory[i] == NULL)
		{
			// std::cout	<< BLUE "Materia Source learn Materia " RESET
			// 			<< *newMateria << std::endl;
			_inventory[i] = newMateria;
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < _inventorySize; ++i)
	{
		if (_inventory[i]->getType() == type)
			return (_inventory[i]->clone());
	}
	return (0);
}
