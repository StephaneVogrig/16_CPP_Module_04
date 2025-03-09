/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 23:31:23 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/09 23:06:59 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{}

Ice::Ice(const Ice & toCopy) : AMateria(toCopy)
{}

Ice::~Ice(void)
{}

Ice Ice::operator = (const Ice & toAssign)
{
	(void)toAssign;
	return (*this);
}

Ice * Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter & target)
{
	std::cout << YELLOW "* shoots an ice bolt at " << target.getName();
	std::cout << " *" RESET << std::endl;
}
