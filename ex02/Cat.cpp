/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:41:40 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/09 17:17:32 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* constructor ---------------------------------------------------------------*/

Cat::Cat(void) : AAnimal("cat"), _brain(new Brain())
{
	std::cout << CYAN "Cat default constructor called : " RESET << *this << std::endl;
}

Cat::Cat(const Cat & toCopy) : AAnimal(toCopy), _brain(new Brain(*toCopy._brain))
{
	std::cout << CYAN "Cat copy constructor called " RESET << *this << std::endl;
}

/* destructor ----------------------------------------------------------------*/

Cat::~Cat(void)
{
	std::cout << BLUE "Cat default destructor called " RESET << *this << std::endl;
	delete _brain;
}

/* operator ------------------------------------------------------------------*/

Cat & Cat::operator = (const Cat & toAssign)
{
	std::cout << PURPLE "Cat assignment operator called " RESET << *this << std::endl;
	AAnimal::operator = (toAssign);
	*_brain = *toAssign._brain;
	return (*this);
}

/* public utilities ----------------------------------------------------------*/

void Cat::makeSound(void) const
{
	std::cout << GREY "The " RESET << _type << GREY " meows" RESET << std::endl;
}

void Cat::addIdea(const std::string & idea)
{
	_brain->addIdea(idea);
}

void Cat::display(void)
{
	std::cout << *this << std::endl;
	_brain->display();
}
