/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 21:57:34 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/09 23:05:54 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type)
{}

AMateria::AMateria(const AMateria & materia) : _type(materia._type)
{}

AMateria::~AMateria()
{}

AMateria & AMateria::operator = (const AMateria & toAssign)
{
	if (this == &toAssign)
		return (*this);
	_type = toAssign._type;
	return (*this);
}

std::ostream & operator << (std::ostream & os, const AMateria & materia)
{
	os << materia.getType();
	return (os);
}

std::string const & AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter & target)
{
	std::cout << YELLOW "AMateria  uses " << _type;
	std::cout << " on " << target.getName() << RESET << std::endl;
}
