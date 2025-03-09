/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 23:48:31 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/09 23:05:31 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string & name) : _name(name)
{
	for (int i = 0; i < _inventorySize; ++i)
		_inventory[i] = NULL;
}

Character::Character(const Character & toCopy) : _name(toCopy._name)
{
	for (int i = 0; i < _inventorySize; ++i)
	{
		if (toCopy._inventory[i])
			_inventory[i] = toCopy._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character & Character::operator = (const Character & toAssign)
{
	if (this == &toAssign)
		return (*this);
		
	_name = toAssign._name;
	
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

Character::~Character(void)
{
	for (int i = 0; i < _inventorySize; ++i)
		delete _inventory[i];
}

std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria * m)
{
	if (m == NULL)
		return ;
	for (int i = 0; i < _inventorySize; ++i)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= _inventorySize)
		return ;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter & target)
{
	if (idx < 0 || idx >= _inventorySize)
		return ;
	if (_inventory[idx] != NULL)
		_inventory[idx]->use(target);
}
