/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 23:31:23 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/09 19:24:07 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	// std::cout << CYAN "Ice constructor is called" RESET << std::endl;	
}

Ice::Ice(const Ice & toCopy) : AMateria(toCopy)
{
	// std::cout << CYAN "Ice constructor is called" RESET << std::endl;	
}

Ice::~Ice(void)
{
	// std::cout << BLUE "Ice destructor is called" RESET << std::endl;	
}

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
