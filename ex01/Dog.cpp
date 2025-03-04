/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:41:40 by svogrig           #+#    #+#             */
/*   Updated: 2025/03/04 19:16:23 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* constructor ---------------------------------------------------------------*/

Dog::Dog(void) : Animal("dog"), _brain(new Brain())
{
	std::cout << CYAN "Dog default constructor called : " RESET << *this << std::endl;
}

Dog::Dog(const Dog & toCopy) : Animal(toCopy), _brain(new Brain(*toCopy._brain))
{
	std::cout << CYAN "Dog copy constructor called " RESET << *this << std::endl;
}

/* destructor ----------------------------------------------------------------*/

Dog::~Dog(void)
{
	std::cout << BLUE "Dog default destructor called " RESET << *this << std::endl;
	delete _brain;
}

/* operator ------------------------------------------------------------------*/

Dog & Dog::operator = (const Dog & toAssign)
{
	std::cout << PURPLE "Dog assignment operator called " RESET << *this << std::endl;
	Animal::operator = (toAssign);
	*_brain = *toAssign._brain;
	return (*this);
}

/* public utilities ----------------------------------------------------------*/

void Dog::makeSound(void) const
{
	std::cout << GREY "The " RESET << _type << GREY " barks" RESET << std::endl;
}

void Dog::addIdea(const std::string & idea)
{
	_brain->addIdea(idea);
}

void Dog::display(void)
{
	std::cout << *this << std::endl;
	_brain->display();
}
