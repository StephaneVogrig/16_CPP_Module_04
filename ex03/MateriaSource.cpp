/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:00:18 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/09 23:07:46 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < _inventorySize; ++i)
		_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource & toCopy)
{
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
