/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:15:08 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/09 19:24:06 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	// std::cout << CYAN "Cure constructor is called" RESET << std::endl;	
}

Cure::Cure(const Cure & toCopy) : AMateria(toCopy)
{
	// std::cout << CYAN "Cure constructor is called" RESET << std::endl;	
}

Cure::~Cure(void)
{
	// std::cout << BLUE "Cure destructor is called" RESET << std::endl;	
}

Cure Cure::operator = (const Cure & toAssign)
{
	(void)toAssign;
	return (*this);
}

Cure * Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter & target)
{
	std::cout << YELLOW "* heals " << target.getName();
	std::cout << "'s wounds *" RESET << std::endl;
}
